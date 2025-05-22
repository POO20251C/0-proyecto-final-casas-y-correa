//
// Created by alejandro10213 on 22/05/2025.
//

#ifndef ENEMY_H
#define ENEMY_H

#include "Character.h"


class Enemy : public Character {
public:
    Enemy(const std::string &name, const Attribute &attributes, const Weapon &weapon, const Armor &armor);
};



#endif //ENEMY_H