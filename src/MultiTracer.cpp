/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "MultiTracer.h"
#include "World.h"

MultiTracer::MultiTracer()
    : Tracer() {
    
}

MultiTracer::MultiTracer(World * world_ptr)
    : Tracer(world_ptr) {
    
}

const RGBColor MultiTracer::trace_ray(const Ray& ray, const int depth) const{
    ShadeRec sr = m_world_ptr->hit_bare_bones_obj(ray);
    if (sr.hit) {
        return sr.color;
    }
    else {
        return m_world_ptr->BACKGROUND_COLOR;
    }
    return sr.hit ? sr.color : m_world_ptr->BACKGROUND_COLOR;
}