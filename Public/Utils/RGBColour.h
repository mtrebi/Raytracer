/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   RGBColour.h
 * Author: maru
 *
 * Created on October 10, 2016, 3:59 PM
 */

#ifndef RGBCOLOUR_H
#define RGBCOLOUR_H

#include <cstdint>
#include <iostream>
class HSVColour;
#include "Utils/HSVColour.h"

class RGBColour {
public:
    // Constructors
    RGBColour(const uint16_t R, const uint16_t G, const uint16_t B);
    RGBColour(const HSVColour hsv);
    RGBColour();
    
    // Getters
    const uint16_t r() const { return m_R; }
    const uint16_t g() const { return m_G; }
    const uint16_t b() const { return m_B; }
    
    // Operators
    friend std::istream& operator >> (std::istream& is, RGBColour& colour);
    friend std::ostream& operator << (std::ostream& os, RGBColour& colour);

    // Destructors
    virtual ~RGBColour();
private:
    int m_R,
            m_G,
            m_B;
};

#endif /* RGBCOLOUR_H */

