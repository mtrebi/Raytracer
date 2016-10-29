# Raytracer in C++
## Introduction
The goal of this project was to become familiar with C++ and graphics stuff while having fun. It was a really amazing project and I encourage everyone to do it if you like graphics.
My raytracer is quite basic and simple and includes the following features:
* Basic shapes: Planes and Spheres.
* Shadows: Simulate shadows using Shadow Rays to multiple light sources. The shadows can be softer or harder depending on the number of lights that illuminate them.
* Phong illumination model to simulate simulate ambient, colored diffuse and colored specular illumination.
* Mirror reflection: Perfect reflection for mirrors.
* Refreaction: Refraction of light depending on the refraction index of the materials.
* Anti-aliasing: Regular sampling technique.
* Multiple cameras: perspective and orthogonal.
* Easy to extend. I took care to design a system that was easy to modify and extend. Is very to extend any of the previous feature, for example to add another material or another sampling method.

## Architecture



## Raytracer
## Intersections
### Primary rays

### Phong illumination


### Shadow rays

[one light and many lights]

### Reflected rays

### Refracted rays

### Sampling


## Results


## References
I've looked on many websites to help me understand the basics of ray tracing but, I'll only reference the two most important:

* [ScratchAPixel](http://www.scratchapixel.com/index.php#3d-basic-rendering): Explains step by step how to implement and how a raytracer works. Highly recommended.
* [Ray Tracing from the ground up](http://www.raytracegroundup.com/). This book explains EVERYTHING related to raytracing. Sometimes it goes very deep. It is a very nice book and it explains how to implement a ray tracer completely from scratch. It has pseudocode and code to help you. My raytracer is based on the ray tracer explained in the firsts chapters of this book and I use their utils classes (Vectors, Points...).
