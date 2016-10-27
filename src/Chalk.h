/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Chalk.h
 * Author: maru
 *
 * Created on October 27, 2016, 9:47 AM
 */

#ifndef CHALK_H
#define CHALK_H

# include "Phong.h"

class Chalk : public Phong {
public:
    Chalk();
    Chalk(const RGBColor& c, const float Kd = 0.4, const float Ks = 0.2, const float specular_e = 2, const float light_color_inf = 0.25);
    ~Chalk();
};

#endif /* CHALK_H */

