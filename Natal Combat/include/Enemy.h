//
// Created by alejandro10213 on 22/05/2025.
//

#ifndef ENEMY_H
#define ENEMY_H

#include "Character.h"
#include "Weapon.h"
#include "Armor.h"


class Enemy : public Character {
public:
    Enemy() = default;
    Enemy(const std::string &name, const Attribute &attributes, const Weapon &weapon, const Armor &armor, int rank);

    int getRank() const;
private:
    int rank;
};



#endif //ENEMY_H