//
// Created by alejandro10213 on 22/05/2025.
//

#include "../include/Dungeon.h"

Dungeon::Dungeon(const Player &player) {
    this -> player = player;
}

std::string Dungeon::addRoom(Room &&room) {
    rooms.push_back(std::move(room));
    return "Done!";
}

Room Dungeon::getRooms() const {
    return rooms;
}