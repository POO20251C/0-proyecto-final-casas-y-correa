//
// Created by alejandro10213 on 13/05/2025.
//

#include "../include/Hero.h"

Hero::Hero(const std::string &name, Attribute attributes, Weapon weapon, Armor armor) {
    this -> name = name;
    this -> attributes = attributes;
    this -> weapon = weapon;
    this -> armor = armor;
}