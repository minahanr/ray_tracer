#ifndef IMAGE_H
#define IMAGE_H

#include "Vector3d.h"
#include "Ray.h"

#include<vector>
#include<list>

class Image {
    public:
        Image(Vector3d &corner, Vector3d &img_dir1, Vector3d &img_dir2, double width, double height, double horizontal_res, double vertical_res);
        Vector3d* getCorner();
        Vector3d* getVectorDirections();
        double getWidth();
        double getHeight();
        double getHorizontalRes();
        double getVerticalRes();
        std::list<Ray> generate_rays_to_image();
    private:
        Vector3d* corner;
        Vector3d vector_directions[2];
        double width;
        double height;
        double horizontal_res;
        double vertical_res;

};

#endif