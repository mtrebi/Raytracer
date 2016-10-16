/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Shape.h
 * Author: maru
 *
 * Created on October 10, 2016, 5:19 PM
 */

#ifndef SHAPE_H
#define SHAPE_H

#include <iostream>
#include "Utils/Ray.h"
#include "Objects/Object.h"

class Shape;

struct IntersectionInfo {
    bool hit;
    float hitDistance;
    Vec3 hitPoint;
    Vec3 hitNormal;
    Shape* hitShape;
};

class Shape : public Object {
public:
    // Constructors
    Shape(const Vec3& location, const RGBColour& colour);
    Shape();
    
    // Getters
    const RGBColour getColour() const { return m_colour; }
    virtual bool intersect(IntersectionInfo &outInfo, const Ray& ray) const = 0;
    // Setters
    void setColour(const RGBColour& colour) { m_colour = colour; }
    
    virtual ~Shape();
protected:
    // Aspect
    RGBColour m_colour;
    //TODO reflection/refraction...
};

#endif /* SHAPE_H */

