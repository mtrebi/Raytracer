/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   Flat.h
 * Author: maru
 *
 * Created on October 26, 2016, 9:58 AM
 */

#ifndef FLAT_H
#define FLAT_H

#include "Material.h"
class Flat : public Material {
public:
    Flat();
    Flat(const RGBColor& c);
    ~Flat();

    const virtual RGBColor shade(const ShadeRec& sr) const override;

};

#endif /* FLAT_H */

