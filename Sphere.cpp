#include "Hittable.h"
#include "Vector3d.h"
#include "Ray.h"
#include "global_constants.h"
#include "Sphere.h"
#include "Material.h"

#include <cmath>
#include<iostream>

Sphere::Sphere(Vector3d center, double radius, Material material) {
    this->center = center;
    this->radius = radius;
    this->material = material;
}

Vector3d Sphere::getCenter() {
    return this->center;
}

double Sphere::getRadius() {
    return this->radius;
}

Material Sphere::getMaterial() {
    return this->material;
}