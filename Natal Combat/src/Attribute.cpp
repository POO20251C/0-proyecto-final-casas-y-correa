//
// Created by alejandro10213 on 12/05/2025.
//

#include "../include/Attribute.h"
#include <iostream>

Attribute::Attribute(int max_hp, int atk, int def, int spd, int lck) {
    this -> max_hp = max_hp;
    this -> hp = max_hp;
    this -> atk = atk;
    this -> def = def;
    this -> spd = spd;

    if (lck > 50) {
        lck = 50;
    }

    this -> lck = lck;
}

int Attribute::getHp() const {
    return hp;
}

int Attribute::getMax_hp() const {
    return max_hp;
}

int Attribute::getAtk() const {
    return atk;
}

int Attribute::getDef() const {
    return def;
}

int Attribute::getSpd() const {
    return spd;
}

int Attribute::getLck() const {
    return lck;
}

void Attribute::increaseAttribute(const std::string &name, int amount) {

    std::cout << name << ": " << std::to_string(amount) << std::endl;

    if (name == "max_hp") {
        this -> max_hp += amount;

    } else if (name == "hp") {
        this -> hp += amount;

        if (hp < 0) {
            this -> hp = 0;
        } else if (hp > max_hp) {
            this -> hp = max_hp;
        }

    } else if (name == "atk") {
        this -> atk += amount;

    } else if (name == "def") {
        std::cout << "vijejo" << std::to_string(this -> def) << std::endl;
        this -> def += amount;

        std::cout << "nuevo: " << std::to_string(amount) << " "<< std::to_string(this -> def) << std::endl;

    } else if (name == "spd") {
        this -> spd += amount;

    } else if (name == "lck") {
        this -> lck += amount;
    }
}

void Attribute::setHp(int hp) {
    this -> hp = hp;
}
