#include "Image.h"
#include "Vector3d.h"
#include "Unit_vector.h"
#include "Ray.h"
#include "Camera.h"

#include<vector>
#include<list>

Image::Image(Vector3d corner, Vector3d img_dir1, Vector3d img_dir2, double width, double height, double horizontal_res, double vertical_res) {
    this->corner = corner;
    this->vector_directions[0] = Unit_vector(img_dir1);
    this->vector_directions[1] = Unit_vector(img_dir2);
    this->width = width;
    this->height = height;
    this->horizontal_res = horizontal_res;
    this->vertical_res = vertical_res;
}

Vector3d Image::getCorner() const {
    return this->corner;
}

Vector3d* Image::getVectorDirections() {
    return this->vector_directions;
}
        
double Image::getWidth() const {
    return this->width;
}

double Image::getHeight() const {
    return this->height;
}

double Image::getHorizontalRes() const { 
    return this->horizontal_res;
}

double Image::getVerticalRes() const {
    return this->vertical_res;
}