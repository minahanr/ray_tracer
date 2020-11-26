#include "Hittable.h"
#include "Vector3d.h"
#include "Ray.h"
#include "global_constants.h"
#include "Sphere.h"
#include "Material.h"
#include "Unit_vector.h"

#include <cmath>
#include<iostream>
#include<memory>

Sphere::Sphere(Vector3d center, double radius, std::shared_ptr<Material> material) : Hittable(material) {
    this->center = center;
    this->radius = radius;
}

Vector3d Sphere::getCenter() const {
    return this->center;
}

double Sphere::getRadius() const {
    return this->radius;
}

void Sphere::printData() const {
    std::cout << this->center.getX() << ' ' << this->center.getY() << ' ' << this->center.getZ() << '\n';
}

double Sphere::intersects(Ray& ray) const {
    double time;
    Vector3d oc = ray.getOrigin() - this->getCenter();
    double a = ray.getDirection().dot(ray.getDirection());
    double b = ray.getDirection().dot(oc) * 2;
    double c = oc.dot(oc) - this->getRadius() * this->getRadius();

    double discriminant = b * b - 4 * a * c;

    if (discriminant > 0) {
        return (-1 * b - std::pow(discriminant, 0.5)) / (2.0 * a);
    }
    
    return -1;
}

Vector3d Sphere::calculateNormal(Vector3d intersectionPoint) const {
    return Unit_vector(intersectionPoint - this->getCenter());
}