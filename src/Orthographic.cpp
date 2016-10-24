/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "Orthographic.h"

Orthographic::Orthographic()
    : Camera(){
    
}

Orthographic::Orthographic(const Point3D& eye, const Point3D& lookat)
    : Camera(eye, lookat, 0){
    
}

Orthographic::~Orthographic(){
    
}

Vector3D Orthographic::calculate_ray_dir(const Point2D& p){
    Vector3D ray_dir = m_eye - m_lookat;
    ray_dir.normalize();
    return ray_dir;
}

void Orthographic::render_scene(World * world){
    Ray ray;


    for (int x = 0; x < world->m_vp.width; ++x){
        for (int y = 0; y < world->m_vp.height; ++y){
            RGBColor pixel_color;
            for (int s = 0; s < world->m_vp.get_n_samples(); ++s){
                const Point2D sample = world->m_vp.sampler_ptr->next_sample();
                Point2D pixel;
                pixel.x = (x - 0.5 * (world->m_vp.width + sample.x));
                pixel.y = (y - 0.5 * (world->m_vp.height + sample.y));

                ray.o = Point3D(pixel.x, pixel.y, -100);
                ray.d = calculate_ray_dir(pixel);
                
                pixel_color += world->m_tracer_ptr->trace_ray(ray);
            }
            pixel_color /= world->m_vp.get_n_samples();
            world->display_pixel(x, y, pixel_color);
        }
    }
}