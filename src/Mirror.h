/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Mirror.h
 * Author: maru
 *
 * Created on October 27, 2016, 10:20 AM
 */

#ifndef MIRROR_H
#define MIRROR_H

#include "Phong.h"

class Mirror : public Phong {
public:
    Mirror(const float Kd = 1, const float Ks = 0.5, const float specular_e = 1, const float lci = 0.01);
    ~Mirror();
    
    const virtual RGBColor shade(const ShadeRec& sr) const override;
     
};

#endif /* MIRROR_H */

