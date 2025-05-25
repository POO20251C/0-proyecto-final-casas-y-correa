//
// Created by alejandro10213 on 22/05/2025.
//

#include "../include/Room.h"

Room::Room(const std::string &name, const Player &player) {
    this -> name = name;
    this -> player = player;
}

void Room::addEnemy(const Enemy &enemy) {
    enemies.push_back(enemy);
}

std::vector<Enemy> Room::getEnemies() const {
    return enemies;
}

Enemy& Room::getLowRankEnemy() {
    Enemy* result = &enemies[0];
    int low_rank = result->getRank();

    for (auto& enemy : enemies) {
        if (enemy.getRank() < low_rank) {
            result = &enemy;
            low_rank = enemy.getRank();
        }
    }

    return *result;
}

std::string Room::getName() const {
    return name;
}

void Room::removeEnemy(const Enemy &enemy) {

}
