/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Material.h
 * Author: maru
 *
 * Created on October 19, 2016, 1:32 PM
 */

#ifndef MATERIAL_H
#define MATERIAL_H

class Material {
public:
    Material();
    Material(const RGBColor& c);
    ~Material();
    
    const virtual RGBColor shade(const ShadeRec& sr) const = 0;

public:
    RGBColor color;
};


#endif /* MATERIAL_H */

