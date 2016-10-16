/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Camera.cpp
 * Author: maru
 * 
 * Created on October 10, 2016, 4:46 PM
 */

#include "Objects/Camera.h"

Camera::Camera(const Vec3& location, const uint16_t fov)
    : Object(location){
    m_fov = fov;
}

Camera::Camera() : Object (){
    m_fov = 0;
}

Camera::~Camera() {
    m_fov = 0;
}

std::istream& operator >> (std::istream& is, Camera& camera){
    std::string CAMERA;
    is >> CAMERA >> camera.m_location >> camera.m_fov;
}
std::ostream& operator << (std::ostream& os, Camera& camera){
    os << "CAMERA " << camera.m_location << camera.m_fov;
}
    
