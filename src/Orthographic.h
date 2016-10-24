/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Ortographic.h
 * Author: maru
 *
 * Created on October 24, 2016, 11:59 AM
 */

#ifndef ORTOGRAPHIC_H
#define ORTOGRAPHIC_H

#include "Camera.h"

class Orthographic: public Camera{
    public:
        Orthographic();
        Orthographic(const Point3D eye, const Point3D lookat);
        ~Orthographic();
        
        virtual Vector3D calculate_ray_dir(const Point2D& p) override;
        virtual Point3D calculate_ray_origin(const Point2D& p) override;

        virtual void render_scene(World *world) override;
};


#endif /* ORTOGRAPHIC_H */

