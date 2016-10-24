/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

# include "Regular.h"
# include <math.h>

Regular::Regular()
    : Sampler() {
    generate_samples();
}
Regular::Regular(const int num_samples, const int num_sets)
    : Sampler(num_samples, num_sets){
    generate_samples();
}

void Regular::generate_samples() {
    const float n = sqrt(m_num_samples);
    for (int s = 0; s < m_num_sets; ++s){
        for (int x = 0; x < n; ++x){
            for (int y = 0; y < n; ++y){
                const Point2D new_sample = Point2D(x/n,y/n);
                m_samples.push_back(new_sample);
            }
        }
    }
}
