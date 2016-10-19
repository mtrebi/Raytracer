/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Point3.h
 * Author: maru
 *
 * Created on October 10, 2016, 2:51 PM
 */

#ifndef VEC3_H
#define VEC3_H

#include <iostream>
#include <math.h>

class Vec3 {
public:
    // Constructors
    Vec3();
    Vec3(const float x, const float, const float z);
    
    // Operators
    friend Vec3 operator- (const Vec3& v1, const Vec3& v2);
    friend Vec3 operator+ (const Vec3& v1, const Vec3& v2);

    friend Vec3 operator/ (const Vec3& v, const int i);
    friend Vec3 operator/ (const int i, const Vec3& v);

    friend Vec3 operator* (const Vec3& v1, const int i);
    friend Vec3 operator* (const int i, const Vec3& v1);
    
    friend bool operator== (const Vec3& v1, const Vec3& v2);
    friend bool operator!= (const Vec3& v1, const Vec3& v2);
    friend bool operator< (const Vec3& v1, const Vec3& v2);
    friend bool operator<= (const Vec3& v1, const Vec3& v2);
    friend bool operator> (const Vec3& v1, const Vec3& v2);
    friend bool operator>= (const Vec3& v1, const Vec3& v2);  
    
    friend std::istream& operator >> (std::istream& is, Vec3& vec3);
    friend std::ostream& operator << (std::ostream& os, Vec3& vec3);
    
    const float distance (const Vec3& vec3) const;
    
    const float length() const ;
    
    static const float dot(const Vec3& v1, const Vec3& v2);
    
    const float dot(const Vec3& v1) const;  
    
    void normalize() {
        const float length = this->length();
        m_x /= length;
        m_y /= length;
        m_z /= length;
    }
    
    virtual ~Vec3();
public:
    float m_x,
            m_y,
            m_z;
};

#endif /* VEC3_H */

