#ifndef HITTABLE_H
#define HITTABLE_H

#include "Vector3d.h"
#include "Ray.h"
#include "Material.h"

class Hittable {
    public:
        Hittable();
        Hittable(Material material);
        Material getMaterial() const;
        virtual void printData() const = 0;
        virtual double intersects(Ray& ray) const = 0;
        virtual Vector3d calculateNormal(Vector3d intersectionPoint) const = 0;

    private:
        Material m_material;
};

#endif