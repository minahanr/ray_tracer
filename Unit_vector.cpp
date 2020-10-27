#include "Unit_vector.h"
#include "Vector3d.h"

Unit_vector::Unit_vector() {
    this->x = 1;
    this->y = 0;
    this->z = 0;
}
        
Unit_vector::Unit_vector(double x, double y, double z) {
    Vector3d vec(x, y, z);
    double magnitude = vec.magnitude();
    this->x = vec.getX() / magnitude;
    this->y = vec.getY() / magnitude;
    this->z = vec.getZ() / magnitude;
}
        
Unit_vector::Unit_vector(Vector3d& vec) {
    double magnitude = vec.magnitude();
    this->x = vec.getX() / magnitude;
    this->y = vec.getY() / magnitude;
    this->z = vec.getZ() / magnitude;
};