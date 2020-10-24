#include "Vector3d.h"

class Camera {
    public:
        Camera(Vector3d& point);

    private:
        Vector3d* point;
}