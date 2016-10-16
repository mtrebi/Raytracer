/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Box.cpp
 * Author: maru
 * 
 * Created on October 10, 2016, 3:05 PM
 */

#include "Objects/Shapes/Box.h"

Box::Box() : Shape(){
    m_side = 0;
}

Box::Box(const Vec3& location, const RGBColour& colour, const uint16_t side) 
    : Shape(location, colour) {
    m_side = side;
    m_boundsMax = location + Vec3(0.5 * m_side, 0.5 * m_side, 0.5 * m_side);
    m_boundsMin = location - Vec3(0.5 * m_side, 0.5 * m_side, 0.5 * m_side);
}

Box::~Box(){
    m_side = 0;
}

std::istream& operator >> (std::istream& is, Box& box){
    std::string BOX;
    is >> BOX >> box.m_location >> box.m_colour >> box.m_side;
    
    box.m_boundsMax = box.m_location + Vec3(0.5 * box.m_side, 0.5 * box.m_side, 0.5 * box.m_side);
    box.m_boundsMin = box.m_location - Vec3(0.5 * box.m_side, 0.5 * box.m_side, 0.5 * box.m_side);
}
std::ostream& operator << (std::ostream& os, Box& box){
    os << "BOX" << box.m_location << box.m_colour << box.m_side;
    
    box.m_boundsMax = box.m_location + Vec3(0.5 * box.m_side, 0.5 * box.m_side, 0.5 * box.m_side);
    box.m_boundsMin = box.m_location - Vec3(0.5 * box.m_side, 0.5 * box.m_side, 0.5 * box.m_side);
}