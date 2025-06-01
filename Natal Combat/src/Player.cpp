#include "../include/Player.h"

#include <algorithm>
#include <stdexcept>
#include <iostream>

Player::Player(const std::string &name){
    this -> name = name;
    this -> currentRoom = 0;
    this -> score = 0;
    this -> totalHealthLost = 0;
}

int Player::getCurrentRoom() {
    return currentRoom;
}

std::vector<Hero>& Player::getHeroes()  {
    return heroes;
}

std::string Player::getName() const {
    return name;
}

Hero& Player::getHero(const std::string &name) {
    for (auto &hero : heroes) {
        if (hero.getName() == name) {
            return hero;
        }
    }
}

void Player::increaseCurrentRoom(int amount) {
    currentRoom += amount;
}

void Player::increaseScore(int amount) {
    score += amount;
}

int Player::getScore() const {
    return score;
}

void Player::increaseHealthLost(int amount) {
    totalHealthLost += amount;
}

int Player::getTotalHealthLost() const {
    return totalHealthLost;
}



Hero& Player::getHeroByIndex(int index) {
    return heroes[index];
}

Inventory& Player::getInventory() {
    return inventory;
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
    std::sort(heroes.begin(), heroes.end(), [](Hero& a, Hero& b) {
        return a.getAttributes().getSpd() > b.getAttributes().getSpd();
    });
}

// Falta manejar las excepciones para usePotion :(
void Player::usePotion(Hero& hero) {
    if (!inventory.getPotions().empty()) {
        if (hero.getAttributes().getHp() > 0) {
            //hero.cureHero(inventory.getPotions()[0].getCure());
        }
    }
}

void Player::boostAllStatsByPercentage(int amount) {
    double factor = amount / 100.0;

    for (auto& hero : heroes) {
        hero.getAttributes().increaseAttribute("max_hp", static_cast<int>(hero.getAttributes().getMax_hp() * factor));
        hero.getAttributes().increaseAttribute("atk", static_cast<int>(hero.getAttributes().getAtk() * factor));
        hero.getAttributes().increaseAttribute("def", static_cast<int>(hero.getAttributes().getDef() * factor));
        hero.getAttributes().increaseAttribute("spd", static_cast<int>(hero.getAttributes().getSpd() * factor));
        hero.getAttributes().increaseAttribute("lck", static_cast<int>(hero.getAttributes().getLck() * factor));
    }
}


void Player::restoreFullHealth() {
    for (auto& hero : heroes) {
        hero.getAttributes().increaseAttribute("hp", hero.getAttributes().getMax_hp());
    }
}
