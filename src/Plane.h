/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Plane.h
 * Author: maru
 *
 * Created on October 19, 2016, 1:35 PM
 */

#ifndef PLANE_H
#define PLANE_H

#include "GeometryObject.h"
#include "Point3D.h"
#include "Vector3D.h"

class Plane : public GeometryObject {
public:
    Plane();
    Plane(const Point3D& p, const Normal& n);
    ~Plane();

    bool hit (const Ray &ray, double& tmin, ShadeRec& sr) const;
private:
    Point3D m_point;
    Normal m_normal;
        
};

#endif /* PLANE_H */

