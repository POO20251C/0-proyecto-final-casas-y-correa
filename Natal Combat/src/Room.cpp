//
// Created by alejandro10213 on 22/05/2025.
//

#include "../include/Room.h"

Room::Room(const Player &player) {
    this -> player = player;
}

std::string Room::addEnemy(std::unique_ptr<Enemy> enemy) {
    enemies.push_back(std::move(enemy));

    return "Agregado correctamente!";
}

std::vector<std::unique_ptr<Enemy>> Room::getEnemies() const {
    return enemies;
}