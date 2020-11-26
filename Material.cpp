#include "Material.h"
#include "Vector3d.h"

Material::Material(Vector3d color) {
    this->color = color;
}

Vector3d Material::getColor() const {
    return this->color;
}