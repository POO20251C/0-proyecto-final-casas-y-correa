//
// Created by alejandro10213 on 22/05/2025.
//

#include "../include/Dungeon.h"

Dungeon::Dungeon(const Player &player) {
    this -> player = player;
}

void Dungeon::addRoom(const Room &room) {
    rooms.push_back(room);
}

Room Dungeon::getRoom(int room) const {
    if (room < 0 || room >= rooms.size()) {
        throw std::out_of_range("Índice de sala inválido");
    }
    return rooms[room];
}
