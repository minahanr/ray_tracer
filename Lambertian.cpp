#include "Lambertian.h"
#include "Vector3d.h"
#include "Unit_vector.h"

Vector3d randInUnitSphere() {
    double x = ((double) rand()) / (RAND_MAX + 1.0);
    double y = ((double) rand()) / (RAND_MAX + 1.0);
    double z = ((double) rand()) / (RAND_MAX + 1.0);
    Vector3d vec(x, y, z);
    if (vec.dot(vec) <= 1) {
        return vec;
    } else {
        return randInUnitSphere();
    }
}

Lambertian::Lambertian() : Material(Vector3d(0.5,0.5,0.5)) {

}

Lambertian::Lambertian(Vector3d color) : Material(color) {

}

Ray Lambertian::scatter(Ray& ray, std::shared_ptr<Hittable> hittable, double min_time) const {
    Vector3d intersectionPoint = ray.getOrigin() + ray.getDirection() * min_time;
    Vector3d normal = hittable->calculateNormal(intersectionPoint);
    Vector3d target = intersectionPoint + normal + randInUnitSphere();
    return Ray(intersectionPoint, Unit_vector(target - intersectionPoint), ray.getImage_point());
}