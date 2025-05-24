//
// Created by alejandro10213 on 22/05/2025.
//
#ifndef ROOM_H
#define ROOM_H

#include <string>
#include <map>
#include <memory>
#include <vector>

#include "Player.h"
#include "Enemy.h"

class Room {
private:
    Player player;
    std::vector<Enemy> enemies;
public:
    Room() = default;
    Room(const Player& player);
    void addEnemy(const Enemy& enemy);
    std::vector<Enemy> getEnemies() const;
};



#endif //ROOM_H
