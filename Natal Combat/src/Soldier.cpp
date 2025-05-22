//
// Created by alejandro10213 on 22/05/2025.
//

#include "../include/Soldier.h"

Soldier::Soldier(const std::string &name, const Attribute &attributes, const Weapon &weapon, const Armor &armor) : Enemy(name, attributes, weapon, armor) {}