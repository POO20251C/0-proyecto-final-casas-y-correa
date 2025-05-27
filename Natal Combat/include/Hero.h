//
// Created by alejandro10213 on 13/05/2025.
//

#ifndef HERO_H
#define HERO_H

#include "Character.h"

class Hero : public Character {
public:
    Hero() = default;
    Hero(const std::string &name, const Attribute &attributes);
};



#endif //HERO_H
