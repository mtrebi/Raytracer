/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

# include "ViewPlane.h"
# include "Regular.h"
ViewPlane::ViewPlane(){
    
}

ViewPlane::ViewPlane(const int width, const int height, float pixel_size, const float gamma){
    this->width = width;
    this->height = height;
    this->pixel_size = pixel_size;
    this->gamma = gamma;
    this->inv_gamma = 1 / gamma;
    
    this->sampler_ptr = new Regular(25,1);
}

ViewPlane::~ViewPlane(){
    delete sampler_ptr;
}


void ViewPlane::set_sampler(Sampler * sampler){
    if (sampler_ptr != nullptr){
        //delete sampler_ptr;
        sampler_ptr = nullptr;
    }
    sampler_ptr = sampler;
}

const int ViewPlane::get_n_samples() const {
    if (sampler_ptr == nullptr){
        return 0;
    }
    return sampler_ptr->get_n_samples(); 
}
