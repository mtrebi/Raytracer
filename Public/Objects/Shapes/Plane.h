/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Box.h
 * Author: maru
 *
 * Created on October 10, 2016, 3:05 PM
 */

#ifndef PLANE_H
#define PLANE_H

#include "Objects/Shapes/Shape.h"
#include <iostream>

class Plane : public Shape {
public:
    // Constructors
    Plane(const Vec3& location, const RGBColour& colour, const Vec3& normal, const float size);
    Plane();
    
    // Functions
    bool intersect(IntersectionInfo &outInfo, const Ray& ray) const;
 
    // Destructors
    virtual ~Plane();
private:
    Vec3 m_a,m_b,m_c,m_d;
    float m_size;
    Vec3 m_normal;
};

#endif /* PLANE_H */

