/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Plastic.h
 * Author: maru
 *
 * Created on October 27, 2016, 9:33 AM
 */

#ifndef PLASTIC_H
#define PLASTIC_H

#include "Phong.h"

class Plastic : public Phong {
public:
    Plastic();
    Plastic(const RGBColor& c, const float Kd = 0.4, const float Ks = 0.4, const float specular_e = 20, const float light_color_inf = 0.35);
    ~Plastic();
};

#endif /* PLASTIC_H */

