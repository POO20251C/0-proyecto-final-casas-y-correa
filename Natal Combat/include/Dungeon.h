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
    Player& player;
    std::vector<Room> rooms;

    void loadDungeon();
public:
    Dungeon(Player &player);

    Room getRoom(int room) const;
    std::vector<Room> getRooms();

    void addRoom(const Room &room);
};



#endif //DUNGEON_H
