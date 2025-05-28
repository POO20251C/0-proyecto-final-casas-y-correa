//
// Created by caren on 21/05/2025.
//

#include "../include/Inventory.h"

Inventory::Inventory() = default;

std::vector<Weapon>& Inventory::getWeapons() {
    return weapons;
}

std::vector<Armor>& Inventory::getArmors() {
    return armors;
}

std::vector<Potion>& Inventory::getPotions() {
    return potions;
}

void Inventory::addWeapon(Weapon &weapon) {
    if (weapon.getName() != "Sin arma") {
        for (const auto& w : weapons) {
            if (w.getName() == weapon.getName()) {
                return;
            }
        }

        weapons.push_back(weapon);
    }
}

void Inventory::removeWeapon(Weapon &weapon) {
    for (auto it = weapons.begin(); it != weapons.end(); ++it) {
        if (it->getName() == weapon.getName()) {
            weapons.erase(it);
            return;
        }
    }
}

void Inventory::addArmor(Armor &armor) {
    if (armor.getName() != "Sin armadura") {
        for (const auto& arm : armors) {
            if (arm.getName() == armor.getName()) {
                return;
            }
        }

        armors.push_back(armor);
    }
}

void Inventory::removeArmor(Armor &armor) {
    for (auto it = armors.begin(); it != armors.end(); ++it) {
        if (it->getName() == armor.getName()) {
            armors.erase(it);
            return;
        }
    }
}

void Inventory::addPotion(Potion &potion) {
    for (auto &p : potions) {
        if (p.getName() == potion.getName()) {
            p.increaseStack(1);
            return;
        }
    }

    potions.push_back(potion);
}

void Inventory::removePotion(Potion &potion) {
    for (auto it = potions.begin(); it != potions.end(); ++it) {
        if (it->getName() == potion.getName()) {
            it->increaseStack(-1);

            if (it->getStack() <= 0) {
                potions.erase(it);
            }

            return;
        }
    }
}
