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
#include "Point.h"
#include <algorithm>
#include "Phong.h"
#include "Constants.h"
#include "Plastic.h"
#include "Chalk.h"
#include "Metal.h"
#include "Mirror.h"

World::World(){
    m_vp = ViewPlane(640, 480, 1.0);
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

void World::build_cornel_box(){
    m_camera_ptr = new Perspective(Point3D(0,0,500), Point3D(-5,0,0), 850);
    m_tracer_ptr = new MultiTracer(this);
    m_vp.set_sampler(new Regular(1, 1));
        
    // Build walls
    
    Plane* floor = new Plane(Point3D(0,-100,0), Normal(0,1,0));
    floor->setMaterial(new Chalk(Colors::white));
    add_object(floor);
    
    Plane* ceil = new Plane(Point3D(0,100,0), Normal(0,-1,0));
    ceil->setMaterial(new Chalk(Colors::white));
    add_object(ceil);
    
    Plane* left_wall = new Plane(Point3D(-100,0,0), Normal(1,0,0));
    left_wall->setMaterial(new Chalk(Colors::red));
    add_object(left_wall);
    
    Plane* right_wall = new Plane(Point3D(100,0,0), Normal(-1,0,0));
    right_wall->setMaterial(new Chalk(Colors::green));
    add_object(right_wall);
    
    Plane* back_wall = new Plane(Point3D(0,0,-100), Normal(0,0,1));
    back_wall->setMaterial(new Chalk(Colors::white));
    add_object(back_wall);
    
    Plane* front_wall = new Plane(Point3D(0,0,500), Normal(0,0,1));
    front_wall->setMaterial(new Chalk(Colors::black));
    add_object(front_wall);
    
    // Build lights
    Ambient * ambient_ptr = new Ambient(1, RGBColor(.3,.3,.3));
    set_ambient(ambient_ptr);
    
    Light * point_ptr = new Point(Point3D(0, 55, 75), 1, Colors::red);
    add_light(point_ptr);
    
    // Build objects
    Sphere* plastic_sphere = new Sphere(Point3D(50, 0,0), 40);
    plastic_sphere->setMaterial(new Plastic(Colors::white));
    add_object(plastic_sphere);
    
    Sphere* metal_sphere = new Sphere(Point3D(-50, 0, 60), 30);
    metal_sphere->setMaterial(new Metal(Colors::blue));
    add_object(metal_sphere);
    
    Sphere* mirror_sphere = new Sphere(Point3D(-20, -60, 0), 25);
    mirror_sphere->setMaterial(new Mirror());
    add_object(mirror_sphere);
}

void World::render_scene() {
    if (m_camera_ptr != nullptr){
        m_camera_ptr->render_scene(this);
    }
}

const ShadeRec World::hit_bare_bones_obj(const Ray& ray, const std::vector<GeometryObject*> ignore){
    ShadeRec sr_min, sr;
    
    sr_min.hit = false;
    sr_min.material_ptr = nullptr;
    sr_min.hit_point = Point3D();
    sr_min.hit_normal = Normal();
    sr_min.ray = ray;
    sr.world_ptr = this;

    double t, t_min = std::numeric_limits<float>::max();
    for(const auto& obj : m_objects){
        if (std::find(ignore.begin(), ignore.end(), obj) == ignore.end()){
            
            if (obj->hit(ray, t, sr) && t > 0 && (t < t_min)){
                t_min = t;
                sr_min = sr;
            }
        }
    }
    return sr_min;
}

void World::display_pixel(const int x, const int y, const RGBColor& pixel_color) {
    RGBColor tempColor;
    int new_index = (y * m_vp.width) + x;
    tempColor.r = std::fmin(pixel_color.r, 1);
    tempColor.g = std::fmin(pixel_color.g, 1);
    tempColor.b = std::fmin(pixel_color.b, 1);

    m_pixels[new_index] = tempColor;
}

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
        fwrite(color, 1, 3, file);
    }
    fclose(file);
}

