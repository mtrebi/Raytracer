/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Sphere.h
 * Author: maru
 *
 * Created on October 12, 2016, 4:14 PM
 */

#ifndef SPHERE_H
#define SPHERE_H

#include <cstdint>
#include <iostream>
#include "Shape.h"

class Sphere : public Shape{
public:
    Sphere();
    Sphere(const Vec3& location, const RGBColour& Color, const uint16_t radius);

    const uint16_t getRadius() const { return m_radius; }
    const Vec3 getCenter() const { return m_center; }

    virtual bool intersect(IntersectionInfo &outInfo, const Ray& ray) const override;

    
    // Operators
    friend std::istream& operator >> (std::istream& is, Sphere& sphere);
    friend std::ostream& operator << (std::ostream& os, Sphere& sphere);
    

    virtual ~Sphere();
private:
    uint16_t m_radius;
    Vec3 m_center;
};

#endif /* SPHERE_H */

