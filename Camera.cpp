#include "Camera.h"
#include "Vector3d.h"

Camera::Camera(Vector3d& point) {
    this->point = &point;
}

Vector3d* Camera::getPoint() {
    return this->point;
}