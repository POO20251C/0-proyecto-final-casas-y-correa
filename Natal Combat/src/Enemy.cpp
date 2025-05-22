//
// Created by alejandro10213 on 22/05/2025.
//

#include "../include/Enemy.h"

Enemy::Enemy(const std::string &name, const Attribute &attributes, const Weapon &weapon, const Armor &armor) {
    this -> name = name;
    this -> attributes = attributes;
    this -> weapon = weapon;
    this -> armor = armor;
}
