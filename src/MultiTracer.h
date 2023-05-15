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

    const RGBColor trace_ray(const Ray& ray, const std::vector<GeometryObject*> ignore = std::vector<GeometryObject*>(), const int depth = 2) const override;
private:
    const float trace_shadow_ray(const ShadeRec& sr) const;
};


#endif /* MULTITRACER_H */

