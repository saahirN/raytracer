#ifndef RAY_H
#define RAY_H

#include "vector.h"

class Ray {
    public:
    
        Vector origin; 
        Vector direction; 

        Ray(const Vector& orig, const Vector& dir) : origin(orig), direction(dir) {};

        Vector pointAtDist(double dist) {
            return origin + (direction * dist); 
        }
};

#endif