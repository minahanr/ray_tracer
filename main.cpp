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
#include<time.h>


void print_color(Vector3d color) {
    int ir = static_cast<int>(255.999 * color.getX());
    int ig = static_cast<int>(255.999 * color.getY());
    int ib = static_cast<int>(255.999 * color.getZ());
    std::cout << ir << ' ' << ig << ' ' << ib << '\n';
}

Vector3d randInUnitSphere() {
    double x = ((double) rand()) / (RAND_MAX + 1.0);
    double y = ((double) rand()) / (RAND_MAX + 1.0);
    double z = ((double) rand()) / (RAND_MAX + 1.0);
    Vector3d vec(x, y, z);
    if (vec * vec <= 1) {
        return vec;
    } else {
        return randInUnitSphere();
    }
}

Vector3d intersects(Ray ray, std::vector<Sphere> surface_list, int depth) {

    if (depth <= 0) {
        return Vector3d(0, 0, 0);
    }

    std::vector<Sphere>::iterator surface_it = surface_list.begin();
    Vector3d intersectionPoint, dif, normal, target; double distance, r_squared;

    for (double time = DELTA_TIME; time < END_TIME; time += DELTA_TIME) {
        intersectionPoint = ray.getOrigin() + ray.getDirection() * time;
        for (surface_it = surface_list.begin(); surface_it != surface_list.end(); surface_it++) {
            dif = intersectionPoint - surface_it->getCenter();
            distance = dif * dif;
            r_squared = surface_it->getRadius() * surface_it->getRadius();
            if (distance - r_squared <= APPROX_EQUIV && distance - r_squared >= -1 * APPROX_EQUIV) {
                normal = Unit_vector(intersectionPoint - surface_it->getCenter());
                target = intersectionPoint + normal + randInUnitSphere();
                Ray newRay = Ray(intersectionPoint, Unit_vector(target - intersectionPoint), ray.getImage_point());
                return intersects(newRay, surface_list, depth - 1) * 0.5;
            }
        }
    }
    
    double t = 0.5 * (ray.getDirection().getY() + 1.0);
    return Vector3d(1, 1, 1) * (1.0 - t) + Vector3d(0.5, 0.7, 1.0) * t;
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

    for (int i = image.getHeight() - 1; i >= 0; i--) {
        for (int j = 0; j < image.getWidth(); j++) {
            image_point = image.getCorner() + image.getVectorDirections()[0] * j * image.getHorizontalRes() + image.getVectorDirections()[1] * i * image.getVerticalRes();
            ray = Ray(camera.getPoint(), Unit_vector(image_point - camera.getPoint()), image_point);

            print_color(intersects(ray, surface_list, 20));
        }
    }
}