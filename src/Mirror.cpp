/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <vector>
#include "Mirror.h"
#include "Constants.h"
#include "Flat.h"
#include "Vector3D.h"
#include "GeometryObject.h"
#include "World.h"
#include "Tracer.h"

Mirror::Mirror(const float kd, const float ks, const float sp_e, const float lci)
        : Phong(Colors::white, kd, ks, sp_e, lci){

}

const RGBColor Mirror::shade(const ShadeRec& sr) const {
    const Vector3D V = -sr.ray.d;
    const Normal N = sr.hit_normal;
    const Vector3D R = 2*(V * N) * N - V;

    std::vector<GeometryObject*> ignore_self = std::vector<GeometryObject*>();
    ignore_self.push_back(sr.obj_ptr);
    const Ray reflected_ray = Ray(sr.hit_point, R);

    const RGBColor base_reflected_color = sr.world_ptr->m_tracer_ptr->trace_ray(reflected_ray, ignore_self);
    RGBColor final_color;
    if (sr.hit){
        ShadeRec sr_aux;
        sr_aux.hit = sr.hit;
        sr_aux.hit_normal = sr.hit_normal;
        sr_aux.hit_point = sr.hit_point;
        sr_aux.ray = sr.ray;
        sr_aux.material_ptr = new Flat(base_reflected_color);
        sr_aux.world_ptr = sr.world_ptr;
        //final_color = Phong::shade(sr_aux);
        final_color = base_reflected_color;
    }else {
        final_color = sr.world_ptr->BACKGROUND_COLOR;
    }
    return final_color;
};
