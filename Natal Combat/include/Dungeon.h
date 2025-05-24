//
// Created by alejandro10213 on 22/05/2025.
//

#ifndef DUNGEON_H
#define DUNGEON_H

#include <vector>

#include "Player.h"
#include "Room.h"


class Dungeon {
private:
    Player player;
    std::vector<Room> rooms;
public:
    Dungeon() = default;
    Dungeon(const Player &player);

    Room getRoom(int room) const;

    void addRoom(const Room &room);
    bool startRoom(int room);
};



#endif //DUNGEON_H
