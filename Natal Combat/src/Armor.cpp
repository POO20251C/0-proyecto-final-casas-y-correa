//
// Created by alejandro10213 on 12/05/2025.
//

#include "../include/Armor.h"

Armor::Armor(const std::string &name, int def) {
    this->name = name;
    this->def = def;
    this->value = 0;
}

std::string Armor::getName() const {
    return name;
}

int Armor::getDef() const {
    return def;
}

int Armor::getValue() const {
    return value;
}

void Armor::setValue(int value) {
    this->value = value;
}