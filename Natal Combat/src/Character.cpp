#include "../include/Character.h"

Character::Character(const std::string &name, const Attribute &attributes) {
    this->name = name;
    this->attributes = attributes;
    this -> armor = Armor("Sin armadura", 0);
    this -> weapon = Weapon("Sin arma", 0, 0);
}

std::string Character::getName() const {
    return name;
}

Attribute Character::getAttributes() const {
    return attributes;
}

Armor Character::getArmor() const {
    return armor;
}

Weapon Character::getWeapon() const {
    return weapon;
}

std::vector<Attack> Character::getAttacks() const {
    return attacks;
}

void Character::equipArmor(const Armor &_armor) {
    if (armor.getName() != "Sin armadura") {
        this->unequipArmor();
    }

    this -> armor = _armor;
    attributes.increaseAttribute("def", armor.getDef());
}

void Character::unequipArmor() {
    attributes.increaseAttribute("def", -armor.getDef());
}

void Character::equipWeapon(const Weapon &_weapon) {
    this->unequipWeapon();

    this -> weapon = _weapon;
    attributes.increaseAttribute("atk", weapon.getAtk());
}

void Character::unequipWeapon() {
    attributes.increaseAttribute("atk", -weapon.getAtk());
}

void Character::addAttack(const Attack &attack) {
    attacks.push_back(attack);
}

int Character::calcDamage(int damage, int k = 100) const {
    return damage * k /(k + this->getArmor().getDef());
}


void Character::receiveDamage(int dmg) {
    dmg = calcDamage(dmg);
    attributes.increaseAttribute("hp", -dmg);
}
