#include "vector.h"
#include "ray.h"
#include <iostream>

using Color = Vector; 

bool hitSphere(const Vector& center, double radius, const Ray& r) {
    Vector originToCenter = center - r.origin;
    double a = r.direction.len();  
    double b = -2.0 * r.direction.dot(originToCenter); 
    double c = originToCenter.len() - radius*radius;
    double discriminant = b*b - 4*a*c; 
    return discriminant >= 0; 
}

Color rayColor(const Ray& r) {
    if(hitSphere(Vector(0, 0, -1), 0.5, r)) {
        return Color(255, 0, 0); 
    }   
    double a = 0.5 * (r.direction.y() + 1.0); 
    return Color(255, 255, 255)*(1.0-a) + Color(128, 179, 255)*a; 
}

/* Print out color values */
void printColor(Color c) {
    std::cout << c.x() << ' ' << c.y() << ' ' << c.z() << '\n'; 
 }

int main() {

    /* Image Parameters */
    double aspectRatio = 16.0 / 9.0; 
    int width = 256; 
    int height = width / aspectRatio;
    height = height >= 1 ? height : 1; 

    /* Camera Parameters */
    double viewportHeight = 2.0;
    double viewportWidth = viewportHeight * (double(width) / height); 
    double focalLength = 1.0;
    Vector camera = Vector(); 

    /* Viewport Vectors */
    Vector u = Vector(viewportWidth, 0, 0); 
    Vector v = Vector(0, -viewportHeight, 0); 
    Vector deltaU = u / width;
    Vector delatV = v / height; 
    Vector upperLeft = camera - Vector(0, 0, focalLength) - u/2 - v/2; 
    Vector upperLeftPixel = upperLeft + (deltaU + delatV) * 0.5; 
    // std::cout << "UpperLeft: " << upperLeftPixel.x() << ' ' << upperLeftPixel.y() << ' ' << upperLeftPixel.z() << '\n'; 


    /* Rendering Loop */
    std::cout << "P3\n" << width << ' ' << height << "\n255\n"; 
    for(int i = 0; i < height; i++) {
        for(int j = 0; j < width; j++) {
            Vector pixel = upperLeftPixel + (delatV * i) +  (deltaU * j); 
            Vector direction = (pixel - camera).normalize(); 
            Ray r = Ray(camera, direction); 
            Color c = rayColor(r); 
            printColor(c); 
        }
    }

    std::clog << "Done\n"; 
}