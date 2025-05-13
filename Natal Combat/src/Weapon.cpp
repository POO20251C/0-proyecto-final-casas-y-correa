//
// Created by alejandro10213 on 12/05/2025.
//

#include "../include/Weapon.h"

Weapon::Weapon(const std::string &name, const std::string &desc, int bleed) {
    this -> name = name;
    this -> desc = desc;
    this -> bleed = bleed;
}
