#include "Metal.h"
#include "Ray.h"
#include "Hittable.h"
#include "Vector3d.h"
#include "Unit_vector.h"

#include<memory>

Metal::Metal(): Material(Vector3d(1, 1, 1)) {

}

Metal::Metal(Vector3d color) : Material(color) {

}

Ray Metal::scatter(Ray& ray, std::shared_ptr<Hittable> hittable, double min_time) const {
    Vector3d intersectionPoint = ray.getOrigin() + ray.getDirection() * min_time;
    Vector3d normal = hittable->calculateNormal(intersectionPoint);
    return Ray(intersectionPoint, Unit_vector(ray.getDirection() + normal * 2), ray.getImage_point());
}