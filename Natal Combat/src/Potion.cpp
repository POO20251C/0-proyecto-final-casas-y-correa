//
// Created by caren on 26/05/2025.
//

#include "../include/Potion.h"

Potion::Potion(const std::string &name, const std::string &type, int stack) {
    this -> name = name;
    this -> type = type;
    this -> stack = stack;
}

void Potion::increaseStack(int amount) {
    stack += amount;
}

std::string Potion::getName() const {
    return name;
}

int Potion::getStack() {
    return stack;
}

std::string Potion::getType() {
    return type;
}

int Potion::getAmount() {
    return amount;
}


std::string Potion::usePotion(Hero &hero) {
    if (type == "Health") {
        int healAmount = amount;
        int currentHp = hero.getAttributes().getHp();
        int maxHp = hero.getAttributes().getMax_hp();

        int currentHeal = std::min(healAmount, maxHp - currentHp);
        if (currentHeal <= 0) {
            return "El heroe ya tiene la vida al maximo.";
        }

        hero.getAttributes().increaseAttribute("hp", currentHeal);

        return "El heroe ha recuperado " + std::to_string(currentHeal) + " de vida.";
    }

    return "Esta pocion no se puede usar.";
}
