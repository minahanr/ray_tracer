#include "Ray.h"

class Ray {
    public:
        Ray(Vector &origin, Vector &direction) {
            this->origin = &origin;
            this->direction = &direction;
        }
    private:
        Vector* origin;
        Vector* direction;
}