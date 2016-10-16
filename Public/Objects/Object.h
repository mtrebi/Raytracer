/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Object.h
 * Author: maru
 *
 * Created on October 10, 2016, 2:41 PM
 */

#ifndef OBJECT_H
#define OBJECT_H

#include <iostream>
#include "Utils/Vec3.h"
#include "Utils/RGBColour.h"

class Object {
public:
    // Constructors
    Object(const Vec3& location);
    Object();
    // Getters
    const Vec3 getLocation() const { return m_location; }

    // Setters
    void setLocation(const Vec3& location) { m_location = location; }
    
    virtual ~Object();
protected:
    // Position
    Vec3 m_location;
};

#endif /* OBJECT_H */

