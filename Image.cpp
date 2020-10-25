#include "Image.h"
#include "Vector3d.h"
#include "Unit_vector.h"
#include "Ray.h"
#include "Camera.h"

#include<vector>

class Image {
    public:
        Image(Vector3d &corner, Vector3d &img_dir1, Vector3d &img_dir2, double width, double height, double horizontal_res, double vertical_res) {
            this->corner = &corner;
            this->vector_directions[0] = Unit_vector(img_dir1);
            this->vector_directions[1] = Unit_vector(img_dir2);
            this->width = width;
            this->height = height;
            this->horizontal_res = horizontal_res;
            this->vertical_res = vertical_res;
        }

        Vector3d* getCorner() const {
            return this->corner;
        }

        Vector3d* getVectorDirections() {
            return this->vector_directions;
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

        std::vector<Ray> generate_rays_to_image(Camera &camera) {
            std::vector<Ray> ray_list;
            Vector3d imagePoint;
            for(int i = 0; i < this->getHeight(); i += this->getVerticalRes()) {
                for (int j = 0; j < this->getWidth(); j += this->getHorizontalRes()) {
                    imagePoint = *(this->getCorner()) + vector_directions[0] * i + vector_directions[1] * j;
                    ray_list.push_back(Ray(*(camera.getPoint()), Unit_vector(imagePoint + *(camera.getPoint()) * -1), imagePoint));
                }
            }
        }
    private:
        Vector3d* corner;
        Unit_vector vector_directions[2];
        double width;
        double height;
        double horizontal_res;
        double vertical_res;
};