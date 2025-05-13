

#include "../include/Character.h"

Character::Character(const std::string &name, Attribute attributes, Weapon weapon, Armor armor) {
    this->name = name;
    this->attributes = attributes;
    this->weapon = weapon;
    this->armor = armor;
}

std::string Character::getName() {
    return name;
}
