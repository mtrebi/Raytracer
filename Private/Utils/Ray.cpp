/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Ray.cpp
 * Author: maru
 * 
 * Created on October 12, 2016, 4:24 PM
 */

#include "Utils/Ray.h"
#include <typeinfo>       // std::bad_cast



Ray::Ray() {
}

Ray::Ray(const Vec3& origin, const Vec3& direction, const uint16_t max_distance){
    m_origin = origin;
    m_direction = direction;
    m_destination = origin + direction * max_distance;
}

/*
int GetIntersection( float fDst1, float fDst2, const Vec3 & P1, const Vec3& P2, Vec3 &Hit) {
    if ( (fDst1 * fDst2) >= 0.0f) return 0;
    if ( fDst1 == fDst2) return 0; 
    Hit = P1 + (P2-P1) * ( -fDst1/(fDst2-fDst1) );
    return 1;
}

int InBox(const Vec3& Hit, const Vec3& B1, const Vec3& B2, const int Axis) {
    if ( Axis==1 && Hit.m_z > B1.m_z && Hit.m_z < B2.m_z && Hit.m_y > B1.m_y && Hit.m_y < B2.m_y) return 1;
    if ( Axis==2 && Hit.m_z > B1.m_z && Hit.m_z < B2.m_z && Hit.m_x > B1.m_x && Hit.m_x < B2.m_x) return 1;
    if ( Axis==3 && Hit.m_x > B1.m_x && Hit.m_x < B2.m_x && Hit.m_y > B1.m_y && Hit.m_y < B2.m_y) return 1;
    return 0;
}

// returns true if line (L1, L2) intersects with the box (B1, B2)
// returns intersection point in Hit
int CheckLineBox(const Vec3& B1, const Vec3& B2, const Vec3& L1, const Vec3& L2, Vec3 &Hit){
    if (L2.m_x < B1.m_x && L1.m_x < B1.m_x) return false;
    if (L2.m_x > B2.m_x && L1.m_x > B2.m_x) return false;
    if (L2.m_y < B1.m_y && L1.m_y < B1.m_y) return false;
    if (L2.m_y > B2.m_y && L1.m_y > B2.m_y) return false;
    if (L2.m_z < B1.m_z && L1.m_z < B1.m_z) return false;
    if (L2.m_z > B2.m_z && L1.m_z > B2.m_z) return false;
    if (L1.m_x > B1.m_x && L1.m_x < B2.m_x &&
        L1.m_y > B1.m_y && L1.m_y < B2.m_y &&
        L1.m_z > B1.m_z && L1.m_z < B2.m_z) {
        Hit = L1; 
        return true;
    }
    if ( (GetIntersection( L1.m_x-B1.m_x, L2.m_x-B1.m_x, L1, L2, Hit) && InBox( Hit, B1, B2, 1 ))
      || (GetIntersection( L1.m_y-B1.m_y, L2.m_y-B1.m_y, L1, L2, Hit) && InBox( Hit, B1, B2, 2 )) 
      || (GetIntersection( L1.m_z-B1.m_z, L2.m_z-B1.m_z, L1, L2, Hit) && InBox( Hit, B1, B2, 3 )) 
      || (GetIntersection( L1.m_x-B2.m_x, L2.m_x-B2.m_x, L1, L2, Hit) && InBox( Hit, B1, B2, 1 )) 
      || (GetIntersection( L1.m_y-B2.m_y, L2.m_y-B2.m_y, L1, L2, Hit) && InBox( Hit, B1, B2, 2 )) 
      || (GetIntersection( L1.m_z-B2.m_z, L2.m_z-B2.m_z, L1, L2, Hit) && InBox( Hit, B1, B2, 3 ))){
        return true;
    }
    return false;
}
*/
/*
const bool Ray::intersect(IntersectionInfo& outInfo, const Box& box) const {
    Vec3 hitPoint;
    const bool hit = CheckLineBox(box.getBoundsMin(), box.getBoundsMax(), m_origin, m_destination, hitPoint);
    if (hit){
        outInfo.hit = hit;
        outInfo.hitPoint = hitPoint;
        outInfo.hitDistance = m_origin.distance(hitPoint);
        outInfo.hitShape = box;
        //outInfo.hitNormal;
    }else {
        outInfo.hit = hit;
    }
    
    return hit;
    
    /*
    const Vec3 invdir = 1 / m_direction;
    
    float tmin, tmax;
    if (invdir.m_x >= 0) { 
        tmin = (box.getBoundsMin().m_x - m_origin.m_x) * invdir.m_x; 
        tmax = (box.getBoundsMax().m_x - m_origin.m_x) * invdir.m_x; 
    } 
    else { 
        tmin = (box.getBoundsMax().m_x - m_origin.m_x) * invdir.m_x; 
        tmax = (box.getBoundsMin().m_x - m_origin.m_x) * invdir.m_x; 
    } 
    float tymin, tymax;
    if (invdir.m_y >= 0) { 
        tymin = (box.getBoundsMin().m_y - m_origin.m_y) * invdir.m_y; 
        tymax = (box.getBoundsMax().m_y - m_origin.m_y) * invdir.m_y; 
    } 
    else { 
        tymin = (box.getBoundsMax().m_y - m_origin.m_y) * invdir.m_y; 
        tymax = (box.getBoundsMin().m_y - m_origin.m_y) * invdir.m_y; 
    } 
    
    if ((tmin > tymax) || (tymin > tmax)) 
        return false; 
    if (tymin > tmin) 
        tmin = tymin; 
    if (tymax < tmax) 
        tmax = tymax; 

    float tzmin, tzmax;
    if (invdir.m_z >= 0) { 
        tzmin = (box.getBoundsMin().m_z - m_origin.m_z) * invdir.m_z; 
        tzmax = (box.getBoundsMax().m_z - m_origin.m_z) * invdir.m_z; 
    } 
    else { 
        tzmin = (box.getBoundsMax().m_z - m_origin.m_z) * invdir.m_z; 
        tzmax = (box.getBoundsMin().m_z - m_origin.m_z) * invdir.m_z; 
    } 
    
    if ((tmin > tzmax) || (tzmin > tmax)) 
        return false; 
    if (tzmin > tmin) 
        tmin = tzmin; 
    if (tzmax < tmax) 
        tmax = tzmax; 
    
    outInfo.hitShape = box;
    return true; 

     */


Ray::~Ray() {
}
