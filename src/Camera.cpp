/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

# include "Camera.h"

Camera::Camera(){

}

Camera::Camera(const Point3D& eye, const Point3D& lookat, const float distance)
    : m_eye(eye), m_lookat(lookat), m_distance_view_plane(distance){

    m_up = Vector3D(0,1,0);
    m_w = (eye - lookat);
    m_w.normalize();
    m_u = m_up ^ m_w;
    m_u.normalize();
    m_v = m_w ^ m_u;
}

Camera::~Camera(){

}
