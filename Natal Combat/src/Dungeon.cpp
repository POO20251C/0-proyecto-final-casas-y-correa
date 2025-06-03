#include "../include/Dungeon.h"
#include "../include/ItemRepository.h"

Dungeon::Dungeon(Player &player) : player(player) {
    this->loadDungeon();
}

void Dungeon::loadDungeon() {
    ItemRepository& repo = ItemRepository::getInstance();

    // Room 1
    // en este cuarto se pelea contra un soldado
    Reward rewardRoom1("Cofre");
    rewardRoom1.addPotion(repo.getPotionByName("Pocion Pequena de Salud"));
    rewardRoom1.addArmor(repo.getArmorByName("Armadura de Cuero Reforzado"));
    // Enemigos
    Enemy enemy1_room1("Soldadito de plomo", Attribute(100, 20, 10, 10, 0), 1);
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
    Room room1("Mazmorra de las Sombras", this->player, rewardRoom1);
    room1.addEnemy(enemy1_room1);
    //room1.addEnemy(enemy2_room1);
    //room1.addEnemy(enemy3_room1);
    //room1.addEnemy(enemy4_room1);
    //room1.addEnemy(enemy5_room1);

    // Room 2
    // en este cuarto se pelea contra 2 esqueletos
    Reward rewardRoom2("Cofre");
    rewardRoom2.addPotion(repo.getPotionByName("Pocion Pequena de Salud"));
    rewardRoom2.addPotion(repo.getPotionByName("Pocion Pequena de Salud"));
    rewardRoom2.addWeapon(repo.getWeaponByName("Lanza de Madera Reforzada"));

    Enemy enemy1_room2("Randy el esqueleto", Attribute(100, 30, 20, 40, 15), 2);
    enemy1_room2.addAttack(repo.getAttackByName("Golpe_Oseo"));
    Enemy enemy2_room2("Sans el esqueleto", Attribute(100, 30, 20, 40, 15), 2);
    enemy2_room2.addAttack(repo.getAttackByName("Golpe_Oseo"));

    Room room2("Burdel de los no muertos", this->player, rewardRoom2);
    room2.addEnemy(enemy1_room2);
    room2.addEnemy(enemy2_room2);

    // Room 3
    // en esta dungeon se pelea contra 5 gnomos
    Reward rewardRoom3("Cofre");
    rewardRoom3.addPotion(repo.getPotionByName("Pocion Mediana de Salud"));
    rewardRoom3.addArmor(repo.getArmorByName("Armadura de Hierro"));

    Enemy enemy1_room3("Gnomo", Attribute(60, 9, 15, 25, 60), 3);
    enemy1_room3.addAttack(repo.getAttackByName("Bofetada"));
    Enemy enemy2_room3("Gnomo", Attribute(60, 9, 15, 25, 60), 3);
    enemy2_room3.addAttack(repo.getAttackByName("Bofetada"));
    Enemy enemy3_room3("Gnomo", Attribute(60, 9, 15, 25, 60), 3);
    enemy3_room3.addAttack(repo.getAttackByName("Bofetada"));
    Enemy enemy4_room3("Gnomo", Attribute(60, 9, 15, 25, 60), 3);
    enemy4_room3.addAttack(repo.getAttackByName("Bofetada"));
    Enemy enemy5_room3("Gnomo", Attribute(60, 9, 15, 25, 60), 3);
    enemy5_room3.addAttack(repo.getAttackByName("Bofetada"));

    Room room3("Patio del nomo", this->player, rewardRoom3);
    room3.addEnemy(enemy1_room3);
    room3.addEnemy(enemy2_room3);
    room3.addEnemy(enemy3_room3);
    room3.addEnemy(enemy4_room3);
    room3.addEnemy(enemy5_room3);

    // Room 4
    // En este cuarto se pelea contra una araña
    Reward rewardRoom4("Cofre");
    rewardRoom4.addWeapon(repo.getWeaponByName("Arco de Cazador"));
    rewardRoom4.addPotion(repo.getPotionByName("Pocion Mediana de Salud"));
    rewardRoom4.addPotion(repo.getPotionByName("Pocion Pequena de Salud"));

    Enemy enemy_room4("Araña gigante de las catatumbas", Attribute(120, 60, 40, 50, 40), 4);
    enemy_room4.addAttack(repo.getAttackByName("Picadura_poderoza"));

    Room room4("Las Catatumbas", this->player, rewardRoom4);
    room4.addEnemy(enemy_room4);

    // Room 5
    // En esta cuarto nos enfrentamos a un golem
    Reward rewardRoom5("Cofre");
    rewardRoom5.addWeapon(repo.getWeaponByName("Chainsaw"));
    rewardRoom5.addPotion(repo.getPotionByName("Pocion Grande de Salud"));
    rewardRoom5.addPotion(repo.getPotionByName("Pocion Mediana de Salud"));

    Enemy enemy_room5("Fyodor el Golem", Attribute(160, 40, 90, 15, 10), 5);
    enemy_room5.addAttack(repo.getAttackByName("Impacto_rocoso"));

    Room room5("Pradera rocosa", this->player, rewardRoom5);
    room5.addEnemy(enemy_room5);

    // Room 6
    // En esta cuarto nos enfrentamos a un hechizero
    Reward rewardRoom6("Cofre");
    rewardRoom6.addWeapon(repo.getWeaponByName("Katana"));
    rewardRoom6.addPotion(repo.getPotionByName("Pocion Grande de Salud"));
    rewardRoom6.addPotion(repo.getPotionByName("Pocion Mediana de Salud"));

    Enemy enemy_room6("Hechizero Merlin", Attribute(110, 75, 70, 60, 99), 6);
    enemy_room6.addAttack(repo.getAttackByName("Abracadabra"));

    Room room6("Biblioteca del palacio de Noctalia", this->player, rewardRoom6);
    room6.addEnemy(enemy_room6);

    // Room 7
    // En este cuarto nos efentramos a un caballero sin cabeza
    Reward rewardRoom7("Cofre");
    rewardRoom7.addPotion(repo.getPotionByName("Elixir de Salud"));
    rewardRoom7.addWeapon(repo.getWeaponByName("Colmillo de sabueso"));
    rewardRoom7.addArmor(repo.getArmorByName("Armadura de Acero"));

    Enemy enemy_room7("Caballero sin cabeza", Attribute(130, 85, 80, 75, 20), 7);
    enemy_room7.addAttack(repo.getAttackByName("Estocada_Oscura"));

    Room room7("Amplio pasillo del palacio de Noctalia", this->player, rewardRoom7);
    room7.addEnemy(enemy_room7);

    // Room 8
    // En este cuarto nos enfrentaremos a un gigante de hielo
    Reward rewardRoom8("Cofre");
    rewardRoom8.addPotion(repo.getPotionByName("Pocion Grande de Salud"));
    rewardRoom8.addPotion(repo.getPotionByName("Pocion Grande de Salud"));
    rewardRoom8.addWeapon(repo.getWeaponByName("Dragon slayer"));
    rewardRoom8.addArmor(repo.getArmorByName("Armadura Berserker"));

    Enemy enemy_room8("Gigante de hielo", Attribute(165, 94, 84, 60, 22), 8);
    enemy_room8.addAttack(repo.getAttackByName("Ice_age"));

    Room room8("Jaula gigante", this->player, rewardRoom8);
    room8.addEnemy(enemy_room8);

    // Room 9
    // En este cuarto no enfrentamos contra un dragon
    Reward rewardRoom9("Cofre");
    rewardRoom9.addPotion(repo.getPotionByName("Elixir de Salud"));

    Enemy enemy_room9("Draco el Dragon escamado", Attribute(190, 100, 100, 90, 50), 9);
    enemy_room9.addAttack(repo.getAttackByName("Drago_Aliento"));

    Room room9("Cuenca de los tezoros", this->player, rewardRoom9);
    room9.addEnemy(enemy_room9);

    // Room 10
    // En este cuarto nos enfrentamos al rey
    Reward rewardRoom10("Cofre");
    rewardRoom10.addPotion(repo.getPotionByName("Elixir de Salud"));

    Enemy enemy_room10("Figaram the fallen king ", Attribute(200, 110, 120, 65, 60), 10);
    enemy_room10.addAttack(repo.getAttackByName("Golpe_de_Gracia"));

    Room room10("Ruinas del palacio de Noctalia", this->player, rewardRoom10);
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
