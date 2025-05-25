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
    std::string name;
    Player player;
    std::vector<Enemy> enemies;
public:
    Room() = default;
    Room(const std::string &name, const Player& player);
    void addEnemy(const Enemy& enemy);
    void removeEnemy(const Enemy& enemy);

    Enemy& getLowRankEnemy();

    std::vector<Enemy> getEnemies() const;

    std::string getName() const;
};



#endif //ROOM_H
