#include "Hittable.h"
#include "Vector3d.h"
#include "Ray.h"
#include "global_constants.h"
#include "Sphere.h"

#include <cmath>

Sphere::Sphere(Vector3d& center, double radius) {
    this->center = &center;
    this->radius = radius;
}

Vector3d* Sphere::getCenter() {
    return this->center;
}

double Sphere::getRadius() {
    return this->radius;
}

Vector3d* Sphere::intersects(Ray& ray, double time) {
    Vector3d intersectionPoint = *(ray.getOrigin()) + *(ray.getDirection()) * time;

    if (std::pow(intersectionPoint.getX() - this->getCenter()->getX(), 2) + 
        std::pow(intersectionPoint.getY() - this->getCenter()->getY(), 2) +
        std::pow(intersectionPoint.getZ() - this->getCenter()->getZ(), 2)
        - std::pow(this->getRadius(), 2) <= APPROX_EQUIV) {
                    
        return &intersectionPoint;
        }

    return nullptr;
}