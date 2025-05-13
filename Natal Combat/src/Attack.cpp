//
// Created by alejandro10213 on 12/05/2025.
//

#include "../include/Attack.h"

Attack::Attack(const std::string &name, const std::string &desc, std::string &action, int dmg, int accuracy) {
    this->name = name;
    this->desc = desc;
    this->action = action;
    this->dmg = dmg;
    this->accuracy = accuracy;
}
