#include "Hittable.h"
#include "Vector3d.h"
#include "Ray.h"
#include "global_constants.h"
#include "Sphere.h"

#include <cmath>
#include<iostream>

Sphere::Sphere(Vector3d center, double radius) {
    this->center = center;
    this->radius = radius;
}

Vector3d Sphere::getCenter() {
    return this->center;
}

double Sphere::getRadius() {
    return this->radius;
}

Vector3d Sphere::intersects(Ray& ray, double time) {
    Vector3d intersectionPoint = *(ray.getOrigin()) + *(ray.getDirection()) * time;
    Vector3d dif = intersectionPoint - this->getCenter();
    double distance = dif * dif;
    double r_squared = std::pow(this->getRadius(), 2);
    if (distance - r_squared <= APPROX_EQUIV && distance - r_squared >= -1 * APPROX_EQUIV) {
        return intersectionPoint;
    }

    return *(ray.getOrigin());
}