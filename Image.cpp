#include "Image.h"
#include "Vector3d.h"

class Image {
    public:
        Image(Vector3d &lower_left_corner, Vector3d &upper_right_corner) {
            this->lower_left_corner = &lower_left_corner;
            this->upper_right_corner = &upper_right_corner;
        }

    private:
        Vector3d* lower_left_corner;
        Vector3d* upper_right_corner;
};