#include "Vector3d.h"

class Unit_vector: public Vector3d {
    public:
        Unit_vector();
        Unit_vector(double x, double y, double z);
        Unit_vector(Vector3d &vec);
};