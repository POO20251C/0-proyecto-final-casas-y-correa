//
// Created by alejandro10213 on 12/05/2025.
//

#include "../include/Weapon.h"

Weapon::Weapon(const std::string &name, int atk, int bleed) {
    this -> name = name;
    this -> atk = atk;
    this -> bleed = bleed;
}

std::string Weapon::getName() const {
    return name;
}

int Weapon::getAtk() const {
    return atk;
}