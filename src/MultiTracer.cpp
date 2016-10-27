/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "MultiTracer.h"
#include "World.h"
#include "Material.h"
#include "Constants.h"

MultiTracer::MultiTracer()
    : Tracer() {
    
}

MultiTracer::MultiTracer(World * world_ptr)
    : Tracer(world_ptr) {
    
}

const RGBColor MultiTracer::trace_ray(const Ray& ray, const std::vector<GeometryObject*> ignore, const int depth) const{
    ShadeRec sr = m_world_ptr->hit_bare_bones_obj(ray, ignore);
    if (sr.hit) {
        float shadow_modifier = 1;
        if (trace_shadow_ray(sr)){
            shadow_modifier = 0.4;
        }
        return sr.material_ptr->shade(sr) * shadow_modifier;
    }
    else {
        return m_world_ptr->BACKGROUND_COLOR;
    }
}

const bool MultiTracer::trace_shadow_ray(const ShadeRec& sr) const {
    for(const auto& light : m_world_ptr->m_lights){
        const Point3D ray_origin = sr.hit_point;
        const Vector3D ray_dir = light->get_direction(ray_origin);
        const Ray ray = Ray(ray_origin, ray_dir);
        std::vector<GeometryObject*> ignore = std::vector<GeometryObject*>();
        ignore.push_back(sr.obj_ptr);
        ShadeRec sr_shadow = m_world_ptr->hit_bare_bones_obj(ray, ignore);
        if (sr_shadow.hit && ray_origin.distance(sr_shadow.hit_point) < light->get_distance(ray_origin)) {// && {
            return sr_shadow.hit;
        }
    }
    return false;
}