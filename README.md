# Raytracer in C++
## Introduction
The goal of this project was to become familiar with C++ and graphics stuff while having fun. It was a really amazing project and I encourage everyone to do it if you like graphics.
My raytracer is quite basic and simple and includes the following features:
* Basic shapes: Planes and Spheres.
* Shadows: Simulate shadows using Shadow Rays to multiple light sources. The shadows can be softer or harder depending on the number of lights that illuminate them.
* Phong illumination model to simulate simulate ambient, colored diffuse and colored specular illumination.
* Mirror reflection: Perfect reflection for mirrors.
* Refraction: Refraction of light depending on the refraction index of the materials.
* Anti-aliasing: Regular sampling technique.
* Multiple cameras: perspective and orthogonal.
* Easy to extend. I took care to design the raytracer folowing the software principles. It is very to modify or extend any of the previous features, for example, to add another material, camera or sampling method.

## Raytracer
### Architecture
### Objects and intersections
The class _GeometryObject_ is a pure virtual class parent of all real objects that can be placed on the World or Scene. This class has a pure virtual method called _hit_ that should be implemented in the derived class. This method is used to check wheter a Ray intersects the object or not and get back the information about the intersection (point, normal...).Any new real object like a Box should inherit from _GeometryObject_ and should implement the _hit_ function.

To calculate the Ray-Plane and Ray-Sphere intersection I've used the implicit surface equations, knowing that the hit point must belong to the Ray and must be on the Surface of the Plane or Sphere.

The Ray-Sphere intersection can also be calculated using the geometric way using cos/sin and the Pythagoras theorem instead of using the surface equation. I believe the geometric way is faster than the analytical.


### Primary rays
A basic raytracer the only thing that it does is throwing rays from an "specific position and direction" through the center of each pixel. Then, the algorithm checks if the ray intersects any of the objects of the scene. If it does, it only retrieves the closest one and gets the color of the hitpoint. This will be the color of the pixel. If the ray doesn't hit any object, we will assign a background color for the pixel.

[flat shading]

This is how a ray tracer works. Now, depending on the camera type, the origin and the direction of the ray may vary, allowing us to generate different kind of images. Here, we are going to focus on the perspective camera because it works very close as our eyes perceive the world.

In a perspective camera, each ray starts at the camera position (determined by different parameters) as goes through the center of each pixel. Thus, each ray has the same origin, but different direction.

[perspective-view]

### Phong illumination

[flat shading vs phong]

### Shadow rays

[one light and many lights]

### Reflected rays

### Refracted rays

### Sampling
To avoid aliasing and increase the quality of the image, I implemented a very simple _Sampler_ virtual class that defines the common functions of the differents samplers, the most obvious one is the pure virtual _GenerateSamples_ function. This function must be implemented by each concrete sampler that we want to add. In my case I created a _Regular_ sampler. Is very basic but it is enough to avoid most of the aliasing of the image and allowing better quaility images.

[image w aliasing] vs [image w/o aliasing]

## Results
In the next image we can see the final result of the Ray Tracer with a 256-Regular Sampler with and all of its features.

[final image with all]

## References
I've looked on many websites to help me understand the basics of ray tracing but, I'll only reference the most important two:

* [ScratchAPixel](http://www.scratchapixel.com/index.php#3d-basic-rendering): Explains step by step how to implement and how a raytracer works. Highly recommended.
* [Ray Tracing from the ground up](http://www.raytracegroundup.com/). This book explains EVERYTHING related to raytracing. Sometimes it goes very deep. It is a very nice book and it explains how to implement a ray tracer completely from scratch. It has pseudocode and code to help you. My raytracer is based on the ray tracer explained in the firsts chapters of this book and I use their utils classes (Vectors, Points...).
