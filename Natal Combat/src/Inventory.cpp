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
    weapons.push_back(weapon);
}
