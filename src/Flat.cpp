/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
# include "Flat.h"

Flat::Flat()
        : Material(){
    
}

Flat::Flat(const RGBColor& c)
        : Material(c){
    
}

const RGBColor Flat::shade(const ShadeRec& sr) const {
    return sr.world_ptr->m_ambient->get_color(sr);
}