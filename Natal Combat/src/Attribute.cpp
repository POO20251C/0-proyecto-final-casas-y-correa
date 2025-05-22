//
// Created by alejandro10213 on 12/05/2025.
//

#include "../include/Attribute.h"

Attribute::Attribute(int hp, int mhp, int atk, int def, int spd, int lck) {
    this -> hp = hp;
    this -> atk = atk;
    this -> def = def;
    this -> spd = spd;
    this -> lck = lck;
    this -> mhp = mhp;
}

int Attribute::getHp() const {
    return hp;
}

int Attribute::getMhp() const {
    return mhp;
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