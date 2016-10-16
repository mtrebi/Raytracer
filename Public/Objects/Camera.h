/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Camera.h
 * Author: maru
 *
 * Created on October 10, 2016, 4:46 PM
 */

#ifndef CAMERA_H
#define CAMERA_H

#include <cstdint>
#include <iostream>
#include "Objects/Object.h"


class Camera : public Object{
public:
    // Constructors
    Camera(const Vec3& location, const uint16_t fov = 90);
    Camera();
    
    // Getters
    const uint16_t getFOV() const { return m_fov; }
    
    // Operatos
    friend std::istream& operator >> (std::istream& is, Camera& camera);
    friend std::ostream& operator << (std::ostream& os, Camera& camera);
    
    // Destructor
    virtual ~Camera();
private:
    uint16_t m_fov;
};

#endif /* CAMERA_H */

