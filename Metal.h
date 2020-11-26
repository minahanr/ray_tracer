#ifndef METAL_H
#define METAL_H

#include "Material.h"
#include "Ray.h"
#include "Hittable.h"
#include "Vector3d.h"

class Metal : public Material {
    public:
        Metal();
        Metal(Vector3d color);
        virtual Ray scatter(Ray& ray, std::shared_ptr<Hittable> hittable, double min_time) const;

};

#endif