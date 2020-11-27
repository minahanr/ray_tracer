#ifndef RAY_H
#define RAY_H

#include "Vector3d.h"
#include "Hittable.h"

#include<memory>

class Hittable;

class Ray {
    public:
        Ray(Vector3d origin, Vector3d direction, Vector3d image_point, std::shared_ptr<Hittable> prev_intersection, double eta);
        Vector3d getOrigin() const;
        Vector3d getDirection() const;
        Vector3d getImage_point() const;
        std::shared_ptr<Hittable> getPrevHittable();
        double getSnellIndex() const;
        
    private:
        Vector3d origin;
        Vector3d direction;
        Vector3d image_point;
        std::shared_ptr<Hittable> prev_intersection_hittable;
        double eta;
};

#endif