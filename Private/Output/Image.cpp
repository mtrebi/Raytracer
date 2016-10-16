/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Image.cpp
 * Author: maru
 * 
 * Created on October 10, 2016, 3:20 PM
 */

#include "Output/Image.h"

Image::Image(const uint16_t width, const uint16_t height){
    m_width = width;
    m_height = height;
}

Image::Image(){
    
}

Image::~Image(){
    m_width = 0;
    m_height = 0;
}
