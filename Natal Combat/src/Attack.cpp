#include "../include/Attack.h"

Attack::Attack(const std::string &name, float power, int accuracy) {
    this->name = name;
    this->power = power;

    if (accuracy > 70) {
        accuracy = 70;
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

