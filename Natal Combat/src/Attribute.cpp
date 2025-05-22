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
void Attribute::setHp(int hp) {
    this->hp = hp;
}