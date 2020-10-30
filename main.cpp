#include "Ray.h"
#include "Hittable.h"
#include "Sphere.h"
#include "Camera.h"
#include "Image.h"
#include "Vector3d.h"
#include "Unit_vector.h"
#include "global_constants.h"

#include<iostream>
#include<vector>
#include<list>



void print_color(double r, double g, double b) {
    int ir = static_cast<int>(255.999 * r);
    int ig = static_cast<int>(255.999 * g);
    int ib = static_cast<int>(255.999 * b);
    std::cout << ir << ' ' << ig << ' ' << ib << '\n';
}

int main() {
    Camera camera(Vector3d(0, 0, 0));
    Image image(Vector3d(-2, -2, -1), Unit_vector(1, 0, 0), Unit_vector(0, 1, 0), 400, 400, 0.01, 0.01);
    std::vector<Sphere> surface_list;
    std::cout << "P3\n" << image.getWidth() << ' ' << image.getHeight() << "\n255\n";
    surface_list.push_back(Sphere(Vector3d(0, 0, -5), 3));
    Ray ray(camera.getPoint(), camera.getPoint(), camera.getPoint());
    Vector3d image_point;
    bool skip = true;

    for (int i = 0; i < image.getHeight(); i++) {
        for (int j = 0; j < image.getWidth(); j++) {
            skip = false;
            image_point = image.getCorner() + image.getVectorDirections()[0] * j * image.getHorizontalRes() + image.getVectorDirections()[1] * i * image.getVerticalRes();
            ray = Ray(camera.getPoint(), Unit_vector(image_point - camera.getPoint()), image_point);
            for (double time = START_TIME; time < END_TIME; time += DELTA_TIME) {
                for (std::vector<Sphere>::iterator surface_it = surface_list.begin(); surface_it != surface_list.end(); surface_it++) {
                    if (time && surface_it->intersects(ray, time) != *(ray.getOrigin())) {
                        skip = true;
                        print_color(1, 0, 0);
                        break;
                    }
                }

                if (skip) {
                    break;
                }
            }

            if (!skip) {
                print_color(0, 0, 0);
            }
        }
    }
}