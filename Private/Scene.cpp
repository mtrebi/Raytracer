/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Scene.cpp
 * Author: maru
 * 
 * Created on October 10, 2016, 4:40 PM
 */

#include <iostream>
#include <fstream>
#include <string>
#include <limits>
#include <math.h>
#include "Scene.h"
#include "Objects/Shapes/Box.h"
#include "Objects/Shapes/Sphere.h"
#include "Utils/Ray.h"

Scene::Scene(){
    m_shapes = std::vector<Shape*>();
    m_light = nullptr;
    m_camera = nullptr;
}

Scene::Scene(const std::string inputFile){
    // read from file
    std::ifstream file;
    file.open(inputFile);
    if (file.is_open()){
        Camera* camera = new Camera();
        file >> *camera;
        
        this->m_camera = camera;
          
        Light* light = new Light();
        file >> *light;
        this->m_light = light;
        
        uint16_t nObjects;
        file >> nObjects;
        this->m_shapes = std::vector<Shape*>(nObjects);
        for(int i = 0; i < nObjects; ++i){
            
            //TODO Shape 
            //Box* box = new Box();
            //Sphere* box = new Sphere();
            //file >> *box;
            //this->m_shapes[i] = box;
        }        
    }    
   
    file.close();
}

Vec3 pixelToWorldSpace(const uint16_t x, const uint16_t y, const uint16_t width, const uint16_t height, const uint16_t fov){   
    float fwidth = static_cast<float>(width);
    float fheight = static_cast<float>(height);
    const float aspectRatio = fwidth/fheight;
    
    // Map values between from (0, height) to [-1,1] for y, 
    // and from (0, width) to [-AR, AR] for x
    const float xScreenSpace = (2 * ((x + 0.5) / fwidth) - 1 ) * aspectRatio;
    const float yScreenSpace = 1 - 2 * ((y + 0.5) / fheight);

    // TODO
    // If camera is aligned and centered of the coordinate's origin
    //  camera space is equal to world space
    const float xCameraSpace = xScreenSpace * tan(M_PI * 0.5 * fov / 180.); 
    const float yCameraSpace = yScreenSpace * tan(M_PI * 0.5 * fov / 180.); 
    
    return Vec3(xCameraSpace, yCameraSpace, -1);    
}

const Image& Scene::render2d(const uint16_t width, const uint16_t height) const{
    Image* image = new Image_impl1(width, height);
    
    for (uint32_t x = 0; x < width; ++x){
        for (uint32_t y = 0; y < height; ++y){
            IntersectionInfo newHit, 
                    closestHit {.hit = false,
                            .hitDistance = std::numeric_limits<float>::max(),
                            .hitPoint = Vec3(0,0,0),
                            .hitNormal = Vec3(0,0,0),
                            .hitShape = nullptr};
            RGBColour colour{255, 255, 255};
            for(const Shape* shape: m_shapes){
                // Compute Ray trace against Shape
                const Vec3 pixelPosition = pixelToWorldSpace(x, y, width, height, m_camera->getFOV());
                Vec3 rayDirection = pixelPosition - m_camera->getLocation(); rayDirection.normalize();
                const Ray ray = Ray(m_camera->getLocation(), rayDirection);
                const bool hit = shape->intersect(newHit, ray);
                if (hit && closestHit.hitDistance > newHit.hitDistance){
                    closestHit = newHit;   
                    //TODO CHECK info (shadow, reflections, refractions, normal)
                }
            }
            
            if (closestHit.hit){
                /* Compute illumination
                for(const Shape* shape: m_shapes){
                    Vec3 rayLightDirection = m_light->getLocation() - closestHit.hitPoint; rayLightDirection.normalize();
                    const Ray raylight = Ray(closestHit.hitPoint, rayLightDirection);
                    const bool hit = shape->intersect(newHit, raylight);
                    if (hit){
                        //SHADOW!
                        //colour = colour
                    }
                 
                   
                } */
                colour = closestHit.hitShape->getColour();
            }
            image->setPixelColour(x, y, colour);
        }
    }
    return *image;
}

Scene::~Scene(){
    m_shapes.clear();
    delete m_camera;
    delete m_light;
}

void Scene::addShape(Shape* shape){
    m_shapes.push_back(shape);
}

void Scene::addCamera(Camera* camera){
    m_camera = camera;
}

void Scene::addLight(Light* light){
    m_light = light;
}
    
std::ostream& operator << (std::ostream& out, Scene& scene){
    out << scene.m_camera << std::endl;
    out << scene.m_light << std::endl;
    out << "OBJECTS " << scene.m_shapes.size() << std::endl;
}
