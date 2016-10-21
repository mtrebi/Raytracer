/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

# include "ViewPlane.h"

ViewPlane::ViewPlane(){
    
}

ViewPlane::ViewPlane(const int width, const int height, float pixel_size, const float gamma){
    this->width = width;
    this->height = height;
    this->pixel_size = pixel_size;
    this->gamma = gamma;
    this->inv_gamma = 1 / gamma;
}

ViewPlane::~ViewPlane(){
    
}
