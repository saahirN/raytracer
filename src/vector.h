#ifndef VECTOR_H
#define VECTOR_H

#include <cmath>

class Vector {
    public:

        double v[3]; 

        Vector() : v{0, 0, 0} {}; 
        Vector(double x, double y, double z) : v{x, y, z} {}; 

        /* Operators overloaded with vector operations */ 

        Vector operator+(const Vector& other) const {
            return Vector(v[0] + other.v[0], v[1] + other.v[1], v[2] + other.v[2]); 
        }   

        Vector operator-() const {
            return Vector(-v[0], -v[1], -v[2]); 
        }

        Vector operator-(const Vector& other) const {
            return Vector(v[0] - other.v[0], v[1] - other.v[1], v[2] - other.v[2]); 
        }

        Vector operator*(double scalar) const {
            return Vector(scalar * v[0], scalar * v[1], scalar * v[2]); 
        }

        Vector operator/(double scalar) const {
            return Vector(v[0] / scalar, v[1] / scalar, v[2] / scalar); 
        }

        /* Other simple methods */

        double x() const { 
            return v[0]; 
        }

        double y() const { 
            return v[1];
        }
 
        double z() const { 
            return v[2]; 
        }

        double len() const {
            return std::sqrt(v[0]*v[0] + v[1]*v[1] + v[2]*v[2]); 
        }

        Vector normalize() const {
            double l = len(); 
            return Vector(v[0]/l, v[1]/l, v[2]/l); 
        }

        double dot(const Vector& other) const {
            return v[0] * other.v[0] + v[1] * other.v[1] + v[2] * other.v[2]; 
        }

        Vector cross(const Vector& other) const {
            return Vector(v[1]*other.v[2] - v[2]*other.v[1], v[2]*other.v[0] - v[0]*other.v[2], v[0]*other.v[1] - v[1]*other.v[0]); 
        }
}; 

#endif