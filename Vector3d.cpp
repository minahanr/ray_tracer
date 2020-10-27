#include "Vector3d.h"

#include <cmath>

Vector3d::Vector3d() {
    Vector3d(0, 0, 0);
}

Vector3d::Vector3d(double x, double y, double z) {
    this->x = x;
    this->y = y;
    this->z = z;
}

double Vector3d::getX() {
    return this->x;
}

double Vector3d::getY() {
    return this->y;
}

double Vector3d::getZ() {
    return this->z;
}

double Vector3d::magnitude() {
    return std::pow(std::pow(this->getX(), 2) + std::pow(this->getY(), 2), 1/2);
}

Vector3d Vector3d::operator+(Vector3d vec) {
    return Vector3d(this->getX() + vec.getX(), this->getY() + vec.getY(), this->getZ() + vec.getZ());
}

Vector3d Vector3d::operator*(double scalar) {
    return Vector3d(this->getX() * scalar, this->getY() * scalar, this->getZ() * scalar);
}