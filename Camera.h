#ifndef CAMERA_H
#define CAMERA_H

#include "Vector3d.h"

class Camera {
    public:
        Camera(Vector3d point);
        Vector3d getPoint() const;

    private:
        Vector3d point;
};

#endif