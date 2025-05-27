//
// Created by caren on 26/05/2025.
//

#include "../include/Potion.h"

Potion::Potion(std::string name, std::string category, int stack, int cure, int value)
    : Object(name, category, stack), cure(cure), value(value) {} // Inicialización en lista de miembros

int Potion::getCure() const {
    return cure;
}

int Potion::getValue() const {
    return value;
}