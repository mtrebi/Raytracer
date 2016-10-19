#include "Objects/Shapes/Plane.h"
#include <limits>

bool PointInRectangle( const Vec3& m, const Vec3& a, const Vec3& b, const Vec3& c, const Vec3& d){
    const Vec3 AM = m - a;
    const Vec3 AB = b - a;
    const Vec3 AC = c - a   ;

    bool b1 = (0 < Vec3::dot(AM, AB) && Vec3::dot(AM, AB) < Vec3::dot(AB, AB));
    bool b2 = (0 < Vec3::dot(AM, AC) && Vec3::dot(AM, AC) < Vec3::dot(AC, AC));
    return  b1 && b2;
}

Plane::Plane(){
    m_normal = Vec3();
    m_size = 0;

}

Plane::Plane(const Vec3& location, const RGBColour& colour, const Vec3& normal, const float size)
    : Shape(location, colour) {
    Vec3 origin = Vec3(0,0,0);
    m_normal = normal;
    m_size = size;
       
    if (normal.m_x != 0){
        m_a = Vec3(m_location.m_x, 1* (m_location.m_y + 0.5*m_size), 1* (m_location.m_z + 0.5*m_size));
        m_b = Vec3(m_location.m_x, -1* (m_location.m_y + 0.5*m_size), 1* (m_location.m_z + 0.5*m_size));
        m_c = Vec3(m_location.m_x, 1* (m_location.m_y + 0.5*m_size), -1* (m_location.m_z + 0.5*m_size));
        m_d = Vec3(m_location.m_x, -1* (m_location.m_y + 0.5*m_size), -1* (m_location.m_z + 0.5*m_size));
    }else if (normal.m_y != 0){
        m_a = Vec3(1* (m_location.m_x + 0.5*m_size),m_location.m_y, 1* (m_location.m_z + 0.5*m_size));
        m_b = Vec3(-1* (m_location.m_x + 0.5*m_size),m_location.m_y, 1* (m_location.m_z + 0.5*m_size));
        m_c = Vec3(1* (m_location.m_x + 0.5*m_size),m_location.m_y, -1* (m_location.m_z + 0.5*m_size));
        m_d = Vec3(-1* (m_location.m_x + 0.5*m_size),m_location.m_y, -1* (m_location.m_z + 0.5*m_size));
    }else if (normal.m_z != 0){
        m_a = Vec3(1* (m_location.m_x + 0.5*m_size), 1* (m_location.m_y + 0.5*m_size),m_location.m_z);
        m_b = Vec3(-1* (m_location.m_x + 0.5*m_size), 1* (m_location.m_y + 0.5*m_size),m_location.m_z);
        m_c = Vec3(1* (m_location.m_x + 0.5*m_size),-1* (m_location.m_y + 0.5*m_size),m_location.m_z);
        m_d = Vec3(-1* (m_location.m_x + 0.5*m_size),-1* (m_location.m_y + 0.5*m_size),m_location.m_z);
    }
    
}

Plane::~Plane(){
    m_normal = Vec3();
    m_size = 0;
}

bool Plane::intersect(IntersectionInfo &outInfo, const Ray& ray) const{      
    
    const float nDotA = m_normal.dot(ray.getOrigin());
    const float nDotBA = m_normal.dot(ray.getDirection());
    const float t = (m_location - ray.getOrigin()).dot(m_normal) / nDotBA; 
    const Vec3 hitPoint = ray.getOrigin() + t * ray.getDirection();
            float d = hitPoint.distance(m_location);

    if (t >= 0 && PointInRectangle(hitPoint, m_a,m_b,m_c,m_d)){
        outInfo.hit = true;         
        outInfo.hitPoint = hitPoint;
        outInfo.hitDistance = hitPoint.distance(ray.getOrigin());
        outInfo.hitNormal = m_normal;
        outInfo.hitShape = const_cast<Plane* const>(this);
    }else {
        outInfo.hit = false;
        outInfo.hitPoint = Vec3(0,0,0);
        outInfo.hitDistance = 0;
        outInfo.hitNormal = Vec3(0,0,0);
        outInfo.hitShape = nullptr;
    }
    return outInfo.hit;
}
