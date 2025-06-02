#include "../include/Market.h"
#include "../include/ItemRepository.h"
Market::Market(const std::string& name) {
    this -> name = name;
    this -> loadMarket();
}

void Market::loadMarket() {
    ItemRepository& repo = ItemRepository::getInstance();

    // Armors
    armors.push_back(repo.getArmorByName("Armadura de Hierro"));

    // Weapons
    weapons.push_back(repo.getWeaponByName("Espada de Hierro"));
}

void Market::removeWeapon(const Weapon &weapon) {
    for (auto it = weapons.begin(); it != weapons.end(); ++it) {
        if (it->getName() == weapon.getName()) {
            weapons.erase(it);
            return;
        }
    }
}

void Market::removeArmor(Armor &armor) {
    for (auto it = armors.begin(); it != armors.end(); ++it) {
        if (it->getName() == armor.getName()) {
            armors.erase(it);
            return;
        }
    }
}



Weapon& Market::getWeaponByName(const std::string &name) {
    for (auto& weapon : weapons) {
        if (weapon.getName() == name) {
            return weapon;
        }
    }

    throw std::runtime_error("No se encontro el arma.");
}

Armor& Market::getArmorByName(const std::string& name) {
    for (auto& armor : armors) {
        if (armor.getName() == name) {
            return armor;
        }
    }

    throw std::runtime_error("No se encontro la armadura.");
}


std::string Market::buyWeapon(Hero& hero, const std::string& name) {
    Weapon& weapon = this->getWeaponByName(name);

    std::string result = hero.equipWeapon(weapon);

    if (result == "El arma fue equipada exitosamente.") {
        // remover del mercado
        this->removeWeapon(weapon);
    }

    return result;
}

std::string Market::buyArmor(Hero &hero, const std::string &name) {
    Armor& armor = this->getArmorByName(name);

    std::string result = hero.equipArmor(armor);

    if (result == "La armadura fue equipada exitosamente.") {
        // remover del mercado
        this->removeArmor(armor);
    }

    return result;
}

std::string Market::getName() {
    return name;
}

std::vector<Weapon>& Market::getWeapons() {
    return weapons;
}

std::vector<Armor>& Market::getArmors() {
    return armors;
}
