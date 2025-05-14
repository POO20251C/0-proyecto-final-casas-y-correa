//
// Created by alejandro10213 on 12/05/2025.
//

#include "../include/Armor.h"

Armor::Armor(const std::string &name, const std::string &desc, int def) {
    this->name = name;
    this->desc = desc;
    this->def = def;
}

std::string Armor::getName() const {
    return name;
}

std::string Armor::getDesc() const {
    return desc;
}

int Armor::getDef() const {
    return def;
}
