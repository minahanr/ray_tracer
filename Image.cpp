#include "Image.h"
#include "Vector3d.h"

class Image {
    public:
        Image(Vector3d &corner, Vector3d &angle_of_image, double width, double height, double horizontal_res, double vertical_res) {
            this->corner = &corner;
            this->angle_of_image = &angle_of_image;
            this->width = width;
            this->height = height;
            this->horizontal_res = horizontal_res;
            this->vertical_res = vertical_res;
        }

        Vector3d* getCorner() const {
            return this->corner;
        }

        Vector3d* getAngleOfImage() const {
            return this->angle_of_image;
        }
        double getWidth() const {
            return this->width;
        }

        double getHeight() const {
            return this->height;
        }

        double getHorizontalRes() const {
            return this->horizontal_res;
        }

        double getVerticalRes() const {
            return this->vertical_res;
        }

        void iterate_on_rays() {
            for(int i = 0; i < this->getHeight(); i += this->getVerticalRes()) {
                for (int j = 0; j < this->getWidth(); j += this->getHorizontalRes()) {

                }
            }
        }
    private:
        Vector3d* corner;
        Vector3d* angle_of_image;
        double width;
        double height;
        double horizontal_res;
        double vertical_res;
};