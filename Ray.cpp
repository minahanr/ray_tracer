#include "Ray.h"

Ray::Ray(Vector3d origin, Vector3d direction, Vector3d image_point) {
    this->origin = origin;
    this->direction = direction;
    this->image_point = image_point;
}

Vector3d Ray::getOrigin() const {
    return origin;
}

Vector3d Ray::getDirection() const {
    return direction;
}

Vector3d Ray::getImage_point() const {
    return image_point;
}