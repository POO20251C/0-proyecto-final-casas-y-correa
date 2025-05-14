//
// Created by alejandro10213 on 14/05/2025.
//

#include "../include/Player.h"

Player::Player(std::vector<Hero> &heroes) {
    this -> heroes = heroes;
}

std::vector<Hero> Player::getHeroes() {
    return heroes;
}
