//
// Created by alejandro10213 on 12/05/2025.
//

#include "../include/Armor.h"

Armor::Armor(const std::string &name, int def) {
    this->name = name;
    this->def = def;
}

std::string Armor::getName() const {
    return name;
}

int Armor::getDef() const {
    return def;
}
