/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   World.h
 * Author: maru
 *
 * Created on October 19, 2016, 5:04 PM
 */

#ifndef WORLD_H
#define WORLD_H

#include "ViewPlane.h"
#include "RGBColor.h"
#include "GeometryObject.h"
#include <vector>
#include "MultiTracer.h"
#include <string>
class World {
private:
    std::vector<RGBColor> m_pixels;
    std::vector<GeometryObject*> m_objects;
    ViewPlane m_vp;
    Tracer * m_tracer;
public:
    const RGBColor BACKGROUND_COLOR = RGBColor(0,0,0);

public:
    World();
    ~World();
    
    void add_object(GeometryObject* obj);
    
    void build();
    void render_scene();
    const ShadeRec hit_bare_bones_obj(const Ray& ray) const;

    
    void open_window(const int hres, const int vres) const;
    void display_pixel(const int row, const int column, const RGBColor& pixel_color);

    void save_image(const std::string& outputFile) const;
};


#endif /* WORLD_H */

