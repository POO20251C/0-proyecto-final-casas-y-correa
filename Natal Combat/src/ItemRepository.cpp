//
// Created by Juan on 24/05/2025.
//

#include "../include/ItemRepository.h"

#include <iostream>
#include <stdexcept>
#include <bits/ostream.tcc>


ItemRepository::ItemRepository() {
    // Ataques
    attacks.emplace_back("Golpe fuerte", "", 1.1, 45);
    attacks.emplace_back("hola", "", 5, 100);

    // Armaduras
    armors.emplace_back("Sin armadura", 0);
    armors.emplace_back("Armadura de Hierro", 60);
    armors.emplace_back("Armadura de Acero", 70);
    armors.emplace_back("Armadura de Cuero Reforzado", 45);
    armors.emplace_back("Armadura de Cadena", 55);
    armors.emplace_back("Armadura de Plata", 65);
    armors.emplace_back("Armadura de Bronce", 50);
    armors.emplace_back("Armadura de Titanio", 80);
    armors.emplace_back("Armadura de Escamas", 40);
    armors.emplace_back("Armadura de Laton", 48);
    armors.emplace_back("Armadura de Placas", 75);


    // Armas
    weapons.emplace_back("Sin arma", 0, 0);
    weapons.emplace_back("Espada de Hierro", 10, 10);
    weapons.emplace_back("Espada Larga de Acero", 65, 10);
    weapons.emplace_back("Hacha de Mano", 55, 10);
    weapons.emplace_back("Lanza de Madera Reforzada", 40, 10);
    weapons.emplace_back("Maza de Bronce", 60, 10);
    weapons.emplace_back("Daga Curva", 45, 10);
    weapons.emplace_back("Martillo de Guerra", 70, 10);
    weapons.emplace_back("Arco de Cazador", 50, 10);
    weapons.emplace_back("Ballesta Liviana", 55, 10);
    weapons.emplace_back("Espada Bastarda", 75, 10);

    // heroes
    // Alejo
    try {
        std::string name = "Alejo";
        Armor armor = this->getArmorByName("Armadura de Hierro");
        Weapon weapon = this->getWeaponByName("Espada de Hierro");

        std::cout << "Alejo " << armor.getName() << std::endl;
        Attribute attribute = Attribute(100, 40, 50, 10, 20);

        Hero hero(name, attribute);
        hero.equipArmor(armor);
        hero.equipWeapon(weapon);
        hero.addAttack(this->getAttackByName("Golpe fuerte"));
        hero.addAttack(this->getAttackByName("hola"));
        heroes.push_back(hero);
    } catch (std::runtime_error & e) {
        std::cout << e.what() << std::endl;
    }

    try {
        std::string name = "c";
        Armor armor = this->getArmorByName("Armadura de Hierro");
        Weapon weapon = this->getWeaponByName("Espada de Hierro");
        Attribute attribute = Attribute(100, 40, 50, 10, 20);

        Hero hero(name, attribute);
        hero.equipArmor(armor);
        hero.equipWeapon(weapon);
        hero.addAttack(this->getAttackByName("Golpe fuerte"));
        heroes.push_back(hero);
    } catch (std::runtime_error & e) {
        std::cout << e.what() << std::endl;
    }

    try {
        std::string name = "b";
        Armor armor = this->getArmorByName("Armadura de Hierro");
        Weapon weapon = this->getWeaponByName("Espada de Hierro");
        Attribute attribute = Attribute(100, 40, 50, 10, 20);

        Hero hero(name, attribute);
        hero.equipArmor(armor);
        hero.equipWeapon(weapon);
        hero.addAttack(this->getAttackByName("Golpe fuerte"));
        heroes.push_back(hero);
    } catch (std::runtime_error & e) {
        std::cout << e.what() << std::endl;
    }
}

Armor ItemRepository::getArmorByName(const std::string &name) const {
    for (const auto armor : armors) {
        if (armor.getName() == name) {
            return armor;
        }
    }

    throw std::runtime_error("No se encontro la armadura " + name);
}

Weapon ItemRepository::getWeaponByName(const std::string &name) const {
    for (const auto weapon : weapons) {
        if (weapon.getName() == name) {
            return weapon;
        }
    }

    throw std::runtime_error("No se encontro el arma " + name);
}

Hero ItemRepository::getHeroByName(const std::string &name) const {
    for (const auto hero : heroes) {
        if (hero.getName() == name) {
            return hero;
        }
    }

    throw std::runtime_error("No se encontro el heroe " + name);
}

Attack ItemRepository::getAttackByName(const std::string &name) const {
    for (const auto attack : attacks) {
        if (attack.getName() == name) {
            return attack;
        }
    }

    throw std::runtime_error("No se encontro el ataque " + name);
}

ItemRepository &ItemRepository::getInstance() {
    static ItemRepository instance;
    return instance;
}


std::vector<Hero> ItemRepository::getHeroes() const {
    return heroes;
}