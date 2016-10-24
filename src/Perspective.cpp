/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

# include "Perspective.h"


Perspective::Perspective()
    : Camera(){
    
}

Perspective::Perspective(const Point3D& eye, const Point3D& lookat, const float distance)
    : Camera(eye, lookat, distance){
    
}

Perspective::~Perspective(){
    
}

Vector3D Perspective::calculate_ray_dir(const Point2D& p){
    Vector3D ray_dir = p.x * m_u + p.y * m_v - m_distance_view_plane * m_w;
    ray_dir.normalize();
    return ray_dir;
}

void Perspective::render_scene(World * world){
    Ray ray;

    ray.o = m_eye;
    for (int x = 0; x < world->m_vp.width; ++x){
        for (int y = 0; y < world->m_vp.height; ++y){
            RGBColor pixel_color;
            for (int s = 0; s < world->m_vp.get_n_samples(); ++s){
                const Point2D sample = world->m_vp.sampler_ptr->next_sample();
                const Point2D pixel = 
                    Point2D(x - 0.5 * (world->m_vp.width + sample.x),
                        y - 0.5 * (world->m_vp.height + sample.y));
                
                ray.d = calculate_ray_dir(pixel);
                pixel_color += world->m_tracer_ptr->trace_ray(ray);
            }
            pixel_color /= world->m_vp.get_n_samples();
            world->display_pixel(x, y, pixel_color);
        }
    }
}