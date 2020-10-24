#include "Vector.h"

class Ray {
    public:
        Ray(Vector &origin, Vector &direction);
        Vector find_intersection(double time_start, double time_end, double delta_t, double delta_r);
    private:
        Vector* origin;
        Vector* direction;
}