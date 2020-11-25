#ifndef RAY_H
#define RAY_H

#include "Vector3d.h"

class Ray {
    public:
        Ray(Vector3d origin, Vector3d direction, Vector3d image_point);
        Vector3d getOrigin() const;
        Vector3d getDirection() const;
        Vector3d getImage_point() const;
        
    private:
        Vector3d origin;
        Vector3d direction;
        Vector3d image_point;
};

#endif