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

class ItemRepository {
private:
    std::vector<Armor> armors;
    std::vector<Weapon> weapons;
    std::vector<Hero> heroes;
    std::vector<Attack> attacks;

    ItemRepository();


public:
    static ItemRepository& getInstance();

    Armor getArmorByName(const std::string &name) const;
    Weapon getWeaponByName(const std::string &name) const;
    Hero getHeroByName(const std::string &name) const;
    Attack getAttackByName(const std::string &name) const;

    std::vector<Hero> getHeroes() const;
};



#endif //ITEMREPOSITORY_H
