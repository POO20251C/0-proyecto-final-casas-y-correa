//
// Created by alejandro10213 on 22/05/2025.
//

#include "../include/Room.h"

Room::Room(const std::string &name, const Player &player, Reward& reward) {
    this -> name = name;
    this -> player = player;
    this -> reward = reward;
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

std::string Room::getRewardName() {
    return reward.getName();
}

Reward& Room::getReward() {
    return reward;
}


std::string Room::giveReward() {
    if (!reward.getWeapons().empty()) {
        for (auto& weapon : reward.getWeapons()) {
            player.getInventory().addWeapon(weapon);
        }
    }

    if (!reward.getArmors().empty()) {
        for (auto& armor : reward.getArmors()) {
            player.getInventory().addArmor(armor);
        }
    }

    if (!reward.getPotions().empty()) {
        for (auto& potion : reward.getPotions()) {
            player.getInventory().addPotion(potion);
        }
    }

    return "Los items fueron agregados al inventario";
}


void Room::removeEnemy(const Enemy& enemy) {
    for (size_t i = 0; i < enemies.size(); ++i) {
        if (&enemies[i] == &enemy) {
            enemies.erase(enemies.begin() + i);
            break;
        }
    }
}