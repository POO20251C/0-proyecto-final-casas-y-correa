//
// Created by caren on 21/05/2025.
//

#ifndef CHEST_H
#define CHEST_H

#include "Potion.h"
#include "Armor.h"
#include "Weapon.h"

#include <string>
#include <vector>


class Reward {
private:
    std::string name;

    std::vector<Armor> armors;
    std::vector<Weapon> weapons;
    std::vector<Potion> potions;
public:
    Reward() = default;
    Reward(const std::string& name);

    std::string getName();

    std::vector<Armor> getArmors();
    std::vector<Weapon> getWeapons();
    std::vector<Potion> getPotions();

    void addArmor(Armor& armor);
    void addWeapon(Weapon& weapon);
    void addPotion(Potion potion);
};

#endif //CHEST_H