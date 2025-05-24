//
// Created by alejandro10213 on 22/05/2025.
//

#include "../include/Room.h"

Room::Room(const Player &player) {
    this -> player = player;
}

void Room::addEnemy(const Enemy &enemy) {
    enemies.push_back(enemy);
}

std::vector<Enemy> Room::getEnemies() const {
    return enemies;
}
