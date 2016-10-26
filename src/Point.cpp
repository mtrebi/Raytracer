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

const float Point::get_distance(const Point3D& point) const{
    return m_position.distance(point);
}


const Vector3D Point::get_direction(const Point3D& surface_point) const {
     return (m_position - surface_point).hat();
}

const RGBColor Point::get_color(const ShadeRec& sr) const {
    const float distance_attenuator = 100/m_position.distance(sr.hit_point);
    return m_intensity * m_color * distance_attenuator;
}
        