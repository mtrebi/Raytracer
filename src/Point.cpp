/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */


# include "Point.h"

Point::Point()
    : Light() {
    
}
Point::Point(const Point3D& position, const float intensity, const RGBColor& color)
    : Light(intensity, color), m_position(position){
    
}
    
Point::~Point(){
    
}

const Vector3D Point::get_direction(const Point3D& surface_point) const {
    return (surface_point - m_position).hat();
}

const RGBColor Point::get_color(const ShadeRec& sr) const {
    const float distance_attenuator = 1/m_position.d_squared(sr.hit_point);
    return m_intensity * m_color * distance_attenuator;
}
        