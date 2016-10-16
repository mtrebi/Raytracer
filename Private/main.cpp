/* 
 * File:   main.cpp
 * Author: maru
 *
 * Created on October 10, 2016, 2:40 PM
 */
#include <iostream>
#include <cstdlib>
#include <string>
#include <ctime>
#include "Scene.h"
#include "Objects/Shapes/Sphere.h"
#include "Output/Image_impl1.h"

void create_image_test(const std::string &name){
    std::cout << "Main: Creating image..." ;
    const Image* newImage = new Image_impl1(256,256);
    if (newImage->save(name)){
        std::cout << "Completed" << std::endl;
    }else {
        std::cout << "Error" << std::endl;
    }
}
#include <stdlib.h>
void generate_random_image_test(const std::string &filename){
     std::cout << "Main: Creating image..." ;
    Image* newImage = new Image_impl1(256,256);
    for (int x = 0; x < 256; ++x){
        for (int y = 0; y < 256; ++y){
            if (rand() % 2){
                newImage->setPixelColour(x,y,RGBColour(122,122,122));
            }
        }
    }
    if (newImage->save(filename)){
        std::cout << "Completed" << std::endl;
    }else {
        std::cout << "Error" << std::endl;
    }
}

void read_scene_test(const std::string &filename){
    std::cout << "Main: Reading scene..." ;
    Scene scene = Scene(filename);
    std::cout << "Completed" << std::endl;

    std::cout << "Main: Printing scene..." << std::endl;
    std::cout << scene << std::endl;
}

void full_2drender_test(const std::string inputFile, const std::string outputFile){
    std::cout << "Main: Reading Scene file from " << inputFile << "..." ;
    const Scene* scene = new Scene(inputFile);
    std::cout << "Completed" << std::endl;

    std::cout << "Main: Rendering...";    
    const Image& generatedImage = scene->render2d(640, 480);
    std::cout << "Completed" << std::endl;

    std::cout << "Main: Saving result in file " << outputFile << "...";    
    generatedImage.save(outputFile);
    std::cout << "Completed" << std::endl; 
}

void full_2drender_test2(const std::string outputFile){
    std::cout << "Main: Generating scene..." ;
    Scene* scene = new Scene();
    scene->addShape(new Sphere(Vec3(3,0,-10), RGBColour(125,25,125), 2));
    scene->addShape(new Sphere(Vec3(0,0,-5), RGBColour(10,130,150), 2));
    scene->addCamera(new Camera(Vec3(0,0,1), 90));
    scene->addLight(new Light(Vec3(0,10,0), 10));
    std::cout << "Completed" << std::endl;

    std::cout << "Main: Rendering...";    
    const Image& generatedImage = scene->render2d(640, 480);
    std::cout << "Completed" << std::endl;

    std::cout << "Main: Saving result in file " << outputFile << "...";    
    generatedImage.save(outputFile);
    std::cout << "Completed" << std::endl; 
}


int main(int argc, char** argv) {
    
    //create_image_test("test-image");
    //generate_random_image_test("test-random-image");
    //read_scene_test("scene-input");
    //full_2drender_test("scene-input", "test-image");
    full_2drender_test2("test-image");

    return 0;
}

