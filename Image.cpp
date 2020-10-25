#include "Image.h"
#include "Vector3d.h"

class Image {
    public:
        Image(Vector3d &lower_left_corner, Vector3d &lower_right_corner, Vector3d &upper_left_corner, Vector3d &upper_right_corner, double horizontal_res, double vertical_res) {
            this->lower_left_corner = &lower_left_corner;
            this->lower_right_corner = &lower_right_corner;
            this->upper_left_corner = &upper_left_corner;
            this->upper_right_corner = &upper_right_corner;
            this->horizontal_res = horizontal_res;
            this->vertical_res = vertical_res;
        }

    private:
        Vector3d* lower_left_corner;
        Vector3d* lower_right_corner;
        Vector3d* upper_right_corner;
        Vector3d* upper_left_corner;
        double horizontal_res;
        double vertical_res;
};