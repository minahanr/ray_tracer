class Vector3d {
    public:
        Vector3d();
        Vector3d(double x, double y, double z);
        double getX();
        double getY();
        double getZ();

        Vector3d operator+(const Vector3d& vec);
        Vector3d operator*(double scalar);
    private:
        double x;
        double y;
        double z;
};
