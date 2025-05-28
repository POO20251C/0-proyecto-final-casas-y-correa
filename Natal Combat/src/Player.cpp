//
// Created by alejandro10213 on 14/05/2025.
//


#include "../include/Player.h"

#include <algorithm>
#include <stdexcept>
#include <iostream>

Player::Player(const std::string &name){

    ItemRepository& itemRepository = ItemRepository::getInstance();


    this->name = name;
    //inventory = Inventory();
    //money = 100;

    Weapon wea = itemRepository.getWeaponByName("Espada de Hierro");
    Weapon wea1 = itemRepository.getWeaponByName("Hacha de Mano");


    this->getInventory().addWeapon(wea);
    this->getInventory().addWeapon(wea1);
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

// Falta manejar las excepciones para usePotion :(
void Player::usePotion(Hero& hero) {
    if (!inventory.getPotions().empty()) {
        if (hero.getAttributes().getHp() > 0) {
            hero.cureHero(inventory.getPotions()[0].getCure());
        }
    }
}
