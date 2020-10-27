#include "Ray.h"

Ray::Ray(Vector3d origin, Vector3d direction, Vector3d image_point) {
    this->origin = &origin;
    this->direction = &direction;
    this->image_point = &image_point;
}

Vector3d* Ray::getOrigin() {
    return origin;
}

Vector3d* Ray::getDirection() {
    return direction;
}

Vector3d* Ray::getImage_point() {
    return image_point;
}