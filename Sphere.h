#ifndef SPHERE_H
#define SPHERE_H

#include "Vector3d.h"
#include "Hittable.h"
#include "Ray.h"
#include "Material.h"

class Sphere: public Hittable {
    public:
        Sphere(Vector3d center, double radius, Material material);
        Vector3d getCenter();
        double getRadius();
        Material getMaterial();

    private:
        Vector3d center;
        double radius;
        Material material;
};

#endif