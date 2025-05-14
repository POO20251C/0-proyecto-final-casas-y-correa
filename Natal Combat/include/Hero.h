//
// Created by alejandro10213 on 13/05/2025.
//

#ifndef HERO_H
#define HERO_H

#include "Character.h"

class Hero : public Character {
public:
    Hero(const std::string &name, Attribute attributes, Weapon weapon, Armor armor);
};



#endif //HERO_H
