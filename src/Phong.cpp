/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "Phong.h"
#include <math.h>   // pow()
#include <algorithm> // fmax()

Phong::Phong()
        : Material(){
    
}

Phong::Phong(const RGBColor& c)
        : Material(c){
    
}


const RGBColor Phong::shade(const ShadeRec& sr) const {
    const Vector3D V = -sr.ray.d;
    const Normal N = sr.hit_normal;
    
    RGBColor diffuse = RGBColor(0);
    RGBColor specular = RGBColor(0);

    for (const auto& light: sr.world_ptr->m_lights){
        const RGBColor Lcolor = light->get_color(sr);
        const Vector3D L = light->get_direction(sr.hit_point);
        const Vector3D R = 2*(L * N) * N - L;        

        diffuse += Kd * std::fmax(L*N,0) * (Lcolor + sr.material_ptr->color);
        specular += Ks * pow(std::fmax(R*V,0), specular_shininess) * (Lcolor + sr.material_ptr->color);
    }
    const RGBColor ambient = Ka * sr.world_ptr->m_ambient->get_color(sr);
    
    return (ambient + diffuse + specular);
}