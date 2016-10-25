/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Plastic.h
 * Author: maru
 *
 * Created on October 25, 2016, 4:12 PM
 */

#ifndef PHONG_H
#define PHONG_H

#include "Material.h"

class Phong : public Material {
public:
    Phong();
    Phong(const RGBColor& c);
    ~Phong();
    
    const virtual RGBColor shade(const ShadeRec& sr) const override;

private:
    const float Ka = 0.2;
    const float Kd = 0.4;
    const float Ks = 0.4;
    const int specular_shininess = 20;
};


#endif /* PHONG_H */

