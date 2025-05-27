//
// Created by alejandro10213 on 12/05/2025.
//

#include "../include/Weapon.h"

Weapon::Weapon(const std::string &name, int atk, int bleed) {
    this -> name = name;
    this -> atk = atk;
    this -> bleed = bleed;
    this -> value = 0;
}

std::string Weapon::getName() const {
    return name;
}

int Weapon::getAtk() const {
    return atk;
}

int Weapon::getValue() {
    return value;
}

void Weapon::setValue(int value) {
    this->value = value;
}
