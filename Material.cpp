#include "Material.h"

Material::Material() {
    this->type = 0;
}

Material::Material(int type) {
    this->type = type;
}

int Material::getType() const {
    return this->type;
}