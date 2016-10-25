/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Light.h
 * Author: maru
 *
 * Created on October 25, 2016, 9:43 AM
 */

#ifndef LIGHT_H
#define LIGHT_H

#include "Point3D.h"
#include "Vector3D.h"
#include "RGBColor.h"

class Light {
public:
    Light();
    Light(const float intensity, const RGBColor& color);
    
    virtual ~Light();
    virtual const Vector3D get_direction(const Point3D& surface_point) const = 0;
    virtual const RGBColor get_color(const ShadeRec& sr) const = 0;
protected:
    float m_intensity;
    RGBColor m_color;
};

#endif /* LIGHT_H */

