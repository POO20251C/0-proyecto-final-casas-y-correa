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

    int calcRealDamage(int damage, int k) const;

public:
    Character() = default;
    Character(const std::string &name, const Attribute &attributes);

    std::string getName() const;

    Attribute& getAttributes();
    Weapon& getWeapon();
    Armor getArmor() const;

    std::vector<Attack> getAttacks() const;

    Attack getAttackByIndex(int index) const;
    Attack getRandomAttack() const;

    int getAttackDamage(const Attack& attack) const;

    void initEquipment();

    std::string equipArmor(const Armor &armor);
    void unequipArmor();

    std::string equipWeapon(const Weapon &weapon);
    void unequipWeapon();

    void addAttack(const Attack &attack);

    int receiveDamage(int dmg);
};



#endif