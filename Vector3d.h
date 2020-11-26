#ifndef VECTOR3D_H
#define VECTOR3D_H

class Vector3d {
    public:
        Vector3d();
        Vector3d(double x, double y, double z);
        double getX() const;
        double getY() const;
        double getZ() const;
        double magnitude() const;

        double dot(Vector3d vec) const;
        Vector3d operator+(Vector3d vec) const;
        Vector3d operator-(Vector3d vec) const;
        Vector3d operator*(Vector3d vec) const;
        Vector3d operator*(double scalar) const;
        bool operator==(Vector3d vec) const;
        bool operator!=(Vector3d vec) const;
        
    protected:
        double x;
        double y;
        double z;
};

#endif
