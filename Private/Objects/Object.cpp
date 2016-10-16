/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Object.cpp
 * Author: maru
 * 
 * Created on October 10, 2016, 2:41 PM
 */

#include "Objects/Object.h"


Object::Object(const Vec3& location){
    m_location = location;
}

Object::Object(){}


Object::~Object(){
    m_location = Vec3(0,0,0);
}

