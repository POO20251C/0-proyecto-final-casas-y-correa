//
// Created by caren on 21/05/2025.
//

#include "../include/Inventory.h"

Inventory::Inventory() = default;

void Inventory::addObject(Object element) {
    objects.push_back(element);
}

std::vector<Object> Inventory::getObjects() {
    return objects;
}

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
