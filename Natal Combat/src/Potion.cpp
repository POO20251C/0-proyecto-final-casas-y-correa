//
// Created by caren on 26/05/2025.
//

#include "../include/Potion.h"

Potion::Potion(const std::string &name, const std::string &type, int stack) {
    this -> name = name;
    this -> type = type;
    this -> stack = stack;
}

std::string Potion::getName() {
    return this->name;
}