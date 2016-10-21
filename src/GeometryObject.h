/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   GeometryObject.h
 * Author: maru
 *
 * Created on October 19, 2016, 1:29 PM
 */

#ifndef GEOMETRYOBJECT_H
#define GEOMETRYOBJECT_H

#include "ShadeRec.h"
#include "RGBColor.h"
#include <limits>

class GeometryObject {
public:
    GeometryObject();
    ~GeometryObject();
            
    virtual bool hit (const Ray &ray, double& tmin, ShadeRec& sr) const = 0;
public:
    //TODO delete
    void setColor(const RGBColor& color) { m_color = color; }
protected:
    const double kEpsilon = std::numeric_limits<double>::min();
    RGBColor m_color;
};


#endif /* GEOMETRYOBJECT_H */

