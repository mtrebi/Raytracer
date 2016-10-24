/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Tracer.h
 * Author: maru
 *
 * Created on October 20, 2016, 11:04 AM
 */

#ifndef TRACER_H
#define TRACER_H

#include "World.h"
#include "RGBColor.h"
#include "Ray.h"
class Tracer {
public:
    Tracer();
    Tracer(World * world_ptr);

    virtual const RGBColor trace_ray(const Ray& ray, const int depth = 0) const = 0;

protected:
    World* m_world_ptr;
};


#endif /* TRACER_H */

