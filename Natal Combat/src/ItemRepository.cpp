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

    // pociones
    potions.emplace_back("Pocion Pequena de Salud", "Health", 10);
    potions.emplace_back("Pocion Mediana de Salud", "Health", 25);
    potions.emplace_back("Pocion Grande de Salud", "Health", 50);
    potions.emplace_back("Elixir de Salud", "Health", 100);


    try {
        std::string name1 = "a";
        Attribute attribute1(100, 40, 50, 10, 20);
        Hero hero1(name1, attribute1);
        hero1.equipArmor(this->getArmorByName("Sin armadura"));
        hero1.equipWeapon(this->getWeaponByName("Sin arma"));
        heroes.push_back(hero1);

        std::string name2 = "b";
        Attribute attribute2(80, 60, 70, 15, 25);
        Hero hero2(name2, attribute2);
        hero2.equipArmor(this->getArmorByName("Sin armadura"));
        hero2.equipWeapon(this->getWeaponByName("Sin arma"));
        heroes.push_back(hero2);

        std::string name3 = "c";
        Attribute attribute3(120, 30, 40, 20, 15);
        Hero hero3(name3, attribute3);
        hero3.equipArmor(this->getArmorByName("Sin armadura"));
        hero3.equipWeapon(this->getWeaponByName("Sin arma"));
        heroes.push_back(hero3);

        std::string name4 = "d";
        Attribute attribute4(90, 50, 60, 12, 22);
        Hero hero4(name4, attribute4);
        hero4.equipArmor(this->getArmorByName("Sin armadura"));
        hero4.equipWeapon(this->getWeaponByName("Sin arma"));
        heroes.push_back(hero4);

        std::string name5 = "e";
        Attribute attribute5(110, 35, 45, 18, 17);
        Hero hero5(name5, attribute5);
        hero5.equipArmor(this->getArmorByName("Sin armadura"));
        hero5.equipWeapon(this->getWeaponByName("Sin arma"));
        heroes.push_back(hero5);

    } catch (std::runtime_error &e) {
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

Potion ItemRepository::getPotionByName(const std::string &name) const {
    for (auto potion : potions) {
        if (potion.getName() == name) {
            return potion;
        }
    }

    throw std::runtime_error("No se encontro la pocion " + name);
}


ItemRepository &ItemRepository::getInstance() {
    static ItemRepository instance;
    return instance;
}


std::vector<Hero> ItemRepository::getHeroes() const {
    return heroes;
}