//
// Created by alejandro10213 on 12/05/2025.
//

#include "../include/Weapon.h"

Weapon::Weapon(const std::string &name, const std::string &desc, int atk, int bleed) {
    this -> name = name;
    this -> desc = desc;
    this -> atk = atk;
    this -> bleed = bleed;
}

std::string Weapon::getName() const {
    return name;
}

std::string Weapon::getDesc() const {
    return desc;
}

int Weapon::getAtk() const {
    return atk;
}