//
// Created by Juan on 24/05/2025.
//

#ifndef ITEMREPOSITORY_H
#define ITEMREPOSITORY_H

#include <vector>

#include "Armor.h"
#include "Weapon.h"
#include "Hero.h"
#include "Attack.h"
#include "Potion.h"

class ItemRepository {
private:
    std::vector<Armor> armors;
    std::vector<Weapon> weapons;
    std::vector<Hero> heroes;
    std::vector<Attack> attacks;
    std::vector<Potion> potions;

    ItemRepository();


public:
    static ItemRepository& getInstance();

    Armor getArmorByName(const std::string &name);
    Weapon getWeaponByName(const std::string &name);
    Hero getHeroByName(const std::string &name);
    Attack getAttackByName(const std::string &name);
    Potion getPotionByName(const std::string &name);

    std::vector<Hero> getHeroes() const;
};



#endif //ITEMREPOSITORY_H
