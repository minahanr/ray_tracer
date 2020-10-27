#ifndef HITTABLE_H
#define HITTABLE_H

#include "Vector3d.h"
#include "Ray.h"

class Hittable {
    public:
        Hittable();
        Vector3d* intersects(Ray& ray, double time);
    private:
};

#endif