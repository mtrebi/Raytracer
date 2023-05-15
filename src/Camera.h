/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   Camera.h
 * Author: maru
 *
 * Created on October 24, 2016, 11:58 AM
 */

#ifndef CAMERA_H
#define CAMERA_H

#include "Point3D.h"
#include "Vector3D.h"
#include "World.h"

class Camera{
protected:
    Point3D m_eye;
    Point3D m_lookat;
    Vector3D m_up, m_u, m_v, m_w;
    float m_distance_view_plane;

public:
    Camera();
    Camera(const Point3D& eye, const Point3D& lookat, const float distance);
    ~Camera();

    virtual Vector3D calculate_ray_dir(const Point2D& p) = 0;
    virtual void render_scene(World *world) = 0;
private:
};

#endif /* CAMERA_H */

