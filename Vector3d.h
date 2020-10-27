#ifndef VECTOR3D_H
#define VECTOR3D_H

class Vector3d {
    public:
        Vector3d();
        Vector3d(double x, double y, double z);
        double getX();
        double getY();
        double getZ();
        double magnitude();

        Vector3d operator+(Vector3d& vec);
        Vector3d operator*(double scalar);
        
    protected:
        double x;
        double y;
        double z;
};

#endif
