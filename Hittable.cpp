#include "Material.h"
#include "Hittable.h"
#include <iostream>

Hittable::Hittable() {

}

Hittable::Hittable(Material material) {
    this->m_material = material;
}

Material Hittable::getMaterial() const {
    return this->m_material;
}

