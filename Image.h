#include "Vector3d.h"

class Image {
    public:
        Image(Vector3d &lower_left_corner, Vector3d &lower_right_corner, Vector3d &upper_left_corner, Vector3d &upper_right_corner, double horizontal_res, double vertical_res);

    private:
        Vector3d* lower_left_corner;
        Vector3d* lower_right_corner;
        Vector3d* upper_right_corner;
        Vector3d* upper_left_corner;
        double horizontal_res;
        double vertical_res;
};