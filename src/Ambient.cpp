/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

# include "Ambient.h"

Ambient::Ambient()
    : Light() {

}
Ambient::Ambient(const float intensity, const RGBColor& color)
    : Light(intensity, color){

}

Ambient::~Ambient(){

}

const float Ambient::get_distance(const Point3D& point) const{
    return .0;
}


const Vector3D Ambient::get_direction(const Point3D& surface_point) const {
    return Vector3D(0,0,0);
}

const RGBColor Ambient::get_color(const ShadeRec& sr) const {
    return m_intensity * m_color;
}
