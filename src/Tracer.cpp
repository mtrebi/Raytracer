/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "Tracer.h"

Tracer::Tracer() : m_world_ptr(nullptr){
    
};

Tracer::Tracer(World* world_ptr) : m_world_ptr(world_ptr) {
    
};