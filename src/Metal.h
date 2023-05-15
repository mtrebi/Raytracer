/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   Metal.h
 * Author: maru
 *
 * Created on October 27, 2016, 9:54 AM
 */

#ifndef METAL_H
#define METAL_H

# include "Phong.h"
class Metal : public Phong {
public:
    Metal();
    Metal(const RGBColor& c, const float Kd = 0.4, const float Ks = 0.4, const float specular_e = 100, const float lci = 0.001);
    ~Metal();
};

#endif /* METAL_H */

