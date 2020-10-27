#ifndef RAY_H
#define RAY_H

#include "Vector3d.h"

class Ray {
    public:
        Ray(Vector3d origin, Vector3d direction, Vector3d image_point);
        Vector3d* getOrigin();
        Vector3d* getDirection();
        Vector3d* getImage_point();
        
    private:
        Vector3d* origin;
        Vector3d* direction;
        Vector3d* image_point;
};

#endif