#ifndef CHARACTER_H
#define CHARACTER_H

#include <map>
#include <string>

#include "Attribute.h"
#include "Weapon.h"
#include "Armor.h"

class Character {
    std::string name;
    std::map<std::string, Attribute> attributes;
    Weapon weapon;
    Armor armor;
public:
    Character(std::string, Weapon weapon, Armor armor);
};



#endif