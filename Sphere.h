#include "Vector3d.h"
#include "Hittable.h"
#include "Ray.h"

class Sphere: public Hittable {
    public:
        Sphere(Vector3d& center, double radius);
        const Vector3d* getCenter();
        const double getRadius();

        Vector3d* intersects(Ray& ray, double time);

    private:
        Vector3d* center;
        double radius;
};