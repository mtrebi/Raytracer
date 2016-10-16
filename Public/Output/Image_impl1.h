/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Image_impl1.h
 * Author: maru
 *
 * Created on October 10, 2016, 3:34 PM
 */

#ifndef IMAGE_IMPL1_H
#define IMAGE_IMPL1_H

#include <vector>
#include <string>
#include <cstdint>
#include "Image.h"

class Image_impl1 : public Image {
public:
    // Constructors
    Image_impl1(const std::string inputFile);
    Image_impl1(const uint16_t width, const uint16_t height);
    
    // Getters
    virtual const RGBColour getPixelColour(const uint16_t x, const uint16_t y) const override;
    
    // Setters
    virtual void setPixelColour(const uint16_t x, const uint16_t y, const RGBColour& colour) override;
    
    // Functions
    virtual const bool save(const std::string& outputFile) const override;
    
    virtual ~Image_impl1();
private:
    const uint32_t convertIndex(const uint16_t x, const uint16_t y) const;
    
private:
    std::vector<RGBColour> pixels;
};

#endif /* IMAGE_IMPL1_H */

