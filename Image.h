#ifndef IMAGE_H
#define IMAGE_H

#include "Vector3d.h"
#include "Ray.h"
#include "Camera.h"

#include<vector>
#include<list>

class Image {
    public:
        Image(Vector3d corner, Vector3d img_dir1, Vector3d img_dir2, double width, double height, double horizontal_res, double vertical_res);
        Vector3d getCorner() const;
        Vector3d* getVectorDirections();
        double getWidth() const;
        double getHeight() const;
        double getHorizontalRes() const;
        double getVerticalRes() const;

    private:
        Vector3d corner;
        Vector3d vector_directions[2];
        double width;
        double height;
        double horizontal_res;
        double vertical_res;

};

#endif