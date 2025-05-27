//
// Created by alejandro10213 on 14/05/2025.
//


#include "../include/Player.h"

#include <algorithm>
#include <stdexcept>
#include <iostream>

Player::Player(const std::string &name){

    //ItemRepository& itemRepository = ItemRepository::getInstance();


    this->name = name;
    //inventory = Inventory();
    //money = 100;
}

int Player::getMoney() {
    return money;
}

void Player::setMoney(int money) {
    this->money = money;
}

std::vector<Hero> Player::getHeroes()  {
    return heroes;
}

std::string Player::getName() const {
    return name;
}

bool Player::isHeroExists(const std::string &name) const {
    for (const auto &hero : heroes) {
        if (hero.getName() == name) {
            return true;
        }
    }

    return false;
}

std::string Player::addHero(const Hero &hero) {
    heroes.push_back(hero);

    this->orderHeroes();

    return hero.getName() + " ha sido agregado.";
}

Hero& Player::getHero(const std::string &name) {
    for (auto &hero : heroes) {
        if (hero.getName() == name) {
            return hero;
        }
    }
}

Hero& Player::getHeroByIndex(int index) {
    return heroes[index];
}

Inventory& Player::getInventory() {
    return inventory;
}


bool Player::removeHero(const std::string& name) {
    for (auto it = heroes.begin(); it != heroes.end(); ++it) {
        if (it->getName() == name) {
            heroes.erase(it);
            return true;
        }
    }
    return false;
}

void Player::orderHeroes() {
    std::sort(heroes.begin(), heroes.end(), [](const Hero& a, const Hero& b) {
        return a.getAttributes().getSpd() > b.getAttributes().getSpd();
    });
}

/* ESTA VAINA NO SE COMO HACERLA PORQUE NECESITO ACCEDER AL INVENTARIO Y ENCONTRAR UNA POCION,
   DE AHI NECESITO VER EL .getCure() DE LA POCION PARA PODER HACER EL .cureHero() CON ESE VALOR, PERO COMO
   INVENTORY ES UN VECTOR DE OBJECT Y NO DE POTION ENTONCES ESTE NO TIENE DICHO METODO :(

void Player::usePotion(Hero& hero) {
    bool confirm = false;
    int i = 0;
    while (!confirm && i < inventory.getObjects().size()) {
        if (inventory.getObjects()[i].getName() == "Potion") {
            confirm = true;

        }
        i += 1;
    }
    if (confirm) {
        if (hero.getAttributes().getHp() > 0) {
            hero.cureHero();
        }
    }
}
*/