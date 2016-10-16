/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Shape.cpp
 * Author: maru
 * 
 * Created on October 10, 2016, 5:19 PM
 */

#include "Objects/Shapes/Shape.h"

Shape::Shape(const Vec3& location, const RGBColour& colour)
    : Object(location){
    m_colour = colour;
}

Shape::Shape() : Object() {
    m_colour = RGBColour(0,0,0);
}

Shape::~Shape(){
    m_colour = RGBColour(0,0,0); 
}
