#include "Vector3d.h"

#include <cmath>
#include <iostream>

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
    return std::pow((*this) * (*this), 0.5);
}

Vector3d Vector3d::operator+(Vector3d vec) {
    return Vector3d(this->getX() + vec.getX(), this->getY() + vec.getY(), this->getZ() + vec.getZ());
}

Vector3d Vector3d::operator-(Vector3d vec) {
    return this->operator+(vec * -1);
}
double Vector3d::operator*(Vector3d vec) {
    return this->getX() * vec.getX() + this->getY() * vec.getY() + this->getZ() * vec.getZ();
}
Vector3d Vector3d::operator*(double scalar) {
    return Vector3d(this->getX() * scalar, this->getY() * scalar, this->getZ() * scalar);
}

bool Vector3d::operator==(Vector3d vec) {
    return (this->getX() == vec.getX() &&
            this->getY() == vec.getY() &&
            this->getZ() == vec.getZ());
}

bool Vector3d::operator!=(Vector3d vec) {
    return !(*this == vec);
}