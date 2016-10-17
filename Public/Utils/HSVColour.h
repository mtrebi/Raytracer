/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   HSVColour.h
 * Author: maru
 *
 * Created on October 17, 2016, 10:15 AM
 */

#ifndef HSVCOLOUR_H
#define HSVCOLOUR_H

#include <cstdint>
class RGBColour;
#include "Utils/RGBColour.h"

class HSVColour {
public:
    HSVColour();
    HSVColour(const RGBColour rgbColour);
    HSVColour(const float hue, const float saturation, const float value);
    
    // Getters
    const float hue() const { return m_hue; }
    const float saturation() const { return m_saturation; }
    const float value() const { return m_value; }
    
    // Operators
    friend std::istream& operator >> (std::istream& is, HSVColour& colour);
    friend std::ostream& operator << (std::ostream& os, HSVColour& colour);

    // Functions
    void modifyBrightness(const float brightnessFactor);
    
    // Destructors
    virtual ~HSVColour();
private:
    float m_hue,            // From 0 to 360
            m_saturation,   // From 0 to 1
            m_value;        // From 0 to 1
};

#endif /* HSVCOLOUR_H */

