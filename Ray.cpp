#include "Ray.h"

class Ray {
    public:
        Ray(Vector3d &origin, Vector3d &direction) {
            this->origin = &origin;
            this->direction = &direction;
        }

        Vector3d* getOrigin() {
            return origin;
        }

        Vector3d* getDirection() {
            return direction;
        }
    private:
        Vector3d* origin;
        Vector3d* direction;
};