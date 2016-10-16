/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Image_impl1.cpp
 * Author: maru
 * 
 * Created on October 10, 2016, 3:34 PM
 */

#include <fstream>
#include <stdio.h>
#include "Output/Image_impl1.h"

Image_impl1::Image_impl1(const uint16_t width, const uint16_t height) : Image(width, height) {
    pixels = std::vector<RGBColour>(m_width * m_height);
}

const RGBColour Image_impl1::getPixelColour(const uint16_t x, const uint16_t y) const {
    return pixels[convertIndex(x,y)];
}

void Image_impl1::setPixelColour(const uint16_t x, const uint16_t y, const RGBColour& colour){
    int index = convertIndex(x,y);
    pixels[convertIndex(x,y)] = colour;
    int a = 2;
}

const bool Image_impl1::save(const std::string& outputFile) const {
    const int image_size = m_height * m_width * 4;
    const int headers_size = 14 + 40;
    const int filesize = image_size + headers_size;
    const int pixelsPerMeter = 2835;
    
    unsigned char bmpfileheader[14] = {'B','M', 0,0,0,0, 0,0,0,0, 54,0,0,0};
    //size of the file in bytes
    bmpfileheader[ 2] = (unsigned char)(filesize);
    bmpfileheader[ 3] = (unsigned char)(filesize>>8);
    bmpfileheader[ 4] = (unsigned char)(filesize>>16);
    bmpfileheader[ 5] = (unsigned char)(filesize>>24);
            
    unsigned char bmpinfoheader[40] = {40,0,0,0, 0,0,0,0, 0,0,0,0, 1,0,24,0};
    //width of the image in bytes
    bmpinfoheader[ 4] = (unsigned char)(m_width);
    bmpinfoheader[ 5] = (unsigned char)(m_width>>8);
    bmpinfoheader[ 6] = (unsigned char)(m_width>>16);
    bmpinfoheader[ 7] = (unsigned char)(m_width>>24);
    
    //height of the image in bytes
    bmpinfoheader[ 8] = (unsigned char)(m_height);
    bmpinfoheader[ 9] = (unsigned char)(m_height>>8);
    bmpinfoheader[10] = (unsigned char)(m_height>>16);
    bmpinfoheader[11] = (unsigned char)(m_height>>24);

    // Size image in bytes
    bmpinfoheader[21] = (unsigned char)(image_size);
    bmpinfoheader[22] = (unsigned char)(image_size>>8);
    bmpinfoheader[23] = (unsigned char)(image_size>>16);
    bmpinfoheader[24] = (unsigned char)(image_size>>24);

    bmpinfoheader[25] = (unsigned char)(pixelsPerMeter);
    bmpinfoheader[26] = (unsigned char)(pixelsPerMeter>>8);
    bmpinfoheader[27] = (unsigned char)(pixelsPerMeter>>16);
    bmpinfoheader[28] = (unsigned char)(pixelsPerMeter>>24);

    bmpinfoheader[29] = (unsigned char)(pixelsPerMeter);
    bmpinfoheader[30] = (unsigned char)(pixelsPerMeter>>8);
    bmpinfoheader[31] = (unsigned char)(pixelsPerMeter>>16);
    bmpinfoheader[32] = (unsigned char)(pixelsPerMeter>>24);

    FILE *file = fopen(outputFile.c_str(), "wb");//write-binary
    
    fwrite(bmpfileheader,1,14, file);
    fwrite(bmpinfoheader,1,40, file);
    
    for (int i = 0; i < pixels.size(); ++i){
        const RGBColour pixel = pixels[i];
        unsigned char color[3] = {
            (int) pixel.b(), 
            (int) pixel.g(), 
            (int) pixel.r()
        };
        fwrite(color, 1, 3, file);
    }
    fclose(file);
    return true;
}

Image_impl1::~Image_impl1() {
    pixels.clear();
}


const uint32_t Image_impl1::convertIndex(const uint16_t x, const uint16_t y) const{
    return (y * m_width) + x;
}
