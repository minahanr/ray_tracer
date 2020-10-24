#include "Hittable.h"

class Hittable {
    public:
        Hittable(&Point_set points) {
            this->points = points;
        }

    private:
        Point_set* points;
}