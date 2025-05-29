//
// Created by alejandro10213 on 12/05/2025.
//

#include "../include/Attribute.h"

Attribute::Attribute(int max_hp, int atk, int def, int spd, int lck) {
    this -> max_hp = max_hp;
    this -> hp = max_hp;
    this -> atk = atk;
    this -> def = def;
    this -> spd = spd;

    if (lck > 30) {
        lck = 30;
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
        this -> def += amount;

    } else if (name == "spd") {
        this -> spd += amount;

    } else if (name == "lck") {
        this -> lck += amount;

        if (lck < 0) {
            this -> lck = 0;
        } else if (lck > 30) {
            this -> lck = 30;
        }
    }
}

void Attribute::setHp(int hp) {
    this -> hp = hp;
}
