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
#include "Objects/Shapes/Plane.h"

#include "Output/Image_impl1.h"
#include "Utils/HSVColour.h"

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
    // Rear cover
    //scene->addShape(new Plane(Vec3(0,0,-30), RGBColour(100,100,100), Vec3(0,0,1), 10));
    // Roof
    scene->addShape(new Plane(Vec3(0,-1,-30), RGBColour(200,200,200), Vec3(0,.1,0.1), 1));


    /*
    scene->addShape(new Sphere(Vec3(3,3,-9), RGBColour(50,50,50), 0.1));
    scene->addShape(new Sphere(Vec3(-3,3,-9), RGBColour(100,100,100), 0.1));
    scene->addShape(new Sphere(Vec3(3,-3,-9), RGBColour(125,125,125), 0.1));
    scene->addShape(new Sphere(Vec3(-3,-3,-9), RGBColour(225,225,225), 0.1));
*/
    
    //scene->addShape(new Sphere(Vec3(0,0,-10), RGBColour(50,50,50), 6));

    //scene->addShape(new Sphere(Vec3(0,0,-5), RGBColour(255,0,0), 0.5)); 

    // floor
    //scene->addShape(new Plane(Vec3(0,0,-10), RGBColour(255,0,0), Vec3(0,1,0), 2))
    // left wall
            
    // right wall
    
    /*
    scene->addShape(new Sphere(Vec3(3,0,-5), RGBColour(255,0,0), 2));
    scene->addShape(new Sphere(Vec3(-3,0,-5), RGBColour(0,0,255), 1.5));
    scene->addShape(new Sphere(Vec3(-2,-2,-7), RGBColour(0,255,0), 1));
    //scene->addShape(new Sphere(Vec3(0,1,-1), RGBColour(0,255,0), .1));
    //scene->addShape(new Sphere(Vec3(1,0,-1), RGBColour(0,0,255), .1));

    scene->addShape(new Sphere(Vec3(1,104,-1), RGBColour(0,0,0), 100));

    //scene->addShape(new Plane(Vec3(0,0,0), RGBColour(0, 0, 0), Vec3(0, 1, 0), 2));
*/
    scene->addCamera(new Camera(Vec3(0,0,1), 45));
    scene->addLight(new Light(Vec3(5,-10,0), 10));
    std::cout << "Completed" << std::endl;

    std::cout << "Main: Rendering...";    
    const Image& generatedImage = scene->render2d(1920, 1080);
    std::cout << "Completed" << std::endl;

    std::cout << "Main: Saving result in file " << outputFile << "...";    
    generatedImage.save(outputFile);
    std::cout << "Completed" << std::endl; 
}

void test_hsv_rgb_conversion(){
    RGBColour rgb1 = RGBColour(10, 20, 30);
    RGBColour rgb2 = RGBColour(15,15,255);
    RGBColour rgb3 = RGBColour(0,112,135);

    HSVColour hsv1 = HSVColour(rgb1);
    HSVColour hsv2 = HSVColour(rgb2);
    HSVColour hsv3 = HSVColour(rgb3);
    
    RGBColour rgb11 = RGBColour(hsv1);
    RGBColour rgb22 = RGBColour(hsv2);
    RGBColour rgb33 = RGBColour(hsv3);
        
    std::cout << "HSV1" << hsv1 << std::endl;
    std::cout << "HSV2" << hsv2 << std::endl;
    std::cout << "HSV2" << hsv3 << std::endl;

    std::cout << "RGB1" << rgb11 << std::endl;
    std::cout << "RGB2" << rgb22 << std::endl;
    std::cout << "RGB3" << rgb33 << std::endl;
    
    
}

int main(int argc, char** argv) {
    
    //create_image_test("test-image");
    //generate_random_image_test("test-random-image");
    //read_scene_test("scene-input");
    //full_2drender_test("scene-input", "test-image");
    full_2drender_test2("test-image");
    //test_hsv_rgb_conversion();
    return 0;
}

