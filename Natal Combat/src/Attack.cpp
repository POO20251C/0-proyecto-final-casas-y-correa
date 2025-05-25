//
// Created by alejandro10213 on 12/05/2025.
//

#include "../include/Attack.h"

Attack::Attack(const std::string &name, const std::string &action, float power, int accuracy) {
    this->name = name;
    this->action = action;
    this->power = power;

    if (accuracy > 50) {
        accuracy = 50;
    }

    this->accuracy = accuracy;
}

std::string Attack::getName() const {
    return name;
}

int Attack::getAccuracy() const {
    return accuracy;
}

float Attack::getPower() const {
    return power;
}

