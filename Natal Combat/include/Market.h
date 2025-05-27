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
#include <vector>
#include <string>
#include <stdexcept>

class Market {
private:
    std::vector<Potion> potions;
    std::vector<Weapon> weapons;
    std::vector<Armor> armors;

public:
    Market();
    std::vector<Potion> getPotions();
    std::vector<Weapon> getWeapons();
    std::vector<Armor> getArmors();

    std::string buyPotion(Inventory& invent, int& money, int cuant);
    void buyWeapon(Hero& hero, int money, int index);
    void buyArmor(Hero& hero, int money, int index);

    std::string showPotions();
    std::string showWeapons();
    std::string showArmors();
    std::string showAll();
};



#endif //MARKET_H
