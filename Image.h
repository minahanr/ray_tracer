#include "Vector3d.h"

class Image {
    public:
        Image(Vector3d &corner, Vector3d& angle_of_image, double width, double height, double horizontal_res, double vertical_res);
        Vector3d* getCorner() const;
        Vector3d* getAngleOfImage() const;
        double getWidth() const;
        double getHeight() const;
        double getHorizontalRes() const;
        double getVerticalRes() const;
        void iterate_on_rays();
    private:
        Vector3d* lower_left_corner;
        Vector3d* lower_right_corner;
        Vector3d* upper_right_corner;
        Vector3d* upper_left_corner;
        double horizontal_res;
        double vertical_res;
};