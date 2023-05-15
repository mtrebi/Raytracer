/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

# include "Chalk.h"


Chalk::Chalk()
        : Phong(){

}

Chalk::Chalk(const RGBColor& c, const float kd, const float ks, const float sp_e, const float lci)
        : Phong(c, ks, ks, sp_e, lci){

}
