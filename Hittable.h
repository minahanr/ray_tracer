#ifndef HITTABLE_H
#define HITTABLE_H

#include "Vector3d.h"
#include "Ray.h"
#include "Material.h"

#include<memory>

class Material;

class Hittable {
    public:
        Hittable();
        Hittable(std::shared_ptr<Material> material);
        std::shared_ptr<Material> getMaterial();
        virtual void printData() const = 0;
        virtual double intersects(Ray& ray) const = 0;
        virtual Vector3d calculateNormal(Vector3d intersectionPoint) const = 0;

    private:
        std::shared_ptr<Material> m_material;
};

#endif