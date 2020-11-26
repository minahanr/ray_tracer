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

double Vector3d::getX() const {
    return this->x;
}

double Vector3d::getY() const {
    return this->y;
}

double Vector3d::getZ() const {
    return this->z;
}

double Vector3d::magnitude() const {
    return std::pow((*this).dot((*this)), 0.5);
}

Vector3d Vector3d::operator+(Vector3d vec) const {
    return Vector3d(this->getX() + vec.getX(), this->getY() + vec.getY(), this->getZ() + vec.getZ());
}

Vector3d Vector3d::operator-(Vector3d vec) const {
    return this->operator+(vec * -1);
}

double Vector3d::dot(Vector3d vec) const {
    return this->getX() * vec.getX() + this->getY() * vec.getY() + this->getZ() * vec.getZ();
}

Vector3d Vector3d::operator*(Vector3d vec) const {
    return Vector3d(this->getX() * vec.getX(), this->getY() * vec.getY(), this->getZ() * vec.getZ());
}

Vector3d Vector3d::operator*(double scalar) const {
    return Vector3d(this->getX() * scalar, this->getY() * scalar, this->getZ() * scalar);
}

bool Vector3d::operator==(Vector3d vec) const {
    return (this->getX() == vec.getX() &&
            this->getY() == vec.getY() &&
            this->getZ() == vec.getZ());
}

bool Vector3d::operator!=(Vector3d vec) const {
    return !(*this == vec);
}