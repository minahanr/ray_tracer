#include "Ray.h"

class Ray {
    public:
        Ray(Vector3d &origin, Vector3d &direction, Vector3d &image_point) {
            this->origin = &origin;
            this->direction = &direction;
            this->image_point = &image_point;
        }

        Vector3d* getOrigin() {
            return origin;
        }

        Vector3d* getDirection() {
            return direction;
        }

        Vector3d* getImage_point() {
            return image_point;
        }
        
    private:
        Vector3d* origin;
        Vector3d* direction;
        Vector3d* image_point;
};