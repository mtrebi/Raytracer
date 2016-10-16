/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Ray.h
 * Author: maru
 *
 * Created on October 12, 2016, 4:24 PM
 */

#ifndef RAY_H
#define RAY_H

#include <cstdint>
#include "Vec3.h"

class Ray {
public:
    Ray();
    Ray(const Vec3& origin, const Vec3& direction, const uint16_t max_distance = 1000);

    const Vec3& getDirection() const { return m_direction; }
    const Vec3& getOrigin() const { return m_origin; }

    virtual ~Ray();
private:
    Vec3 m_origin;
    Vec3 m_destination;
    Vec3 m_direction;
    Vec3 m_invdirection;
};

#endif /* RAY_H */