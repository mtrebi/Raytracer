/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Sampler.h
 * Author: maru
 *
 * Created on October 24, 2016, 9:31 AM
 */

#ifndef SAMPLER_H
#define SAMPLER_H

# include <vector>
# include "Point2D.h"
//TODO: Index shuffling
class Sampler {
protected:
    int m_num_samples;
    int m_num_sets;
    std::vector<Point2D> m_samples;
    
    int m_count;
    int m_jump;
public:
    Sampler();
    Sampler(const int num_samples, const int num_sets = 5);
    ~Sampler();
    
    const int get_n_samples() const;
    
    const Point2D& next_sample();
    virtual void generate_samples() = 0;    
};

#endif /* SAMPLER_H */

