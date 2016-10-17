/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   HSVColour.cpp
 * Author: maru
 * 
 * Created on October 17, 2016, 10:15 AM
 */

#include "Utils/HSVColour.h"
#include <math.h>
#include <algorithm>

HSVColour::HSVColour() {
    m_hue = 0;
    m_saturation = 0;
    m_value = 0;
}

HSVColour::HSVColour(const float hue, const float saturation, const float value){
    m_hue = hue;
    m_saturation = saturation;
    m_value = value;
}
    

HSVColour::HSVColour(const RGBColour rgbColour){
    // Value calculation
    float h, s, v;
    const float  r = rgbColour.r() / 255.0;
    const float  g = rgbColour.g() / 255.0;
    const float  b = rgbColour.b() / 255.0;
    const float maxColor = std::max(r, std::max(g, b));
    const float minColor = std::min(r, std::min(g, b));
    const float delta = maxColor - minColor;
    
    // Saturation
    if(maxColor == 0){ //avoid division by zero when the color is black
        s = 0;
    } else{
        s = (delta) / maxColor;
    }
    
    // Hue
    if(s == 0){
        h = 0; //it doesn't matter what value it has
    } else {
        if(r == maxColor) {
            h = fmod(((g - b) / (delta)), 6);
        }
        else if(g == maxColor){
            h = 2.0 + (b - r) / (maxColor - minColor);
        } else {
            h = 4.0 + (r - g) / (maxColor - minColor);
        }
        h *= 60.0; //degrees
        //if (h < 0) h+=360.0;
    }
    m_hue = h;
    m_saturation = s;
    m_value = maxColor ;

}


HSVColour::~HSVColour() {
    m_hue = 0;
    m_saturation = 0;
    m_value = 0;
}

std::istream& operator >> (std::istream& is, HSVColour& colour){
    is >> colour.m_hue >> colour.m_saturation >> colour.m_value;
}

std::ostream& operator << (std::ostream& os, HSVColour& colour){
    os << "(H= " << colour.m_hue << " S= " << colour.m_saturation << " V= " << colour.m_value << ")";
}
// brightness between 0 and 1
void HSVColour::modifyBrightness(const float brightness){
    m_value = brightness;
}
