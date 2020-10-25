#include "Vector3d.h"

class Ray {
    public:
        Ray(Vector3d &origin, Vector3d &direction, Vector3d &image_point);
        Vector3d find_intersection(double time_start, double time_end, double delta_t, double delta_r);
        Vector3d* getOrigin();
        Vector3d* getDirection();
        Vector3d* getImage_point();
        
    private:
        Vector3d* origin;
        Vector3d* direction;
        Vector3d* image_point;
};