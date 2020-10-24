#include "Camera.h"
#include "Vector3d.h"

class Camera {
    public:
        Camera(Vector3d& point) {
            this->point = &point;
        }

    private:
        Vector3d* point;
};