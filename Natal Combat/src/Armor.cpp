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