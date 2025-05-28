//
// Created by caren on 26/05/2025.
//

#include "../include/Potion.h"

Potion::Potion(std::string name, std::string category, int stack, int cure, int value) {
    this->name = name;
    this->category = category;
    this->stack = stack;
    this->cure = cure;
    this->value = value;
}

std::string Potion::getName() {
    return this->name;
}
std::string Potion::getCategory() {
    return this->category;
}
int Potion::getStack() {
    return this->stack;
}
int Potion::getCure() {
    return this->cure;
}
int Potion::getValue() {
    return this->value;
}