/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Regular.h
 * Author: maru
 *
 * Created on October 24, 2016, 9:34 AM
 */

#ifndef REGULAR_H
#define REGULAR_H

class Regular : public Sampler {
    public:
        Regular();
        Regular(const int num_samples, const int num_sets = 1);

        ~Regular();
        
        virtual void generate_samples() override;
};


#endif /* REGULAR_H */

