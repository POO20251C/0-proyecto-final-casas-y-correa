

#include "../include/Character.h"

Character::Character(const std::string &name, const Attribute &attributes, const Weapon &weapon, const Armor &armor) {
    this->name = name;
    this->attributes = attributes;
    this->weapon = weapon;
    this->armor = armor;
}

std::string Character::getName() const {
    return name;
}

Attribute Character::getAttributes() const {
    return attributes;
}

Armor Character::getArmor() const {
    return armor;
}

Weapon Character::getWeapon() const {
    return weapon;
}

