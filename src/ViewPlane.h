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

class ViewPlane {
public:
    ViewPlane();
    ViewPlane(const int width, const int height, float pixel_size, const float gamma);
    ~ViewPlane();

public:
    int height, width;
    float pixel_size;
    float gamma, inv_gamma;
};

#endif /* VIEWPLANE_H */

