/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Light.h
 * Author: maru
 *
 * Created on October 10, 2016, 4:47 PM
 */

#ifndef LIGHT_H
#define LIGHT_H

#include "Object.h"
#include <iostream>

class Light : public Object {
public:
    // Constructors
    Light(const Vec3& location, const uint8_t intensity);
    Light();
    // Getters
    const uint8_t getIntensity() const { return m_intensity; }
    
    // Operators
    friend std::istream& operator >> (std::istream& is, Light& light);
    friend std::ostream& operator << (std::ostream& os, Light& light);
    
    // Setters
    virtual ~Light();
private:
    uint16_t m_intensity;
    //TODO directional lights?
};

#endif /* LIGHT_H */

