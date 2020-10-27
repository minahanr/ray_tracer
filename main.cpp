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



void print_color(double r, double g, double b, int width, int height) {
    int ir = static_cast<int>(255.999 * r);
    int ig = static_cast<int>(255.999 * g);
    int ib = static_cast<int>(255.999 * b);
    std::cout << ir << ' ' << ig << ' ' << ib << '\n';
}

int main() {
    Camera camera(Vector3d());
    Image image(Vector3d(-2, -2, -1), Unit_vector(0, 1, 0), Unit_vector(1, 0, 0), 4., 2., 0.01, 0.01);
    std::vector<Hittable> surface_list;
    std::list<Ray> ray_list = image.generate_rays_to_image(camera);

    std::cout << "P3\n" << image.getWidth() << ' ' << image.getHeight() << "\n255\n";
    surface_list.push_back(Sphere(Vector3d(0, 0, -1), 1));

    bool skip = false;
    int ray_num = 0;
    for (std::list<Ray>::iterator ray_it = ray_list.begin(); ray_it != ray_list.end(); ray_it++) {
        skip = false;
        for (double time = START_TIME; time < END_TIME; time += DELTA_TIME) {
            for (std::vector<Hittable>::iterator surface_it = surface_list.begin(); surface_it != surface_list.end(); surface_it++) {
                if (surface_it->intersects(*ray_it, time) != nullptr) {
                    skip = true;
                    print_color(1, 0, 0, image.getWidth(), image.getHeight());
                    break;
                }
            }

            if (skip == true) {
                break;
            }

            print_color(0, 0, 0, image.getWidth(), image.getHeight());
        }
        ray_num++;
    }
}