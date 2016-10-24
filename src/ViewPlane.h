/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ViewPlane.h
 * Author: maru
 *
 * Created on October 19, 2016, 6:09 PM
 */

#ifndef VIEWPLANE_H
#define VIEWPLANE_H

#include "Sampler.h"

class ViewPlane {
public:
    ViewPlane();
    ViewPlane(const int width, const int height, float pixel_size, const float gamma);
    ~ViewPlane();

    void set_sampler(Sampler * sampler);
    const int get_n_samples() const;
public:
    int height, width;
    float pixel_size;
    float gamma, inv_gamma;
    Sampler * sampler_ptr;

};

#endif /* VIEWPLANE_H */

