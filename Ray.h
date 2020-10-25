#include "Vector3d.h"

class Ray {
    public:
        Ray(Vector3d &origin, Vector3d &direction);
        Vector3d find_intersection(double time_start, double time_end, double delta_t, double delta_r);
        Vector3d* getOrigin();
        Vector3d* getDirection();
        
    private:
        Vector3d* origin;
        Vector3d* direction;
};