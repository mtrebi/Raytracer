/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "Sphere.h"
#include <math.h>

Sphere::Sphere()
        : GeometryObject(), m_center(Point3D()), m_radius(0) {
}

Sphere::Sphere(const Point3D& center, const float radius)
        : GeometryObject(), m_center(center), m_radius(radius) {
}

Sphere::~Sphere(){
}

bool Sphere::hit (const Ray &ray, double& tmin, ShadeRec& sr) {
    const double a = ray.d * ray.d;
    const double b = 2 * (ray.o - m_center) * ray.d;
    const double c = (ray.o - m_center) * (ray.o - m_center) - (m_radius * m_radius);
    const double denom = 2 * a;
    const double disc = b * b - 4 * a * c;

    if (disc < 0) {
        return false;
    }

    const double sq_disc = sqrt(disc);

    const double t_minus = (-b - sq_disc) / denom;

    if (t_minus > kEpsilon){
        tmin = t_minus;
        sr.hit = true;
        sr.hit_point = ray.o + ray.d * t_minus;
        sr.hit_normal = ((ray.o - m_center) + (t_minus * ray.d)) / m_radius;
        sr.material_ptr = m_material;
        sr.ray = ray;
        sr.obj_ptr = this;
        return true;
    }

    const double t_plus = (-b + sq_disc) / denom;

    if (t_plus > kEpsilon){
        tmin = t_plus;
        sr.hit = true;
        sr.hit_point = ray.o + ray.d * t_plus;
        sr.hit_normal = ((ray.o - m_center) + (t_plus * ray.d)) / m_radius;
        sr.material_ptr = m_material;
        sr.ray = ray;
        sr.obj_ptr = this;
        return true;
    }
    return false;
}
