#ifndef SPHERE_H
#define SPHERE_H

#include "Vector3d.h"
#include "Hittable.h"
#include "Ray.h"

class Sphere: public Hittable {
    public:
        Sphere(Vector3d center, double radius);
        Vector3d getCenter();
        double getRadius();

    private:
        Vector3d center;
        double radius;
};

#endif