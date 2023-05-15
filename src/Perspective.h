/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   Perspective.h
 * Author: maru
 *
 * Created on October 24, 2016, 11:59 AM
 */

#ifndef PERSPECTIVE_H
#define PERSPECTIVE_H

#include "Camera.h"

class Perspective: public Camera{
    public:
        Perspective();
        Perspective(const Point3D& eye, const Point3D& lookat, const float distance);
        ~Perspective();

        virtual Vector3D calculate_ray_dir(const Point2D& p) override;
        virtual void render_scene(World *world) override;
};


#endif /* PERSPECTIVE_H */

