//
// Created by alejandro10213 on 13/05/2025.
//

#ifndef HERO_H
#define HERO_H

#include "Character.h"
#include "Enemy.h"

class Hero : public Character {
public:
    Hero(const std::string &name, const Attribute &attributes);
    void attack(const std::string &attack, const Enemy &enemy);
};



#endif //HERO_H
