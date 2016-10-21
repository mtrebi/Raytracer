/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Sphere.h
 * Author: maru
 *
 * Created on October 19, 2016, 1:36 PM
 */

#ifndef SPHERE_H
#define SPHERE_H

#include "GeometryObject.h"
#include "Point3D.h"
#include "Vector3D.h"

class Sphere : public GeometryObject {
    public:
        Sphere();
        Sphere(const Point3D& center, const float radius);
        ~Sphere();
        
        virtual bool hit (const Ray &ray, double& tmin, ShadeRec& sr) const override;
    private:
        Point3D m_center;
        float m_radius;
};


#endif /* SPHERE_H */

