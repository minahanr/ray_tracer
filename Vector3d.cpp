#include "Vector3d.h"

class Vector3d {
    public:
        Vector3d() {
            Vector3d(0, 0, 0);
        }
        
        Vector3d(double x, double y, double z) {
            this->x = x;
            this->y = y;
            this->z = z;
        }

        double getX() const {
            return this->x;
        }

        double getY() const {
            return this->y;
        }

        double getZ() const {
            return this->z;
        }

        Vector3d operator+(const Vector3d& vec) {
            return Vector3d(this->x + vec.getX(), this->y + vec.getY(), this->z + vec.getZ());
        }
        Vector3d operator*(double scalar) {
            return Vector3d(this->x * scalar, this->y * scalar, this->z * scalar);
        }

    private:
        double x;
        double y;
        double z;


};

Vector3d operator*(double scalar, Vector3d& vec) {
    return vec * scalar;
}