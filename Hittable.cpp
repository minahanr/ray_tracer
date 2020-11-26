#include "Material.h"
#include "Hittable.h"
#include <iostream>

Hittable::Hittable() {

}

Hittable::Hittable(std::shared_ptr<Material> material) {
    this->m_material = material;
}

std::shared_ptr<Material> Hittable::getMaterial() {
    return this->m_material;
}

