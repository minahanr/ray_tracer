#include "Ray.h"

class Ray {
    public:
        Ray(Vector3d &origin, Vector3d &direction) {
            this->origin = &origin;
            this->direction = &direction;
        }
    private:
        Vector3d* origin;
        Vector3d* direction;
};