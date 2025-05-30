//
// Created by alejandro10213 on 22/05/2025.
//

#include "../include/Dungeon.h"

#include <iostream>

#include "../include/ItemRepository.h"

Dungeon::Dungeon(const Player &player) {
    this -> player = player;

    std::cout << "Empezando a cargar" << std::endl;

    this -> loadDungeon();

    std::cout << "Termino de cargar" << std::endl;
}

void Dungeon::loadDungeon() {
    ItemRepository& repo = ItemRepository::getInstance();

    // Room 1
    Reward rewardRoom1("Cofre");
    rewardRoom1.addPotion(repo.getPotionByName("Pocion Pequena de Salud"));
    // Enemigos
    Enemy enemy1_room1("Soldado", Attribute(100, 20, 10, 10, 0), 1);
    //Enemy enemy2_room1("Soldado", Attribute(100, 20, 10, 10, 0), 1);
    //Enemy enemy3_room1("Soldado", Attribute(100, 20, 10, 10, 0), 1);
    //Enemy enemy4_room1("Soldado", Attribute(100, 23, 15, 10, 0), 2);
    //Enemy enemy5_room1("Soldado", Attribute(130, 25, 15, 10, 0), 2);

    // Ataques de enemigos
    enemy1_room1.addAttack(repo.getAttackByName("one_punch"));
    //enemy2_room1.addAttack(repo.getAttackByName("Golpe fuerte"));
    //enemy3_room1.addAttack(repo.getAttackByName("Golpe fuerte"));
    //enemy4_room1.addAttack(repo.getAttackByName("Golpe fuerte"));
    //enemy5_room1.addAttack(repo.getAttackByName("Golpe fuerte"));

    // instanciar todo
    Room room1("Mazmorra de las Sombras", player, rewardRoom1);
    room1.addEnemy(enemy1_room1);
    //room1.addEnemy(enemy2_room1);
    //room1.addEnemy(enemy3_room1);
    //room1.addEnemy(enemy4_room1);
    //room1.addEnemy(enemy5_room1);



    // Room 10
    Reward rewardRoom10("Cofre");
    Enemy enemy_room10("Tung Tung Tung Sahur", Attribute(99, 99, 99, 99, 99), 10);

    Room room10("nose", player, rewardRoom10);
    room10.addEnemy(enemy_room10);

    addRoom(room1);
    addRoom(room10);
}


void Dungeon::addRoom(const Room &room) {
    rooms.push_back(room);
}

std::vector<Room> Dungeon::getRooms() {
    return rooms;
}

Room Dungeon::getRoom(int room) const {
    return rooms[room];
}
