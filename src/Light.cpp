/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "ShadeRec.h"
#include "Light.h"
#include "Ambient.h"

Light::Light(){

}

Light::Light(const float intensity, const RGBColor& color)
    : m_intensity(intensity), m_color(color) {
}

Light::~Light(){

}
