/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Scene.h
 * Author: maru
 *
 * Created on October 10, 2016, 4:40 PM
 */

#ifndef SCENE_H
#define SCENE_H

#include <string>
#include <vector>
#include <iostream>

#include "Output/Image_impl1.h"
#include "Objects/Light.h"
#include "Objects/Camera.h"
#include "Objects/Object.h"
#include "Objects/Shapes/Shape.h"

class Scene {
public:
    Scene();
    Scene(const std::string inputFile);
    //TODO Scene(const Scene& orig);
    
    const Image& render2d(const uint16_t width, const uint16_t height) const;
    
    void addShape(Shape* shape);
    void addCamera(Camera* camera);
    void addLight(Light* light);

    friend std::ostream& operator << (std::ostream& out, Scene& scene);

    virtual ~Scene();  
private:
    const IntersectionInfo visibilityTrace(const Ray& ray) const;
    const float shadowTrace (const Ray& ray) const;
    const float LambertianShading(const Vec3& hitPoint, const Vec3& hitPointNormal) const;

    const RGBColour shadeColour(const RGBColour& colour, const float shading_factor) const;
private:
    //TODO built-in
    Camera * m_camera;
    Light * m_light;
    std::vector<Shape*> m_shapes;

    const RGBColour BACKGROUND_COLOR = RGBColour(255,255,255);
    // Min. amount of light that can receive and object
    const float AMBIENT_COEFFICIENT = 0.25;                  
    // Amount of light determined by the Lambertian/cosine shading
    const float DIFFUSE_COEFFICIENT = 1 - AMBIENT_COEFFICIENT;
    // Amount of light for hard shadows
    const float HARD_SHADOWS_COEFFICIENT = 0.2;
    const int RAY_DEPTH = 5;

    const bool FLAG_HARD_SHADOWS = true;
    const bool FLAG_LAMBERTIAN_SHADING = true;
};

#endif /* SCENE_H */

