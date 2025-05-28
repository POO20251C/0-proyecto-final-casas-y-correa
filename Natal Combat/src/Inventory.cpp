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
