//
// Created by alejandro10213 on 13/05/2025.
//

#ifndef HERO_H
#define HERO_H

#include "Character.h"

class Hero : public Character {
public:
    Hero(const std::string &name, const Attribute &attributes, const Weapon &weapon, const Armor &armor);
    void setHp(int hp);
};



#endif //HERO_H
