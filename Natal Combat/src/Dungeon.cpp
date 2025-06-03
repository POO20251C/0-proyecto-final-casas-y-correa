#include "../include/Dungeon.h"
#include "../include/ItemRepository.h"

Dungeon::Dungeon(Player &player) : player(player) {
    this->loadDungeon();
}

void Dungeon::loadDungeon() {
    ItemRepository &repo = ItemRepository::getInstance();

    // Room 1
    Reward rewardRoom1("Cofre");
    rewardRoom1.addPotion(repo.getPotionByName("Pocion Pequena de Salud"));
    rewardRoom1.addPotion(repo.getPotionByName("Pocion Pequena de Salud"));
    rewardRoom1.addPotion(repo.getPotionByName("Pocion Pequena de Salud"));

    Enemy enemy1_room1("Esbirro débil", Attribute(45, 10, 5, 10, 0), 1);
    enemy1_room1.addAttack(repo.getAttackByName("Bofetada"));
    Enemy enemy2_room1("Esbirro débil", Attribute(45, 10, 5, 10, 0), 1);
    enemy2_room1.addAttack(repo.getAttackByName("Bofetada"));
    Enemy enemy3_room1("Esbirro débil", Attribute(45, 10, 5, 10, 0), 1);
    enemy3_room1.addAttack(repo.getAttackByName("Bofetada"));

    Room room1("Entrada del Susurro", this->player, rewardRoom1);
    room1.addEnemy(enemy1_room1);
    room1.addEnemy(enemy2_room1);
    room1.addEnemy(enemy3_room1);

    // Room 2
    Reward rewardRoom2("Cofre");
    rewardRoom2.addPotion(repo.getPotionByName("Pocion Pequena de Salud"));
    rewardRoom2.addPotion(repo.getPotionByName("Pocion Pequena de Salud"));

    Enemy enemy1_room2("Goblin enclenque", Attribute(55, 12, 6, 18, 3), 1);
    enemy1_room2.addAttack(repo.getAttackByName("Bofetada"));
    Enemy enemy2_room2("Goblin enclenque", Attribute(55, 12, 6, 18, 3), 1);
    enemy2_room2.addAttack(repo.getAttackByName("Bofetada"));
    Enemy enemy3_room2("Goblin enclenque", Attribute(55, 12, 6, 18, 3), 1);
    enemy3_room2.addAttack(repo.getAttackByName("Bofetada"));

    Room room2("Callejón de los Perdidos", this->player, rewardRoom2);
    room2.addEnemy(enemy1_room2);
    room2.addEnemy(enemy2_room2);
    room2.addEnemy(enemy3_room2);

    // Room 3
    Reward rewardRoom3("Cofre");
    rewardRoom3.addPotion(repo.getPotionByName("Pocion Pequena de Salud"));
    rewardRoom3.addPotion(repo.getPotionByName("Pocion Pequena de Salud"));

    Enemy enemy1_room3("Murciélago hambriento", Attribute(60, 13, 7, 22, 4), 1);
    enemy1_room3.addAttack(repo.getAttackByName("Bofetada"));
    Enemy enemy2_room3("Murciélago hambriento", Attribute(60, 13, 7, 22, 4), 1);
    enemy2_room3.addAttack(repo.getAttackByName("Bofetada"));
    Enemy enemy3_room3("Murciélago hambriento", Attribute(60, 13, 7, 22, 4), 1);
    enemy3_room3.addAttack(repo.getAttackByName("Bofetada"));
    Enemy enemy4_room3("Murciélago hambriento", Attribute(60, 13, 7, 22, 4), 1);
    enemy4_room3.addAttack(repo.getAttackByName("Bofetada"));
    Enemy enemy5_room3("Murciélago hambriento", Attribute(60, 13, 7, 22, 4), 1);
    enemy5_room3.addAttack(repo.getAttackByName("Bofetada"));

    Room room3("Caverna zumbante", this->player, rewardRoom3);
    room3.addEnemy(enemy1_room3);
    room3.addEnemy(enemy2_room3);
    room3.addEnemy(enemy3_room3);
    room3.addEnemy(enemy4_room3);
    room3.addEnemy(enemy5_room3);

    // Room 4
    Reward rewardRoom4("Cofre");
    rewardRoom4.addPotion(repo.getPotionByName("Pocion Pequena de Salud"));
    rewardRoom4.addPotion(repo.getPotionByName("Pocion Pequena de Salud"));

    Enemy enemy1_room4("Esqueleto reanimado", Attribute(70, 14, 9, 15, 2), 1);
    enemy1_room4.addAttack(repo.getAttackByName("Golpe_Oseo"));
    Enemy enemy2_room4("Esqueleto reanimado", Attribute(70, 14, 9, 15, 2), 1);
    enemy2_room4.addAttack(repo.getAttackByName("Golpe_Oseo"));
    Enemy enemy3_room4("Esqueleto reanimado", Attribute(70, 14, 9, 15, 2), 1);
    enemy3_room4.addAttack(repo.getAttackByName("Golpe_Oseo"));
    Enemy enemy4_room4("Esqueleto reanimado", Attribute(70, 14, 9, 15, 2), 1);
    enemy4_room4.addAttack(repo.getAttackByName("Golpe_Oseo"));

    Room room4("Sala de huesos", this->player, rewardRoom4);
    room4.addEnemy(enemy1_room4);
    room4.addEnemy(enemy2_room4);
    room4.addEnemy(enemy3_room4);
    room4.addEnemy(enemy4_room4);

    Reward rewardRoom5("Cofre");
    rewardRoom5.addPotion(repo.getPotionByName("Pocion Pequena de Salud"));
    rewardRoom5.addPotion(repo.getPotionByName("Pocion Pequena de Salud"));
    rewardRoom5.addArmor(repo.getArmorByName("Armadura de Cuero Reforzado"));
    rewardRoom5.addWeapon(repo.getWeaponByName("Espada Bastarda"));

    Enemy enemy1_room5("Jefe Orcucho", Attribute(90, 25, 15, 20, 5), 1);
    enemy1_room5.addAttack(repo.getAttackByName("Golpe fuerte"));

    Room room5("Antro del Jefe", this->player, rewardRoom5);
    room5.addEnemy(enemy1_room5);

    // Room 6
    Reward rewardRoom6("Cofre");
    rewardRoom6.addPotion(repo.getPotionByName("Pocion Mediana de Salud"));
    rewardRoom6.addPotion(repo.getPotionByName("Pocion Mediana de Salud"));
    rewardRoom6.addPotion(repo.getPotionByName("Pocion Mediana de Salud"));
    rewardRoom6.addArmor(repo.getArmorByName("Armadura de Titanio"));
    rewardRoom6.addWeapon(repo.getWeaponByName("Espada Larga de Acero"));

    Enemy enemy1_room6("Espadachin oscuro", Attribute(120, 55, 40, 45, 20), 2);
    enemy1_room6.addAttack(repo.getAttackByName("Golpe fuerte"));
    Enemy enemy2_room6("Bandido nocturno", Attribute(105, 50, 35, 55, 25), 2);
    enemy2_room6.addAttack(repo.getAttackByName("Bofetada"));

    Room room6("Pasaje olvidado", this->player, rewardRoom6);
    room6.addEnemy(enemy1_room6);
    room6.addEnemy(enemy2_room6);

    // Room 7
    Reward rewardRoom7("Cofre");
    rewardRoom7.addPotion(repo.getPotionByName("Pocion Mediana de Salud"));
    rewardRoom7.addPotion(repo.getPotionByName("Pocion Mediana de Salud"));
    rewardRoom7.addArmor(repo.getArmorByName("Armadura de Plata"));
    rewardRoom7.addWeapon(repo.getWeaponByName("Espada Bastarda"));

    Enemy enemy1_room7("Nigromante errante", Attribute(115, 60, 30, 35, 40), 2);
    enemy1_room7.addAttack(repo.getAttackByName("Abracadabra"));
    Enemy enemy2_room7("Asesino sombrío", Attribute(110, 65, 38, 50, 35), 2);
    enemy2_room7.addAttack(repo.getAttackByName("Estocada_Oscura"));

    Room room7("Cámara de los ecos", this->player, rewardRoom7);
    room7.addEnemy(enemy1_room7);
    room7.addEnemy(enemy2_room7);

    // Room 8
    Reward rewardRoom8("Cofre");
    rewardRoom8.addPotion(repo.getPotionByName("Pocion Grande de Salud"));
    rewardRoom8.addPotion(repo.getPotionByName("Pocion Grande de Salud"));
    rewardRoom8.addPotion(repo.getPotionByName("Elixir de Salud"));
    rewardRoom8.addArmor(repo.getArmorByName("Armadura de escamas de dragon"));
    rewardRoom8.addArmor(repo.getArmorByName("Armadura Berserker"));
    rewardRoom8.addWeapon(repo.getWeaponByName("Dragon slayer"));
    rewardRoom8.addWeapon(repo.getWeaponByName("Espada Bastarda"));

    Enemy enemy1_room8("Guardian de hielo", Attribute(180, 85, 110, 30, 20), 4);
    enemy1_room8.addAttack(repo.getAttackByName("Ice_age"));
    Enemy enemy2_room8("Titán escarchado", Attribute(170, 80, 95, 28, 15), 4);
    enemy2_room8.addAttack(repo.getAttackByName("Impacto_rocoso"));

    Room room8("Pico glacial", this->player, rewardRoom8);
    room8.addEnemy(enemy1_room8);
    room8.addEnemy(enemy2_room8);

    // Room 9
    Reward rewardRoom9("Cofre");
    rewardRoom9.addPotion(repo.getPotionByName("Pocion Mediana de Salud"));
    rewardRoom9.addPotion(repo.getPotionByName("Pocion Mediana de Salud"));
    rewardRoom9.addPotion(repo.getPotionByName("Pocion Mediana de Salud"));
    rewardRoom9.addPotion(repo.getPotionByName("Pocion Mediana de Salud"));
    rewardRoom9.addPotion(repo.getPotionByName("Pocion Mediana de Salud"));

    Enemy enemy1_room9("Terror alado", Attribute(130, 100, 60, 65, 25), 3);
    enemy1_room9.addAttack(repo.getAttackByName("Drago_Aliento"));
    Enemy enemy2_room9("Heraldo infernal", Attribute(140, 95, 55, 70, 30), 3);
    enemy2_room9.addAttack(repo.getAttackByName("Golpe fuerte"));

    Room room9("Volcán prohibido", this->player, rewardRoom9);
    room9.addEnemy(enemy1_room9);
    room9.addEnemy(enemy2_room9);

    // Room 10
    Reward rewardRoom10("Cofre");

    Enemy enemy_room10("Figaram the fallen king", Attribute(250, 90, 150, 40, 40), 5);
    enemy_room10.addAttack(repo.getAttackByName("Golpe_de_Gracia"));

    Room room10("Trono del olvido", this->player, rewardRoom10);
    room10.addEnemy(enemy_room10);


    addRoom(room1);
    addRoom(room2);
    addRoom(room3);
    addRoom(room4);
    addRoom(room5);
    addRoom(room6);
    addRoom(room7);
    addRoom(room8);
    addRoom(room9);
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
