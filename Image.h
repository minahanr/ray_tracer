#include "Vector3d.h"
#include "Ray.h"

#include<vector>
#include<list>

class Image {
    public:
        Image(Vector3d &corner, Vector3d &img_dir1, Vector3d &img_dir2, double width, double height, double horizontal_res, double vertical_res);
        Vector3d* getCorner() const;
        Vector3d* getAngleOfImage() const;
        double getWidth() const;
        double getHeight() const;
        double getHorizontalRes() const;
        double getVerticalRes() const;
        std::list<Ray> generate_rays_to_image();
    private:
        Vector3d* lower_left_corner;
        Vector3d* lower_right_corner;
        Vector3d* upper_right_corner;
        Vector3d* upper_left_corner;
        double horizontal_res;
        double vertical_res;
};