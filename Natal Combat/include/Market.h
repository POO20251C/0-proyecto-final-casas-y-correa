//
// Created by caren on 26/05/2025.
//

#ifndef MARKET_H
#define MARKET_H

#include "inventory.h"
#include "Potion.h"
#include "Weapon.h"
#include "Armor.h"
#include "Hero.h"

#include "Player.h"

#include <vector>
#include <string>
#include <stdexcept>

class Market {
private:
    std::string name;

    std::vector<Potion> potions;
    std::vector<Weapon> weapons;
    std::vector<Armor> armors;

    void loadMarket();
    void removeWeapon(const Weapon& weapon);
    void removeArmor(Armor& armor);
    void removePotion(Potion& potion);

    Weapon& getWeaponByName(const std::string& name);
public:
    Market(const std::string& name);
    std::vector<Potion> getPotions();
    std::vector<Weapon>& getWeapons();
    std::vector<Armor>& getArmors();

    std::string buyWeapon(Hero& hero, const std::string& name);
    std::string buyArmor(Hero& hero, const std::string& name);

    std::string getName();

    std::string buyPotion(Inventory& invent, int& money, int cuant);
};



#endif //MARKET_H
