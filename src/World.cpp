/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "World.h"
#include <limits>
#include "Vector3D.h"
#include "Point3D.h"
#include "Normal.h"
#include "Ray.h"
#include "Sphere.h"
#include "Plane.h"
#include "Regular.h"
#include <fstream>
#include "Orthographic.h"
#include "Perspective.h"
#include "Light.h"
#include "Ambient.h"

World::World(){
    m_vp = ViewPlane(200, 200, 1.0);
    m_objects = std::vector<GeometryObject*>(0);
    m_pixels = std::vector<RGBColor>(m_vp.width * m_vp.height);
}

World::~World(){
    delete m_tracer_ptr;
}

void World::set_ambient(Light * light){
    m_ambient = light;
}

void World::add_object(GeometryObject* obj){
    m_objects.push_back(obj);
}

void World::add_light(Light* light){
    m_lights.push_back(light);
}

void World::build(){
    //m_camera_ptr = new Orthographic(Point3D(0,0,0), Point3D(0,0,1));
    m_camera_ptr = new Perspective(Point3D(0,0,-100), Point3D(0,0,0), 100);
    m_tracer_ptr = new MultiTracer(this);
    m_vp.set_sampler(new Regular(1, 1));
    
    Sphere* red_sphere = new Sphere(Point3D(0,0,0), 65);
    red_sphere->setColor(RGBColor(1,0,0));
    add_object(red_sphere);
    
    //Light * point_light = new Point(Point3D(0, 200, 0), RGBColor(.9,.9,.9), 10);
    //add_light(point_light);
    
    Light * ambient_light = new Ambient(1, RGBColor(0.9,0.9,0.9));
    set_ambient(ambient_light);
    /*
    Sphere* yellow_sphere = new Sphere(Point3D(0,30,0), 60);
    yellow_sphere->setColor(RGBColor(1,1,0));
    add_object(yellow_sphere);

    Plane* green_plane = new Plane(Point3D(0,0,0), Normal(0,1,1));
    green_plane->setColor(RGBColor(0,1,0));
    add_object(green_plane);
    */
}

void World::render_scene() {
    if (m_camera_ptr != nullptr){
        m_camera_ptr->render_scene(this);
    }
}

const ShadeRec World::hit_bare_bones_obj(const Ray& ray) const {
    ShadeRec sr_min, sr;
    
    sr_min.hit = false;
    sr_min.color = RGBColor();
    sr_min.hit_point = Point3D();
    sr_min.local_hit_point = Point3D();    
    sr_min.hit_normal = Normal();
    sr_min.ray = ray;
    //sr.world = *this;

    double t, t_min = std::numeric_limits<float>::max();
    for(const auto& obj : m_objects){
        if (obj->hit(ray, t, sr) && (t < t_min)){
            t_min = t;
            sr_min = sr;
        }
    }
    return sr_min;
}

void World::display_pixel(const int x, const int y, const RGBColor& pixel_color) {
    int new_index = (y * m_vp.width) + x;
    m_pixels[new_index] = pixel_color;
}

#include <iostream>

void World::save_image(const std::string& outputFile) const {
    const int image_size = m_vp.height * m_vp.width * 4;
    const int headers_size = 14 + 40;
    const int filesize = image_size + headers_size;
    const int pixelsPerMeter = 2835;
    
    unsigned char bmpfileheader[14] = {'B','M', 0,0,0,0, 0,0,0,0, 54,0,0,0};
    //size of the file in bytes
    bmpfileheader[ 2] = (unsigned char)(filesize);
    bmpfileheader[ 3] = (unsigned char)(filesize>>8);
    bmpfileheader[ 4] = (unsigned char)(filesize>>16);
    bmpfileheader[ 5] = (unsigned char)(filesize>>24);
            
    unsigned char bmpinfoheader[40] = {40,0,0,0, 0,0,0,0, 0,0,0,0, 1,0,24,0};
    //width of the image in bytes
    bmpinfoheader[ 4] = (unsigned char)(m_vp.width);
    bmpinfoheader[ 5] = (unsigned char)(m_vp.width>>8);
    bmpinfoheader[ 6] = (unsigned char)(m_vp.width>>16);
    bmpinfoheader[ 7] = (unsigned char)(m_vp.width>>24);
    
    //height of the image in bytes
    bmpinfoheader[ 8] = (unsigned char)(m_vp.height);
    bmpinfoheader[ 9] = (unsigned char)(m_vp.height>>8);
    bmpinfoheader[10] = (unsigned char)(m_vp.height>>16);
    bmpinfoheader[11] = (unsigned char)(m_vp.height>>24);

    // Size image in bytes
    bmpinfoheader[21] = (unsigned char)(image_size);
    bmpinfoheader[22] = (unsigned char)(image_size>>8);
    bmpinfoheader[23] = (unsigned char)(image_size>>16);
    bmpinfoheader[24] = (unsigned char)(image_size>>24);

    bmpinfoheader[25] = (unsigned char)(pixelsPerMeter);
    bmpinfoheader[26] = (unsigned char)(pixelsPerMeter>>8);
    bmpinfoheader[27] = (unsigned char)(pixelsPerMeter>>16);
    bmpinfoheader[28] = (unsigned char)(pixelsPerMeter>>24);

    bmpinfoheader[29] = (unsigned char)(pixelsPerMeter);
    bmpinfoheader[30] = (unsigned char)(pixelsPerMeter>>8);
    bmpinfoheader[31] = (unsigned char)(pixelsPerMeter>>16);
    bmpinfoheader[32] = (unsigned char)(pixelsPerMeter>>24);

    FILE *file = fopen(outputFile.c_str(), "wb");//write-binary
    
    fwrite(bmpfileheader,1,14, file);
    fwrite(bmpinfoheader,1,40, file);
    
    for (int i = 0; i < m_pixels.size(); ++i){
        const RGBColor pixel = m_pixels[i];
        unsigned char color[3] = {
            (int) (pixel.b * 255), 
            (int) (pixel.g * 255), 
            (int) (pixel.r * 255)
        };
        std::cout << color[2] << " ";
        fwrite(color, 1, 3, file);
    }
    fclose(file);
}

