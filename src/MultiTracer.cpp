/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "MultiTracer.h"
#include "World.h"
#include "Material.h"
#include <math.h>   // pow()
#include <algorithm> // fmax()
MultiTracer::MultiTracer()
    : Tracer() {
    
}

MultiTracer::MultiTracer(World * world_ptr)
    : Tracer(world_ptr) {
    
}

const RGBColor MultiTracer::trace_ray(const Ray& ray, const int depth) const{
    ShadeRec sr = m_world_ptr->hit_bare_bones_obj(ray);
    if (sr.hit) {
        //return sr.color;
        return phong_illumination(sr);
        //return phong;
    }
    else {
        return m_world_ptr->BACKGROUND_COLOR;
    }
}

const RGBColor MultiTracer::phong_illumination(const ShadeRec& sr) const {
    const Vector3D V = -sr.ray.d;
    const Normal N = sr.hit_normal;
    
    RGBColor specular = RGBColor(.0);
    RGBColor diffuse = RGBColor(.0);
    for (const auto& light: m_world_ptr->m_lights){
        const RGBColor Lcolor = light->get_color(sr);
        const Vector3D L = light->get_direction(sr.hit_point);
        const Vector3D R = 2*(L * N) * N - L;        

        diffuse += Kd * std::fmax(L*N,0) * Lcolor;
        //TODO move indexs to material
        specular += Ks * pow(std::fmax(R*V,0), specular_shininess) * Lcolor;
    }
    const RGBColor ambient = Ka * m_world_ptr->m_ambient->get_color(sr);
    
    return (ambient + diffuse + specular) * sr.material_ptr->color;
}

