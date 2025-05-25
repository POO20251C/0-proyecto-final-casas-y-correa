#ifndef CHARACTER_H
#define CHARACTER_H

#include <vector>
#include <string>

#include "Attribute.h"
#include "Weapon.h"
#include "Armor.h"
#include "Attack.h"

class Character {
protected:
    std::string name;
    Attribute attributes;
    Weapon weapon;
    Armor armor;
    std::vector<Attack> attacks;

    int calcDamage(int damage, int k) const;

public:
    Character() = default;
    Character(const std::string &name, const Attribute &attributes);

    std::string getName() const;
    Attribute getAttributes() const;
    Weapon getWeapon() const;
    Armor getArmor() const;

    std::vector<Attack> getAttacks() const;

    void equipArmor(const Armor &armor);
    void unequipArmor();

    void equipWeapon(const Weapon &weapon);
    void unequipWeapon();

    void addAttack(const Attack &attack);

    void receiveDamage(int dmg);
};



#endif