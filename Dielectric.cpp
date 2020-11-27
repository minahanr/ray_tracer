#include "Ray.h"
#include "Hittable.h"
#include "Dielectric.h"
#include "global_constants.h"
#include "Unit_vector.h"

#include <math.h>

Dielectric::Dielectric() : Material(Vector3d(1, 1, 1)) {
    this->snellIndex = 1.7;
}

double Dielectric::getSnellIndex() const {
    return this->snellIndex;
}

Ray Dielectric::scatter(Ray& ray, std::shared_ptr<Hittable> hittable, double min_time) const {
    double snellIndex = this->getSnellIndex();

    if (ray.getPrevHittable() == hittable) {
        snellIndex = DEFAULT_ETA;
    }

    Vector3d intersectionPoint = ray.getOrigin() + ray.getDirection() * min_time;
    Vector3d normal = hittable->calculateNormal(intersectionPoint);
    double cos_theta = ray.getDirection().dot(normal);
    double sin_theta = sqrt(1 - cos_theta * cos_theta);
    double refractionRatio = ray.getSnellIndex() / snellIndex;

    if (sin_theta * refractionRatio > 1 || this->reflectance(cos_theta * -1, refractionRatio) > ((double) rand()) / (RAND_MAX + 1.0) ) {
        return Ray(intersectionPoint, Unit_vector(ray.getDirection() + normal * 2), ray.getImage_point(), hittable, ray.getSnellIndex());
    }

    Vector3d r_prime_perp =  (ray.getDirection() + normal * cos_theta * -1) * refractionRatio;
    Vector3d r_prime_par = normal * (-1 * sqrt(1 - r_prime_perp.dot(r_prime_perp)));

    return Ray(intersectionPoint, r_prime_perp + r_prime_par, ray.getImage_point(), hittable, snellIndex);
}

double Dielectric::reflectance(double cos, double ref_idx) {
    double r0 = (1-ref_idx) / (1+ref_idx);
    r0 = r0*r0;
    return r0 + (1-r0) * pow((1 - cos),5);
}