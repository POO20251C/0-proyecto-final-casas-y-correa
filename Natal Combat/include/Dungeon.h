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

    std::string addRoom( Room &&room);
    Room getRooms() const;
};



#endif //DUNGEON_H
