#include "../include/Potion.h"

Potion::Potion(const std::string &name, const std::string &type, int amount) {
    this -> name = name;
    this -> type = type;
    this -> amount = amount;
    this -> stack = 1;
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


bool Potion::usePotion(Hero &hero) {
    if (type == "Health") {
        int maxHp = hero.getAttributes().getMax_hp();
        int currentHp = hero.getAttributes().getHp();

        int healAmount = (maxHp * amount) / 100;

        int currentHeal = std::min(healAmount, maxHp - currentHp);
        if (currentHeal <= 0) {
            return false;
        }

        hero.getAttributes().increaseAttribute("hp", currentHeal);
        return true;
    }

    return false;
}

