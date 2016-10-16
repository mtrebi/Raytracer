/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Box.h
 * Author: maru
 *
 * Created on October 10, 2016, 3:05 PM
 */

#ifndef BOX_H
#define BOX_H

#include <cstdint>
#include <iostream>
#include "Objects/Shapes/Shape.h"

class Box : public Shape {
public:
    // Constructors
    Box(const Vec3& location, const RGBColour& colour, const uint16_t side);
    Box();
    
    // Getters
    const uint16_t getSide() const { return m_side; }
    const Vec3 getBoundsMax() const { return m_boundsMax; }
    const Vec3 getBoundsMin() const { return m_boundsMin; }
    // Setters
    void setSide(const uint16_t side) { m_side = side; }
    
    // Operators
    friend std::istream& operator >> (std::istream& is, Box& box);
    friend std::ostream& operator << (std::ostream& os, Box& box);
    
    // Destructors
    virtual ~Box();
private:
    uint16_t m_side;
    Vec3 m_boundsMax;
    Vec3 m_boundsMin;
};

#endif /* BOX_H */

