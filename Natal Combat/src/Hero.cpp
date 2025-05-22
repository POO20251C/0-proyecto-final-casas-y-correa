//
// Created by alejandro10213 on 13/05/2025.
//

#include "../include/Hero.h"

Hero::Hero(const std::string &name, const Attribute &attributes, const Weapon &weapon, const Armor &armor)
    : Character(name, attributes, weapon, armor) {}