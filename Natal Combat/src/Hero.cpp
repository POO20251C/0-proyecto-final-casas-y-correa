//
// Created by alejandro10213 on 13/05/2025.
//

#include "../include/Hero.h"

Hero::Hero(const std::string &name, const Attribute &attributes) {
    this->name = name;
    this->attributes = attributes;
}

void Hero::cureHero(int cure) {
    if (attributes.getHp() + cure < attributes.getMax_hp()) {
        attributes.setHp(attributes.getHp() + cure);
    }
    else {
        attributes.setHp(attributes.getMax_hp());
    }
}
