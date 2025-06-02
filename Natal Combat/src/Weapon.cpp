#include "../include/Weapon.h"

Weapon::Weapon(const std::string &name, int atk) {
    this -> name = name;
    this -> atk = atk;
}

std::string Weapon::getName() const {
    return name;
}

int Weapon::getAtk() const {
    return atk;
}