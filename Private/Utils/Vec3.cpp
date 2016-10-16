/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Point3.cpp
 * Author: maru
 * 
 * Created on October 10, 2016, 2:51 PM
 */

#include "Utils/Vec3.h"
Vec3::Vec3(){
    
}

Vec3::Vec3(const float x, const float y, const float z){
    m_x = x;
    m_y = y;
    m_z = z;    
}

Vec3::~Vec3() {
    m_x = 0;
    m_y = 0;
    m_z = 0;
}

std::istream& operator >> (std::istream& is, Vec3& vec3){
    is >> vec3.m_x >> vec3.m_y >> vec3.m_z;
}
std::ostream& operator << (std::ostream& os, Vec3& vec3){
    os << "VECTOR(" << vec3.m_x << ", " << vec3.m_y << ", " << vec3.m_z << ") " ;
}

const float Vec3::distance (Vec3& vec3) const {
    return sqrt(pow((m_x - vec3.m_x), 2) +
           pow((m_y - vec3.m_y), 2) +
           pow((m_z - vec3.m_z), 2));
}
    
const float Vec3::length() const {
    return sqrt(m_x * m_x +
           m_y * m_y +
           m_z * m_z);
}

const float Vec3::dot(const Vec3& v1, const Vec3& v2) {
    return v1.dot(v2);
}
    
const float Vec3::dot(const Vec3& v1) const {
    return v1.m_x * m_x + v1.m_y * m_y + v1.m_z * m_z;
}

Vec3 operator- (const Vec3& v1, const Vec3& v2){
    return Vec3(v1.m_x - v2.m_x,
                v1.m_y - v2.m_y,
                v1.m_z - v2.m_z);
}

Vec3 operator+ (const Vec3& v1, const Vec3& v2){
    return Vec3(v1.m_x + v2.m_x,
                v1.m_y + v2.m_y,
                v1.m_z + v2.m_z);    
}

Vec3 operator* (const Vec3& v1, const int i){
    return Vec3(v1.m_x * i,
                v1.m_y * i,
                v1.m_z * i);
}

Vec3 operator/ (const Vec3& v, const int i){
    return Vec3(v.m_x / i,
                v.m_y / i,
                v.m_z / i);
}

Vec3 operator/ (const int i, const Vec3& v){
    return Vec3(i / v.m_x,
                i / v.m_y,
                i / v.m_z);
}

Vec3 operator* (const int i, const Vec3& v1){
    return v1 * i;
}

bool operator== (const Vec3& v1, const Vec3& v2){
    return (v1.m_x == v2.m_x && v1.m_y == v2.m_y && v1.m_z == v2.m_z);
}

bool operator!= (const Vec3& v1, const Vec3& v2){
    return !(v1 == v2);
}

bool operator< (const Vec3& v1, const Vec3& v2){
    return (v1.length() < v2.length());
}

bool operator<= (const Vec3& v1, const Vec3& v2){
    return (v1.length() <= v2.length());
}

bool operator> (const Vec3& v1, const Vec3& v2){
    return (v1.length() > v2.length());
}
bool operator>= (const Vec3& v1, const Vec3& v2){
    return (v1.length() >= v2.length());
}   

Vec3 operator/ (const Vec3& v1, const Vec3& v2){
    return Vec3(v1.m_x / v2.m_x,
                v1.m_y / v2.m_y,
                v1.m_z / v2.m_z);   }
