/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <math.h>
#include "Refract.h"
#include "Constants.h"
#include "Ray.h"
#include "ShadeRec.h"
#include "World.h"
#include "Tracer.h"

Refract::Refract()
        : Phong(){

}

Refract::Refract(const RGBColor& color, const float ref_coef, const float kd, const float ks, const float sp_e, const float lci)
        : Phong(Colors::white, kd, ks, sp_e, lci), refraction_coef(ref_coef){
}

const Vector3D Refract::refracted_vector(const Vector3D& N, const Vector3D& V, const float n1_n2) const{
    const float c1 = -(N * V);
    const float c2 = sqrt( 1 - pow(n1_n2,2) * (1 - pow(c1,2)));
    const Vector3D refracted = (n1_n2 * V) + (n1_n2 * c1 - c2) * N;

    return refracted;
}

# include "Flat.h"
const RGBColor Refract::shade(const ShadeRec& sr) const {
    // Refacted ray inside
    const Point3D inside_ray_origin = sr.hit_point + .0001 * sr.ray.d;
    const Vector3D inside_ray_dir = refracted_vector(sr.hit_normal,sr.ray.d, 1/refraction_coef);
    const Ray inside_ray = Ray(inside_ray_origin, inside_ray_dir);
    const ShadeRec sr_inside = sr.world_ptr->hit_bare_bones_obj(inside_ray);

    // Refracted ray outside
    const Point3D out_ray_origin = sr_inside.hit_point ;
    const Vector3D out_ray_dir = refracted_vector(-sr_inside.hit_normal,sr_inside.ray.d, refraction_coef);
    const Ray out_ray = Ray(out_ray_origin, out_ray_dir);
    const ShadeRec sr_out = sr.world_ptr->hit_bare_bones_obj(out_ray, std::vector<GeometryObject*>{sr.obj_ptr});

    const RGBColor base_reflected_color = sr.world_ptr->m_tracer_ptr->trace_ray(out_ray, std::vector<GeometryObject*>{sr.obj_ptr});


    RGBColor final_color;

    if (sr_out.hit){
        /* Apply phong shade
        ShadeRec sr_aux;
        sr_aux.hit = sr.hit;
        sr_aux.hit_normal = sr.hit_normal;
        sr_aux.hit_point = sr.hit_point;
        sr_aux.ray = sr.ray;
        sr_aux.material_ptr = new Flat(base_reflected_color);
        sr_aux.world_ptr = sr.world_ptr;
        final_color = Phong::shade(sr_aux);
        */
        final_color = base_reflected_color;
    }else {
        final_color = sr.world_ptr->BACKGROUND_COLOR;
    }
    return final_color;

};
