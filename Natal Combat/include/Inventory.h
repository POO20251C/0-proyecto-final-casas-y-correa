//
// Created by caren on 21/05/2025.
//

#ifndef INVENTORY_H
#define INVENTORY_H

#include "Weapon.h"
#include "Potion.h"
#include "Armor.h"

#include <vector>

class Inventory {
private:
    std::vector<Weapon> weapons;
    std::vector<Potion> potions;
    std::vector<Armor> armors;
public:
    //constructores
    Inventory();

    //getters
    std::vector<Weapon>& getWeapons();
    std::vector<Potion>& getPotions();
    std::vector<Armor>& getArmors();
    //metodos

    void addWeapon(Weapon& weapon);
};



#endif //INVENTORY_H
