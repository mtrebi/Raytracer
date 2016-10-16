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

RGBColour::RGBColour() {
}


RGBColour:: RGBColour(const uint16_t R, const uint16_t G, const uint16_t B){
    m_R = R;
    m_G = G;
    m_B = B;
}


RGBColour::~RGBColour() {
    m_R = 0;
    m_G = 0;
    m_B = 0;
}

std::istream& operator >> (std::istream& is, RGBColour& colour){
    is >> colour.m_R >> colour.m_G >> colour.m_B;
}

std::ostream& operator << (std::ostream& os, RGBColour& colour){
    os << "(R= " << colour.m_R << " G= " << colour.m_G << " B= " << colour.m_B << ")";
}
