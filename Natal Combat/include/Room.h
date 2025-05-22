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
    std::vector<std::unique_ptr<Enemy>> enemies;
public:
    Room(const Player& player);

    std::string addEnemy(std::unique_ptr<Enemy> enemy);

    std::vector<std::unique_ptr<Enemy>> getEnemies() const;
};



#endif //ROOM_H
