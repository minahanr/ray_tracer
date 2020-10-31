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
#include<cmath>
#include<time.h>

inline double clamp(double num, double min, double max) {
    if (num > max) {
        return max;
    }
    if (num < min) {
        return min;
    }
    return num;
}

void print_color(Vector3d color) {
    double scale = 1.0 / SAMPLES_PER_PIXEL;
    double r = color.getX() * scale;
    double g = color.getY() * scale;
    double b = color.getZ() * scale;
    int ir = static_cast<int>(255.999 * clamp(r, 0.0, 0.999));
    int ig = static_cast<int>(255.999 * clamp(g, 0.0, 0.999));
    int ib = static_cast<int>(255.999 * clamp(b, 0.0, 0.999));
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
    double a = ray.getDirection() * ray.getDirection();
    Vector3d oc; double time;
    Vector3d intersectionPoint;
    double min_time = -1; double b, c, t, discriminant;
    
    std::vector<Sphere>::iterator earliest_surface_hit = surface_list.begin();
    for (surface_it = surface_list.begin(); surface_it != surface_list.end(); surface_it++) {
        oc = ray.getOrigin() - surface_it->getCenter();
        b = ray.getDirection() * oc * 2;
        c = oc * oc - surface_it->getRadius() * surface_it->getRadius();

        discriminant = b * b - 4 * a * c;
        if (discriminant > 0) {
            time = (-1 * b - std::pow(discriminant, 0.5)) / (2.0 * a);
            if ((min_time == -1 || time < min_time) && time > 0) {
                min_time = time;
                earliest_surface_hit = surface_it;
            }
        }
    }

    if (min_time == -1) {
        t = 0.5 * (ray.getDirection().getY() + 1.0);
        return Vector3d(1, 1, 1) * (1.0 - t) + Vector3d(0.5, 0.7, 1.0) * t;
    } else {
        intersectionPoint = ray.getOrigin() + ray.getDirection() * min_time;
        Vector3d normal = Unit_vector(intersectionPoint - earliest_surface_hit->getCenter());
        Vector3d target = intersectionPoint + normal + randInUnitSphere();
        Ray newRay = Ray(intersectionPoint, Unit_vector(target - intersectionPoint), ray.getImage_point());
        return intersects(newRay, surface_list, depth - 1) * 0.5;
    }
}

int main() {
    Camera camera(Vector3d(0, 0, -10));
    Image image(Vector3d(-2, -2, -1), Unit_vector(1, 0, 0), Unit_vector(0, 1, 0), 400, 400, 0.01, 0.01);
    std::vector<Sphere> surface_list;
    std::cout << "P3\n" << image.getWidth() << ' ' << image.getHeight() << "\n255\n";
    surface_list.push_back(Sphere(Vector3d(0.0, 0.0, -2.0), 0.5));
    surface_list.push_back(Sphere(Vector3d(-1.0, 0.0, -1.0), 0.5));
    surface_list.push_back(Sphere(Vector3d(1.0, 0.0, -1.0), 0.5));
    surface_list.push_back(Sphere(Vector3d(0.0, -100.5, -1.0), 100.0));

    Ray ray(camera.getPoint(), camera.getPoint(), camera.getPoint());
    Vector3d image_point, color;
    bool skip = true;
    double i_rand, j_rand;

    for (int i = image.getHeight() - 1; i >= 0; i--) {
        for (int j = 0; j < image.getWidth(); j++) {
            
            color = Vector3d();
            for (int s = 0; s < SAMPLES_PER_PIXEL; s++) {
                i_rand = i + rand() / (RAND_MAX + 1.0);
                j_rand = j + rand() / (RAND_MAX + 1.0);
                image_point = image.getCorner() + image.getVectorDirections()[0] * j_rand * image.getHorizontalRes() + image.getVectorDirections()[1] * i_rand * image.getVerticalRes();
                ray = Ray(camera.getPoint(), Unit_vector(image_point - camera.getPoint()), image_point);
                color = color + intersects(ray, surface_list, 50);
            }
            print_color(color);
        }
    }
}