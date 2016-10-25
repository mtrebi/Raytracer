/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   MultiTracer.h
 * Author: maru
 *
 * Created on October 20, 2016, 10:12 AM
 */

#ifndef MULTITRACER_H
#define MULTITRACER_H

#include "Tracer.h"

class MultiTracer : public Tracer {
public:
    MultiTracer();
    MultiTracer(World* world_ptr);

    virtual const RGBColor trace_ray(const Ray& ray, const int depth = 0) const override;

    const float Ka = 0.2;
    const float Kd = 0.4;
    const float Ks = 0.4;
    const int specular_shininess = 20;
private:
    const RGBColor phong_illumination(const ShadeRec& sr) const;
};


#endif /* MULTITRACER_H */

