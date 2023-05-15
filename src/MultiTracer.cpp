/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <iostream>
#include "MultiTracer.h"
#include "World.h"
#include "Material.h"
#include "Constants.h"
#include "ShadeRec.h"

MultiTracer::MultiTracer()
    : Tracer() {

}

MultiTracer::MultiTracer(World *world_ptr)
    : Tracer(world_ptr) {

}

const RGBColor MultiTracer::trace_ray(const Ray& ray, const std::vector<GeometryObject*> ignore, const int depth) const {
    ShadeRec sr = m_world_ptr->hit_bare_bones_obj(ray, ignore);
    if (sr.hit) {
        return sr.material_ptr->shade(sr) * trace_shadow_ray(sr);
    }
    else {
        return m_world_ptr->BACKGROUND_COLOR;
    }
}

const float MultiTracer::trace_shadow_ray(const ShadeRec& sr) const {
    const float shadow_min = .45;
    int shadowed_by_n_lights = 0;
    for(const auto& light : m_world_ptr->m_lights){
        const Point3D ray_origin = sr.hit_point;
        const Vector3D ray_dir = light->get_direction(ray_origin);
        const Ray ray = Ray(ray_origin, ray_dir);
        std::vector<GeometryObject*> ignore = std::vector<GeometryObject*>();
        ignore.push_back(sr.obj_ptr);
        ShadeRec sr_shadow = m_world_ptr->hit_bare_bones_obj(ray, ignore);

        if (sr_shadow.hit && ray_origin.distance(sr_shadow.hit_point) < light->get_distance(ray_origin)){
            ++shadowed_by_n_lights;
        }
    }
    const float iluminated_by_lights = m_world_ptr->m_lights.size() - shadowed_by_n_lights;
    const float light_proportion = (iluminated_by_lights/m_world_ptr->m_lights.size());
    return (shadowed_by_n_lights > 0) ?  light_proportion + shadow_min : 1;
}
