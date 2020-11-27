#ifndef DIELECTRIC_H
#define DIELECTRIC_H

#include "Material.h"
#include "Ray.h"

class Dielectric : public Material {
    public:
        Dielectric();
        double getSnellIndex() const;
        virtual Ray scatter(Ray& ray, std::shared_ptr<Hittable> hittable, double min_time) const;
    private:
        double snellIndex;
        static double reflectance(double cos, double ref_idx);
};

#endif