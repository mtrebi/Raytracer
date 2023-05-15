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
    Phong(const RGBColor& c, const float Kd, const float Ks, const float specular_e, const float light_color_inf);
    ~Phong() = default;

    const virtual RGBColor shade(const ShadeRec& sr) const override;

protected:
    float Ka = 0.2;
    float Kd;
    float Ks;
    float specular_e;
    // light color influence when merging light color with obj. color.
    // Which color is more important? 0 -> Pure object, 1 -> Pure light
    float light_color_inf;
};

#endif /* PHONG_H */

