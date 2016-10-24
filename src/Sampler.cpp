/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

# include "Sampler.h"
# include <random>
# include <algorithm>

Sampler::Sampler()
    : m_num_samples(0), m_num_sets(0), m_samples(std::vector<Point2D>()), m_count(0), m_jump(0){
}

Sampler::Sampler(const int num_samples, const int num_sets)
    : m_num_samples(num_samples), m_num_sets(num_sets), m_samples(std::vector<Point2D>()), m_count(0), m_jump(0) {
}


Sampler::~Sampler(){
    
}

const int Sampler::get_n_samples() const{
    return m_num_samples;
}


const Point2D& Sampler::next_sample(){
    if (m_count % m_num_samples == 0){ // New Pixel
        m_jump = rand() % m_num_sets;
    }
    
    return m_samples[m_jump + m_count++ % (m_num_samples * m_num_sets)];
}   