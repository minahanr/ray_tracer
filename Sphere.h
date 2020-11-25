#ifndef SPHERE_H
#define SPHERE_H

#include "Vector3d.h"
#include "Hittable.h"
#include "Ray.h"
#include "Material.h"

class Sphere: public Hittable {
    public:
        Sphere(Vector3d center, double radius, Material material);
        Vector3d getCenter() const;
        double getRadius() const;
        virtual void printData() const override;
        virtual double intersects(Ray& ray) const override;
        virtual Vector3d calculateNormal(Vector3d intersectionPoint) const override;

    private:
        Vector3d center;
        double radius;
};

#endif