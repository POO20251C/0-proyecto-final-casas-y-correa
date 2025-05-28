//
// Created by caren on 21/05/2025.
//

#include "../include/Reward.h"

Reward::Reward(const std::string& name) {
    this -> name = name;
}

std::string Reward::getName() {
    return name;
}

std::vector<Armor> Reward::getArmors() {
    return armors;
}

std::vector<Potion> Reward::getPotions() {
    return potions;
}

std::vector<Weapon> Reward::getWeapons() {
    return weapons;
}

void Reward::addArmor(Armor& armor) {
    armors.push_back(armor);
}

void Reward::addPotion(Potion& potion) {
    potions.push_back(potion);
}

void Reward::addWeapon(Weapon& weapon) {
    weapons.push_back(weapon);
}
