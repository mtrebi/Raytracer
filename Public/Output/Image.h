/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Image.h
 * Author: maru
 *
 * Created on October 10, 2016, 3:20 PM
 */

#ifndef IMAGE_H
#define IMAGE_H

#include <string>
#include <cstdint>
#include "Utils/RGBColour.h"

class Image {
public:
    // Constructors
    Image(const uint16_t width, const uint16_t height);
    Image();
    
    // Getters
    const uint16_t getWidth() { return m_width; }
    const uint16_t getHeight() { return m_height; }
    virtual const RGBColour getPixelColour(const uint16_t x, const uint16_t y) const = 0;
    
    // Setters
    virtual void setPixelColour(const uint16_t x, const uint16_t y, const RGBColour& colour) = 0;
    
    // Functions
    virtual const bool save(const std::string& outputFile) const = 0;
    
    virtual ~Image();
protected:
    uint16_t m_width, 
            m_height;
};

#endif /* IMAGE_H */

