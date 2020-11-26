#ifndef LAMBERTIAN_H
#define LAMBERTIAN_H

#include "Hittable.h"
#include "Material.h"
#include "Vector3d.h"
#include "Ray.h"
#include<memory>

class Lambertian : public Material {
    public:
        Lambertian();
        Lambertian(Vector3d color);

        virtual Ray scatter(Ray& ray, std::shared_ptr<Hittable> hittable, double min_time) const;
};

#endif