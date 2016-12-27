<a href='http://www.recurse.com' title='Made with love at the Recurse Center'><img src='https://cloud.githubusercontent.com/assets/2883345/11325206/336ea5f4-9150-11e5-9e90-d86ad31993d8.png' height='20px'/></a>
# Raytracer in C++
## Introduction
The goal of this project was to become familiar with C++ and graphics stuff while having fun. It was a really amazing project and I encourage everyone to do it if you like graphics.
My raytracer is a backwards raytracer. Is quite basic and simple and includes the following features:
* Basic shapes: Planes and Spheres.
* Shadows: Simulate shadows using Shadow Rays to multiple light sources. The shadows can be softer or harder depending on the number of lights that illuminate them.
* Phong illumination model to simulate simulate ambient, colored diffuse and colored specular illumination.
* Mirror reflection: Perfect reflection for mirrors.
* Refraction: Refraction of light depending on the refraction index of the materials.
* Anti-aliasing: Regular sampling technique.
* Multiple cameras: perspective and orthogonal.
* Easy to extend. I took care to design the raytracer folowing the software principles. It is very to modify or extend any of the previous features, for example, to add another material, camera or sampling method.

## Raytracer
### Dependency diagram
Here is a simple dependency diagram of the World class. 

![Dependency diagram](https://github.com/mtrebi/Raytracer/blob/master/images/class_diagram.png "Simple dependency diagram")

Each of its dependencies (except ViewPlane) are pure virtual classes that define a set of functions that should be implemented by the subclasses. This way, the system is decoupled and can be easily modified to, add another _Tracer_, _Sampler_ or _GeometryObject_.For further details look at the code, it is very easy to understand.


### Objects and intersections
The class _GeometryObject_ is a pure virtual class parent of all real objects that can be placed on the World or Scene. This class has a pure virtual method called _hit_ that should be implemented in the derived class. This method is used to check wheter a Ray intersects the object or not and get back the information about the intersection (point, normal...).Any new real object like a Box should inherit from _GeometryObject_ and should implement the _hit_ function.

To calculate the Ray-Plane and Ray-Sphere intersection I've used the implicit surface equations, knowing that the hit point must belong to the Ray and must be on the Surface of the Plane or Sphere.

The Ray-Sphere intersection can also be calculated using the geometric way using cos/sin and the Pythagoras theorem instead of using the surface equation. I believe the geometric way is faster than the analytical.


### Primary rays
A basic (backwards) raytracer the only thing that it does is throwing rays from an "specific position and direction" through the center of each pixel. Then, the algorithm checks if the ray intersects any of the objects of the scene. If it does, it only retrieves the closest one and gets the color of the hitpoint. This will be the color of the pixel. If the ray doesn't hit any object, we will assign a background color for the pixel.
This is the result:
![Flat shading](https://github.com/mtrebi/Raytracer/blob/master/images/flat-shading.bmp "Flat shading example")

This is how a ray tracer works. Now, depending on the camera type, the origin and the direction of the ray may vary, allowing us to generate different kind of images. Here, we are going to focus on the perspective camera because it works very close as our eyes perceive the world.

In a perspective camera, each ray starts at the camera position (determined by different parameters) and goes through the center of each pixel. Thus, each ray has the same origin, but different direction.

### Phong illumination
If we only use basic ray tracing the image doesn't look real. We only got the colors and the shape of the objects. To create a more realistic image, we are going to use the [Phong equation](https://en.wikipedia.org/wiki/Phong_shading). With this equation we can shade the original color of the object depending on several parameters (view angle, normal of the surface, number of lights, and so on). I am not going to focus on the Phong equation here because it is very well explained in other places. I'll simply say that there is:
* Ambient component: Simulates the global light on the scene. It is a constant.
* Diffuse component: Simulates the reflected light in all directions on a surface depending on the angle of incidence of the light on the surface (see [Lambertian reflectance](https://en.wikipedia.org/wiki/Lambertian_reflectance))
* Specular component: Simulates the reflected light in an specific direction (the view direction) given the incidince of the light on the surface. 

Ambient and diffuse components:

![Phong - ambient and diffuse components](https://github.com/mtrebi/Raytracer/blob/master/images/phong-diffuse.bmp "Ambient and diffuse components of Phong shading")

Ambient and specular components:

![Phong - ambient and specular components](https://github.com/mtrebi/Raytracer/blob/master/images/phong-specular.bmp "Ambient and specular components of Phong shading")

Phong complete:

![Phong with all components](https://github.com/mtrebi/Raytracer/blob/master/images/phong-complete.bmp "Phong shading with all components")

*Note: As you can see, Phong shading is not physically realistic but it is a good first approach to shade the colors*

#### Extra
To create an even better image I made some changes on the Phong equation:
The first change was to clamp to zero negative values of dot product operations.
There is an extra parameter in my phong equation that indicated how much the light's color should dominate over the object color. A high value will cause the object to be colored by the light color. On the contrary, the object will be just brighter but its base color won't be modified. In the next image we can see only the color transfered to the object from a red light:

![Color transfer from a red light](https://github.com/mtrebi/Raytracer/blob/master/images/color_transfer.PNG "Color transfer from a red light")

If we apply the previous phong equation with the campled dot product and the color transfer from lights this is the result:

![Phong with an extra parameter](https://github.com/mtrebi/Raytracer/blob/master/images/phong-new-parameter.bmp "Phong with an extra parameter")

I added an attenuator value for the lights based on distance. Objects farther from the light receive less light. This is very subtle but it improves the final result:

![Light attenuatted by distance](https://github.com/mtrebi/Raytracer/blob/master/images/light-attenuatted.bmp "Light attenuatted by distance")

### Shadow rays
An image won't be realistic without hard shadows. A hard shadow is an area which doesn't receive direct light from the light sources. So, to add shadows, the simply thing that we do is, once the primary ray hit an object, we throw another ray (called shadow ray) from that position to the light sources. If the shadow ray can't reach any of the lights, it means that this area should be shadowed. Is that simple.

![Hard shadows with multiple light sources](https://github.com/mtrebi/Raytracer/blob/master/images/hard-shadows.bmp "Hard shadows with multiple light sources")

*Note: Do you remember that I said that this was a backwards ray tracer? Here is the reason. In the real world, the light throws photons in all directions and only a part of them impact in our eyes. Because, doing this is very expensive, what we do is the opposite. We throw rays from our eyes (the camera) to the objects, and then from the objects to the lights to ensure that they are visible.*

#### Extra
When we have multiple lights, objects have multiple shadows. One (like) soft-shadow per light and a harder-shadow when the soft-shadows intersect. To simulate this, I modified the shadow rays in order to count, how many lights of the scene lighted each position and then I applied a shadow proportionally to these number of lights.

![Hard and soft shadows with multiple light sources](https://github.com/mtrebi/Raytracer/blob/master/images/hard-soft-shadows.bmp "Hard and soft shadows with multiple light sources")

### Reflected rays
Reflected rays are needed to implement mirrors. Their behavior is very simple. When the primary ray hits the surface of a mirror, you have to calculate the [reflected direction](https://en.wikipedia.org/wiki/Reflection_(physics)) (It is pure physics). Once you have it, you just throw a secondary ray with the origin where the primary ray hit and with the reflected direction. Then, you follow the same process as you did with the primary ray (in fact, the ray function that I used is the same). If the ray hits something, you get its color, otherwhise, background color.

![Mirror reflection](https://github.com/mtrebi/Raytracer/blob/master/images/reflected-mirror.bmp "Mirror reflection")

### Refracted rays
The process to implement refracted rays work is similar to the previous process but more complex. When the primary ray this the surface of the material, you have to calculate the new direction of the ray given the [refraction index](https://en.wikipedia.org/wiki/Refraction) of the previous and new material. Then, you create a new ray from the surface hitpoint with the direction determined by the refraction index. This ray will travel through the interior of the material until it will hit the surface of the material. When this happens, you have to create a new ray that starts on this hitpoint and its direction its determined, as before, by the refractions indices. Finally, this ray is treated as a primary ray. If it hits something, you get its color, otherwise, background color.

![Water refraction example](https://github.com/mtrebi/Raytracer/blob/master/images/final-alising.bmp "Water refraction example")

### Sampling
One way to avoid aliasing is to implement sampling techniques. Sampling just means that instead of getting one sample per pixel (its center) we get many. Depending on the sampler, this could be distributed in a grid, randomly or even randomly in a grid. Then, for each sample we throw a ray and we get back the color and the final color of the pixel is the average of all the samples.

For my RayTracer I implemented a very simple virtual class _Sampler_ that defines the common functions of the differents samplers, the most obvious one is the pure virtual _GenerateSamples_ function. This function must be implemented by each concrete sampler that we want to add. In my case I created a _Regular_ sampler. Is very basic but it is enough to avoid most of the aliasing of the image and allowing better quaility images.

This is the final image of my Ray Tracer with all its features and 256 samples per pixel:

![Image with regular samplingh with 256 samples](https://github.com/mtrebi/Raytracer/blob/master/images/final-256-sampling.bmp "Image with regular samplingh with 256 samples]")

## Future work
* Real time raytracing (GPU)
* Shadows and penumbra (using light sampling)
* Depth of field
* Caustics
* Path Tracing with multiples bounces and  Russian Roulette (Montecarlo technique)

## References
I've looked on many websites to help me understand the basics of ray tracing but, I'll only reference the most important two:

* [ScratchAPixel](http://www.scratchapixel.com/index.php#3d-basic-rendering): Explains step by step how to implement and how a raytracer works. Highly recommended.
* [Ray Tracing from the ground up](http://www.raytracegroundup.com/). This book explains EVERYTHING related to raytracing. Sometimes it goes very deep. It is a very nice book and it explains how to implement a ray tracer completely from scratch. It has pseudocode and code to help you. My raytracer is based on the ray tracer explained in the firsts chapters of this book and I use their utils classes (Vectors, Points...).
