#include "Vector3d.h"

#include <cmath>

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

        double magnitude() const {
            return std::pow(std::pow(this->getX(), 2) + std::pow(this->getY(), 2), 1/2);
        }

        Vector3d operator+(const Vector3d& vec) {
            return Vector3d(this->getX() + vec.getX(), this->getY() + vec.getY(), this->getZ() + vec.getZ());
        }
        Vector3d operator*(double scalar) {
            return Vector3d(this->getX() * scalar, this->getY() * scalar, this->getZ() * scalar);
        }

    private:
        double x;
        double y;
        double z;


};

Vector3d operator*(double scalar, Vector3d& vec) {
    return vec * scalar;
}