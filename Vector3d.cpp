#include "Vector3d.h"

class Vector3d {
    public:
        Vector3d(double x, double y, double z) {
            this->x = x;
            this->y = y;
            this->z = z;
        }

    private:
        double x;
        double y;
        double z;
};