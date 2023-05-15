/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <math.h>   // pow()
#include <algorithm> // fmax()
#include "Phong.h"
#include "Vector3D.h"
#include "Normal.h"
#include "ShadeRec.h"
#include "World.h"

Phong::Phong()
        : Material(){
}

Phong::Phong(const RGBColor& c, const float kd, const float ks, const float sp_e, const float lci)
        : Material(c), Kd(kd), Ks(ks), specular_e(sp_e), light_color_inf(lci){
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

        diffuse += Kd * std::fmax(L*N,0) * (light_color_inf * Lcolor +  (1 - light_color_inf) * sr.material_ptr->color);
        specular += Ks * pow(std::fmax(R*V,0), specular_e) * (light_color_inf * Lcolor +  (1 - light_color_inf) * sr.material_ptr->color);
    }
    const RGBColor ambient = Ka * (light_color_inf *  sr.world_ptr->m_ambient->get_color(sr) +  (1 - light_color_inf) * sr.material_ptr->color);

    return (ambient + diffuse + specular);
}
