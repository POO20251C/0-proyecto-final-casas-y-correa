//
// Created by alejandro10213 on 14/05/2025.
//


#include "../include/Player.h"

Player::Player(const std::string &name){
    this->name = name;
    inventory = Inventory();
}

std::vector<Hero> Player::getHeroes() {
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

    return hero.getName() + " ha sido agregado.";
}

Hero Player::getLowSpeedHero() const {
    Hero hero = heroes[0];
    for (const auto &h : heroes) {
        if (h.getAttributes().getSpd() < hero.getAttributes().getSpd()) {
            hero = h;
        }
    }

    return hero;
}

Hero Player::getHero(const std::string &name) const {
    throw "No se encontró el héroe " + name + ".";
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