#include "Ray.h"
#include "Vector3d.h"
#include "Unit_vector.h"

Ray::Ray(Vector3d origin, Vector3d direction, Vector3d image_point, std::shared_ptr<Hittable> prev_intersection, double eta) {
    this->origin = origin;
    this->direction = Unit_vector(direction);
    this->image_point = image_point;
    this->prev_intersection_hittable = prev_intersection;
    this->eta = eta;
}

Vector3d Ray::getOrigin() const {
    return this->origin;
}

Vector3d Ray::getDirection() const {
    return this->direction;
}

Vector3d Ray::getImage_point() const {
    return this->image_point;
}

std::shared_ptr<Hittable> Ray::getPrevHittable() {
    return this->prev_intersection_hittable;
}

double Ray::getSnellIndex() const {
    return this->eta;
}