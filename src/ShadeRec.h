#ifndef __SHADE_REC__
#define __SHADE_REC__


// 	Copyright (C) Kevin Suffern 2000-2007.
//	This C++ code is for non-commercial purposes only.
//	This C++ code is licensed under the GNU General Public License Version 2.
//	See the file COPYING.txt for the full license.


// We can use forward references for Material and World because they are a pointer and a reference

class Material;
class World;

// We need the following as #includes instead of forward class declarations,
// because we have the objects themselves, not pointers or references to them

#include "Point3D.h"
#include "Normal.h"
#include "Ray.h"
#include "RGBColor.h"
#include "GeometryObject.h"
class GeometryObject;
struct ShadeRec {
    bool hit;
    Material* material_ptr;
    Point3D hit_point;
    Normal hit_normal;
    Ray ray;
    World* world_ptr;
    GeometryObject* obj_ptr;
};

#endif
