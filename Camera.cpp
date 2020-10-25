#include "Camera.h"
#include "Vector3d.h"

class Camera {
    public:
        Camera(Vector3d& point) {
            this->point = &point;
        }

        Vector3d* getPoint() const {
            return this->point;
        }
    private:
        Vector3d* point;
};