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
public:
    RGBColor color;
    float f_specular_reflection;
};


#endif /* MATERIAL_H */

