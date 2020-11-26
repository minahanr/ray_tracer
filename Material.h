#ifndef MATERIAL_H
#define MATERIAL_H

#include "Hittable.h"
#include "Ray.h"
#include "Vector3d.h"
#include<memory>

class Hittable;

class Material {
    public:
        Material(Vector3d color);
        Vector3d getColor() const;
        virtual Ray scatter(Ray& ray, std::shared_ptr<Hittable> hittable, double min_time) const = 0;

    private:
        Vector3d color;
};

#endif