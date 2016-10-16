/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Light.cpp
 * Author: maru
 * 
 * Created on October 10, 2016, 4:47 PM
 */

#include "Objects/Light.h"

Light::Light(const Vec3& location, const uint8_t intensity) 
    : Object(location){
    m_intensity = intensity;
}

Light::Light(){
    m_intensity = 0;
}

Light::~Light(){
    m_intensity = 0;
}

std::istream& operator >> (std::istream& is, Light& light){
    std::string LIGHT;
    is >> LIGHT >> light.m_location >> light.m_intensity;
}

std::ostream& operator << (std::ostream& os, Light& light){
    os << "LIGHT " << light.m_location << light.m_intensity;
}
    