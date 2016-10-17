/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   RGBColour.cpp
 * Author: maru
 * 
 * Created on October 10, 2016, 3:59 PM
 */

#include "Utils/RGBColour.h"
#include <math.h>       /* fmod */
#include <stdlib.h>     /* abs */

RGBColour::RGBColour() {
}


RGBColour:: RGBColour(const uint16_t R, const uint16_t G, const uint16_t B){
    m_R = R;
    m_G = G;
    m_B = B;
}

RGBColour::RGBColour(const HSVColour hsv){
    double r = 0, g = 0, b = 0;
    double s = hsv.saturation(),
            h = hsv.hue(),
            v = hsv.value();
    if (s == 0){
        r = hsv.value();
        g = hsv.value();
        b = hsv.value();
    }
    else{
        int i;
        double f, p, q, t;
        
        if (h== 360)
            h = 0;
        else
            h /= 60;

        i = (int) trunc(h);
        f = h - i;

        p = v * (1.0 - s);
        q = v * (1.0 - (s * f));
        t = v * (1.0 - (s * (1.0 - f)));

        switch (i){
        case 0:
                r = v;
                g = t;
                b = p;
                break;

        case 1:
                r = q;
                g = v;
                b = p;
                break;

        case 2:
                r = p;
                g = v;
                b = t;
                break;

        case 3:
                r = p;
                g = q;
                b = v;
                break;

        case 4:
                r = t;
                g = p;
                b = v;
                break;

        default:
                r = v;
                g = p;
                b = q;
                break;
        }
    }
    m_R = r * 255;
    m_G = g * 255;
    m_B = b * 255;
}

RGBColour::~RGBColour() {
    m_R = 0;
    m_G = 0;
    m_B = 0;
}

std::istream& operator  >> (std::istream& is, RGBColour& colour){
    is >> colour.m_R >> colour.m_G >> colour.m_B;
}

std::ostream& operator << (std::ostream& os, RGBColour& colour){
    os << "(R= " << colour.m_R << " G= " << colour.m_G << " B= " << colour.m_B << ")";
}
