//
// Created by alejandro10213 on 22/05/2025.
//

#ifndef SOLDIER_H
#define SOLDIER_H

#include "Enemy.h"

class Soldier : public Enemy {
public:
    Soldier(const std::string &name, const Attribute &attributes, const Weapon &weapon, const Armor &armor);
};



#endif //SOLDIER_H
