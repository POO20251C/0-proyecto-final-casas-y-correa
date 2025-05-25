//
// Created by alejandro10213 on 12/05/2025.
//

#include "../include/Attack.h"

Attack::Attack(const std::string &name, const std::string &action, int dmg, int accuracy) {
    this->name = name;
    this->action = action;
    this->dmg = dmg;
    this->accuracy = accuracy;
}

std::string Attack::getName() const {
    return name;
}

int Attack::getAccuracy() const {
    return accuracy;
}

int Attack::getDmg() const {
    return dmg;
}

