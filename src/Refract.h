/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Refract.h
 * Author: maru
 *
 * Created on October 27, 2016, 2:27 PM
 */

#ifndef REFRACT_H
#define REFRACT_H

# include "Phong.h"

class Refract: public Phong {
public:
    Refract();
    Refract(const RGBColor& color, const float refraction_coef, const float kd = .4, const float ks = .4, const float sp_e = .0001, const float lci = 0.1);
    
    const virtual RGBColor shade(const ShadeRec& sr) const override;

private:
    const Vector3D refracted_vector(const Vector3D& N, const Vector3D& V, const float ref_coef) const;
private:
    float refraction_coef; // c2/c1
};


#endif /* REFRACT_H */

