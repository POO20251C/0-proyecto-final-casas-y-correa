#ifndef CHARACTER_H
#define CHARACTER_H

#include <map>
#include <string>

#include "Attribute.h"
#include "Weapon.h"
#include "Armor.h"

class Character {
protected:
    std::string name;
    Attribute attributes;
    Weapon weapon;
    Armor armor;
public:
    Character() = default;
    Character(const std::string &name, const Attribute &attributes, const Weapon &weapon, const Armor &armor);

    std::string getName() const;
    Attribute getAttributes() const;
    Weapon getWeapon() const;
    Armor getArmor() const;
};



#endif