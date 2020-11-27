#include "Unit_vector.h"
#include "Vector3d.h"

#include <iostream>

Unit_vector::Unit_vector() {
    this->x = 1;
    this->y = 0;
    this->z = 0;
}
        
Unit_vector::Unit_vector(double x, double y, double z) : Vector3d(x, y, z) {
    double magnitude = this->magnitude();
    this->x = this->getX() / magnitude;
    this->y = this->getY() / magnitude;
    this->z = this->getZ() / magnitude;
}
        
Unit_vector::Unit_vector(Vector3d vec) {
    double magnitude = vec.magnitude();
    this->x = vec.getX() / magnitude;
    this->y = vec.getY() / magnitude;
    this->z = vec.getZ() / magnitude;
};