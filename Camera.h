#ifndef CAMERA_H
#define CAMERA_H

#include "Vector3d.h"

class Camera {
    public:
        Camera(Vector3d& point);
        Vector3d* getPoint();

    private:
        Vector3d* point;
};

#endif