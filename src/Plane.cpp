/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "Plane.h"

Plane::Plane()
        : GeometryObject() {
}

Plane::Plane(const Point3D& p, const Normal& n){
    m_point = p;
    m_normal = n;
}

Plane::~Plane() {
}

bool Plane::hit (const Ray &ray, double& tmin, ShadeRec& sr) const {
    const double t = (m_point - ray.o) * m_normal / (ray.d * m_normal);
    if (t > kEpsilon){
        tmin = t;
        //sr.hit =  true;
        sr.hit_normal = m_normal;
        sr.local_hit_point = ray.o + t * ray.d;
       // sr.color = m_color;
        sr.ray = ray;
        return true;
    }else {
        return false;
    }
};
