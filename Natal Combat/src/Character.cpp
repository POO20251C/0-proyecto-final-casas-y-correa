#include "../include/Character.h"
#include "../include/ItemRepository.h"

#include <cmath>
#include <iostream>
#include <stdexcept>

Character::Character(const std::string &name, const Attribute &attributes) {
    this->name = name;
    this->attributes = attributes;
}

void Character::initEquipment() {
    ItemRepository& itemRepository = ItemRepository::getInstance();
    this->armor = itemRepository.getArmorByName("Sin armadura");
    this->weapon = itemRepository.getWeaponByName("Sin arma");
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

Weapon& Character::getWeapon() {
    return weapon;
}

std::vector<Attack> Character::getAttacks() const {
    return attacks;
}

Attack Character::getAttackByIndex(int index) const {
    return attacks[index];
}


std::string Character::equipArmor(const Armor &_armor) {
    if (armor.getName() == _armor.getName()) {
        return "Ya tienes esa armadura equipada.";
    }

    if (armor.getName() != "Sin armadura" && !armor.getName().empty()) {
        this->unequipArmor();
    }

    this -> armor = _armor;
    attributes.increaseAttribute("def", armor.getDef());
    return "La armadura fue equipada exitosamente.";
}

void Character::unequipArmor() {
    attributes.increaseAttribute("def", -armor.getDef());
}

std::string Character::equipWeapon(const Weapon &_weapon) {
    if (weapon.getName() == _weapon.getName()) {
        return "Ya tienes esa arma equipada.";
    }

    if (weapon.getName() != "Sin arma" && !weapon.getName().empty()) {
        this->unequipWeapon();
    }

    this -> weapon = _weapon;
    attributes.increaseAttribute("atk", weapon.getAtk());

    return "El arma fue equipada exitosamente.";
}

void Character::unequipWeapon() {
    attributes.increaseAttribute("atk", -weapon.getAtk());
}

void Character::addAttack(const Attack &attack) {
    attacks.push_back(attack);
}

int Character::calcRealDamage(int damage, int k = 100) const {
    double numerator = damage * k;
    double denominator = k + getArmor().getDef();

    int result = static_cast<int>(std::ceil(numerator / denominator));

    return result;
}

int Character::getAttackDamage(const Attack &attack) const {
    float powerAttack = attack.getPower();
    int baseAtk = attributes.getAtk();

    return baseAtk * powerAttack;
}


int Character::receiveDamage(int dmg) {
    dmg = calcRealDamage(dmg);
    attributes.increaseAttribute("hp", -dmg);

    return dmg;
}

Attack Character::getRandomAttack() const {
    if (attacks.empty()) {
        throw std::runtime_error("No hay ataques disponibles.");
    }

    int index = rand() % attacks.size();
    return attacks[index];
}


