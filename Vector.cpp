include "Vector.h"

class Vector {
    public:
        Vector(double x, double y, double z) {
            this->x = x;
            this->y = y;
            this->z = z;
        }

    private:
        double x;
        double y;
        double z;
}