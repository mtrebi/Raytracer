/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Sphere.cpp
 * Author: maru
 * 
 * Created on October 12, 2016, 4:14 PM
 */

#include "Objects/Shapes/Sphere.h"

Sphere::Sphere() {
}

Sphere::Sphere(const Vec3& location, const RGBColour& colour, const float radius)
    : Shape(location, colour) {
    m_radius = radius;
}

Sphere::~Sphere() {
}


bool Sphere::intersect(IntersectionInfo &outInfo, const Ray& ray) const {
    float a = Vec3::dot(ray.getDirection(), ray.getDirection());
    float b = Vec3::dot(ray.getDirection(),  (2.0f * ( ray.getOrigin() - m_location)));
    float c = Vec3::dot(m_location, m_location) + Vec3::dot(ray.getOrigin(), ray.getOrigin()) -2.0f*Vec3::dot(ray.getOrigin(),m_location) - m_radius * m_radius;
    float D = b*b + (-4.0f)*a*c;
    
    // If ray can not intersect then stop
    if (D < 0){
        return false;
    }
    
    D=sqrtf(D);

    // Ray can intersect the sphere, solve the closer hitpoint
    float t = (-0.5f)*(b+D)/a;
    if (t > 0.0f){
        outInfo.hit = true;
        outInfo.hitDistance = sqrtf(a)*t;
        outInfo.hitPoint = ray.getOrigin() + t*ray.getDirection();
        Vec3 normal = outInfo.hitPoint - m_location; normal.normalize();
        outInfo.hitNormal = normal;
        outInfo.hitShape = const_cast<Sphere* const>(this);
    }
    else{
        return false;
    }
    return true;
}


std::istream& operator >> (std::istream& is, Sphere& sphere){
    std::string SPHERE;
    is >> SPHERE >> sphere.m_center >> sphere.m_colour >> sphere.m_radius;
}
std::ostream& operator << (std::ostream& os, Sphere& sphere){
    os << "SPHERE" << sphere.m_center << sphere.m_colour << sphere.m_radius;
}