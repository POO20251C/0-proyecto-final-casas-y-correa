#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>

#include "include/Hero.h"
#include "include/Player.h"
#include "include/Room.h"
#include "include/Dungeon.h"
#include "include/ItemRepository.h"

using namespace std;

const int MAX_HEROES = 3;
const int MIN_HEORES = 1;
const string helperName = "Gonzo";

// Funciones auxiliares
void sendMessage(const string &message) {
    cout << "Gonzo" << ": " << message << endl;
}

void enterToContinue() {
    cout << "Pressione ENTER para continuar." << endl;
    cin.get();
}

void clearCin() {
    cin.clear();
    cin.ignore(10000, '\n');
}

int getOption() {
    int option;

    cin >> option;

    if (cin.fail()) {
        clearCin();
    } else {
        clearCin();
        return option;
    }

    return 0;
}

void displayHero(const Hero &hero) {
    const Attribute attributes = hero.getAttributes();
    const Weapon weapon = hero.getWeapon();
    const Armor armor = hero.getArmor();
    cout << "=========================" << endl;

    cout << "Nombre: " << hero.getName() << endl;

    cout << "Atributos:" << endl;
    cout << "   -Salud Maxima: " << attributes.getMax_hp() << endl;
    cout << "   -Salud: " << attributes.getHp() << endl;
    cout << "   -Fuerza: " << attributes.getAtk() << " (+" << weapon.getAtk() << ")" << endl;
    cout << "   -Defensa: " << attributes.getDef() << " (+" << armor.getDef() << ")" << endl;
    cout << "   -Velocidad: " << attributes.getSpd() << endl;
    cout << "   -Suerte: " << attributes.getLck() << endl;

    cout << "Arma: " << endl;
    cout << "   -Nombre: " << weapon.getName() << endl;
    cout << "   -dano: " << weapon.getAtk() << endl;

    cout << "Armadura: " << endl;
    cout << "   -Nombre: " << armor.getName() << endl;
    cout << "   -Defensa: " << armor.getDef() << endl;

    cout << "Ataques: " << endl;

    for (const auto &attack : hero.getAttacks()) {
        cout << "   -Nombre: " << attack.getName() << endl;
        cout << "   -Poder: x" << to_string(attack.getPower()) << endl;
        cout << "-------------------------------------" << endl;
    }

    cout << "=========================" << endl;
}

void displayHeroes(const vector<Hero> &heroes) {
    cout << "--- Lista de Heroes ---" << endl;
    for (const auto &hero: heroes) {
        displayHero(hero);
    }
}

void displayHeroAttacks(const Hero &hero) {
    cout << "--- Lista de ataques (poder | Precision) ---" << endl;

    const auto &attacks = hero.getAttacks();
    const int attacks_size = attacks.size();
    for (size_t i = 0; i < attacks_size; ++i) {
        const Attack &attack = attacks[i];
        cout << i + 1 << ". " << attack.getName() << " (" << attack.getPower() << " poder | " <<
                to_string(attack.getAccuracy()) << "% precision)" << endl;
    }

    cout << attacks_size + 1 << ". " << "Ataque aleatorio" << endl;
}

void displayInventoryArticle() {

}

bool displayInventory(Player &player, const ItemRepository &itemRepository) {
    bool exit = false;

    cout << "===== INVENTARIO =====" << endl;
    cout << "1. Armas" << endl;
    cout << "2. Armaduras" << endl;
    cout << "3. Posciones" << endl;
    cout << "4. Salir" << endl;
    int option = getOption();

    switch (option) {
        case 1:
            sendMessage("Mostrando Armas...");
            if (!player.getInventory().getWeapons().empty()) {
                // Esto muestra el de las armas
                for (size_t i = 0; i < player.getInventory().getWeapons().size(); ++i) {
                    Weapon& weapon = player.getInventory().getWeapons()[i];

                    cout << i + 1 << ". " << weapon.getName() << endl;
                }

                option = getOption();
                switch (option) {

                }

            } else {
                sendMessage("No tienes armas en este momento.");
            }
            break;
        case 2:
            sendMessage("Mostrando Armaduras...");
            break;
        case 3:
            sendMessage("Mostrando Posciones...");
            break;
        case 4:
            sendMessage("Saliendo del inventario...");
            exit = true;
            break;
        default:
            std::cout << "Opción no válida. Intenta de nuevo.\n";
    }

    return exit;
}

Dungeon loadDungeon(const Player &player, const ItemRepository &itemRepository) {
    Dungeon dungeon(player);


    // Room 1

    Room room1("Mazmorra de las Sombras", player);
    Enemy enemy1("Soldado", Attribute(100, 103, 10, 10, 10), 1, 25);
    //enemy1.initEquipment();

    //cout << "Enemigoo " << to_string(enemy1.getAttributes().getDef()) << " otro " << (enemy1.getArmor().getName()) << endl;
    enemy1.addAttack(itemRepository.getAttackByName("Golpe fuerte"));
    room1.addEnemy(enemy1);

    dungeon.addRoom(room1);

    // Room 2

    Room room2("Caverna del Olvido", player);


    Room room3("Cripta del Destino", player);


    Room room4("Templo de la Perdición", player);


    Room room5("Ruinas del Eco", player);


    Room room6("Fortaleza de la Agonía", player);


    Room room7("Abismo Carmesí", player);


    Room room8("Santuario Roto", player);


    Room room9("Torre del Silencio", player);


    Room room10("Nido de la Niebla", player);

    return dungeon;
}

bool checkAccuracy(int accuracy) {
    if (accuracy < 0 || accuracy > 100) {
        return false;
    }

    int rng = rand() % 101;

    return rng <= accuracy;
}

bool checkDodge(int lck) {
    if (lck < 0 || lck > 50) {
        return false;
    }

    int rng = rand() % 51;
    return rng <= lck;
}

Attack getPlayerAttack(Hero &player_hero) {
    displayHeroAttacks(player_hero);
    int option = getOption();

    int player_attacks_size = player_hero.getAttacks().size();

    if (option > 0 && option < player_attacks_size + 2) {
        option = option - 1;
        if (option == player_attacks_size) {
            return player_hero.getRandomAttack();
        }

        return player_hero.getAttackByIndex(option);
    }
    cout << "Opcion invalida." << endl;
    return getPlayerAttack(player_hero);
}

void execute_player_attack(Hero &player_hero, Enemy &objetive) {
    sendMessage("Turno de " + player_hero.getName() + "(Salud: " + to_string(player_hero.getAttributes().getHp()) +
    "/" + to_string(player_hero.getAttributes().getMax_hp()) + ")");

    Attack hero_attack = getPlayerAttack(player_hero); //player_hero.getAttackByIndex(0);

    // Probabilidad de que el ataque acierte + la suerete base del jugador
    if (checkAccuracy(hero_attack.getAccuracy() + player_hero.getAttributes().getLck())) {
        // Acerto

        // Probabilidad de que el enemigo lo esquive
        if (checkDodge(objetive.getAttributes().getLck())) {
            // El enemigo lo esquivo

            sendMessage(objetive.getName() + " esquivo el ataque de " + player_hero.getName());
        } else {
            // El enemigo no lo esquiva (recibe daño)

            int dmg = objetive.receiveDamage(player_hero.getAttackDamage(hero_attack));
            sendMessage(
                "Golpe acertado " + objetive.getName() + " pierde " + to_string(dmg) + " de salud. " +
                "(Salud: " + to_string(objetive.getAttributes().getHp()) + "/" + to_string(
                    objetive.getAttributes().getMax_hp()) + ")");
        }

    } else {
        // No acerto
        sendMessage(player_hero.getName() + " ha fallado su ataque.");
    }

    /*
    if (checkAccuracy(hero_attack.getAccuracy())) {
        int dmg = objetive.receiveDamage(player_hero.getAttacks()[0].getDmg());
        sendMessage(
            "Golpe acertado " + objetive.getName() + " pierde " + to_string(dmg) + " de salud. " +
            "(Salud: " + to_string(objetive.getAttributes().getHp()) + "/" + to_string(
                objetive.getAttributes().getMax_hp()) + ")");
    } else {
        cout << player_hero.getName() << " ha fallado su ataque.";
    }*/
}

void execute_enemy_attack(Enemy &enemy, Hero &objetive) {
    sendMessage("Turno de " + enemy.getName() + "(Salud: " + to_string(enemy.getAttributes().getHp()) +
"/" + to_string(enemy.getAttributes().getMax_hp()) + ")");

    Attack enemy_attack = enemy.getRandomAttack();

    if (checkAccuracy(enemy_attack.getAccuracy() + enemy.getAttributes().getLck())) {
        // Acerto

        // Probabilidad de que el heroe lo esquive
        if (checkDodge(objetive.getAttributes().getLck())) {
            // El heroe lo esquivo

            sendMessage(objetive.getName() + " esquivo el ataque de " + enemy.getName());
        } else {
            // El heroe no lo esquiva (recibe daño)

            int dmg = objetive.receiveDamage(enemy.getAttackDamage(enemy_attack));
            sendMessage(
                "Golpe acertado " + objetive.getName() + " pierde " + to_string(dmg) + " de salud. " +
                "(Salud: " + to_string(objetive.getAttributes().getHp()) + "/" + to_string(
                    objetive.getAttributes().getMax_hp()) + ")");
        }

    } else {
        // No acerto
        sendMessage(enemy.getName() + " ha fallado su ataque.");
    }
}


bool startRoom(Player &player, const Dungeon &dungeon, int currentDungeon) {
    srand(time(nullptr));

    int currentHeroTurn = 0;

    bool result = true;
    try {
        Room room = dungeon.getRoom(currentDungeon);
        sendMessage("Bienvenido a la " + room.getName());
        while (!room.getEnemies().empty() && result) {
            Enemy &objetive = room.getLowRankEnemy();

            sendMessage(
                "Un enemigo de rango " + to_string(objetive.getRank()) + " ha aparecido! Preparate para derrotarlo!");

            while (objetive.getAttributes().getHp() > 0) {
                Hero &player_hero = player.getHeroByIndex(currentHeroTurn++);

                execute_player_attack(player_hero, objetive);
                if (objetive.getAttributes().getHp() == 0) {
                    break;
                }

                enterToContinue();
                execute_enemy_attack(objetive, player_hero);
                enterToContinue();

                if (player_hero.getAttributes().getHp() == 0) {
                    sendMessage(player_hero.getName() + " ha caído en batalla a manos de " + objetive.getName() + "...");
                    player.removeHero(player_hero.getName());
                    sendMessage("Te quedan " + to_string(player.getHeroes().size()) + " de " + to_string(MIN_HEORES) + " heroes.");

                    if (player.getHeroes().size() < MIN_HEORES) {
                        sendMessage("Necesitas al menos " + to_string(MIN_HEORES) + " heroes para seguir luchando.");
                    } else {
                        sendMessage("Aun puedes continuar la batalla.");
                    }
                }

                if (currentHeroTurn >= player.getHeroes().size()) {
                    currentHeroTurn = 0;
                }
            }

            sendMessage(objetive.getName() + " ha sido derrotado!");
            room.removeEnemy(objetive);
            enterToContinue();
        }
    } catch (out_of_range &e) {
        sendMessage(e.what());
    }

    return result;
}

int main() {
    Dungeon dungeon;
    ItemRepository itemRepository = ItemRepository::getInstance();

    int currentDungeon = 0;

    Player player;
    string state = "Menu";
    string playerName = "None";

    bool enable = true;

    while (enable) {
        // Menu principal
        if (state == "Menu") {
            int option;
            cout << "1. Iniciar nuevo juego" << endl;
            cout << "2. Ver mejor puntuacion" << endl;
            cout << "3. Salir" << endl;
            option = getOption();
            switch (option) {
                case 1:
                    state = "Init";
                    break;
                case 2:
                    break;
                case 3:
                    enable = false;
                    break;
                default:
                    cout << "Opcion invalida." << endl;
            }


            // Seleccion de heroes
        } else if (state == "Init") {
            if (playerName == "None") {
                cout << "Introduce tu nombre: ";
                getline(cin, playerName);

                player = Player(playerName);

                sendMessage("Hola, " + playerName + ". Preparate para el combate!");
                sendMessage("Selecciona 3 heroes para la batalla");
                sendMessage("Para seleccionar a un heroe, escribe su nombre");

                enterToContinue();
                state = "Inventory";
                continue;

                int option;
                bool exit = false;
                while (!exit) {
                    cout << "1. Agregar heroe" << endl;
                    cout << "2. Eliminar heroe" << endl;
                    cout << "3. Mostrar tus heroes" << endl;
                    cout << "4. Mostrar heroes" << endl;
                    cout << "5. Salir" << endl;

                    option = getOption();

                    switch (option) {
                        case 1: {
                            if (player.getHeroes().size() < MAX_HEROES) {
                                string heroName;
                                cout << "Para seleccionar a un heroe, escribe su nombre: ";
                                getline(cin, heroName);

                                if (!player.isHeroExists(heroName)) {
                                    try {
                                        Hero hero = itemRepository.getHeroByName(heroName);
                                        sendMessage(player.addHero(hero));
                                    } catch (runtime_error &e) {
                                        //sendMessage("SYSTEM", "Error cargando heroe, " + to_string(e.what()) + endl);
                                        cout << "Error cargando heroe, " << e.what() << endl;
                                    };
                                } else {
                                    sendMessage("Ese heroe ya está en tu equipo.");
                                }
                            } else {
                                sendMessage("Ya tienes 3 heroes seleccionados.");
                            }
                            break;
                        }
                        case 2: {
                            if (!player.getHeroes().empty()) {
                                string heroName;
                                cout << "Escribe el nombre del heroe que deseas eliminar: ";
                                getline(cin, heroName);

                                bool removed = player.removeHero(heroName); // usa el metodo de la clase Player

                                if (removed) {
                                    sendMessage("El heroe fue borrado correctamente.");
                                } else {
                                    sendMessage("No se encontro el heroe.");
                                }
                            } else {
                                sendMessage("No has seleccionado ningun heroe.");
                            }

                            break;
                        }
                        case 3: {
                            if (!player.getHeroes().empty()) {
                                displayHeroes(player.getHeroes());
                            } else {
                                sendMessage("Aun no has seleccionado heroes.");
                            }
                            break;
                        }

                        case 4: {
                            displayHeroes(itemRepository.getHeroes());
                            break;
                        }
                        case 5: {
                            if (player.getHeroes().size() == MAX_HEROES) {
                                state = "load_dungeons";
                                exit = true;
                            } else {
                                sendMessage("Aun no has seleccionado todos los heroes.");
                            }
                            break;
                        }

                        default:
                            cout << "Opcion inválida." << endl;
                            break;
                    }
                }
            }
        } else if (state == "load_dungeons") {
            dungeon = loadDungeon(player, itemRepository);
            state = "Ready";
            sendMessage("Cargando dungeons...");
        } else if (state == "Ready") {
            // Verificar los heroes
            /*if (player.getHeroes().size() == MIN_HEORES) {
                break;
            }*/
            enterToContinue();

            startRoom(player, dungeon, currentDungeon);
        } else if (state == "Inventory") {
            if (displayInventory(player, itemRepository) == true) {
                state = "Ready";
            }
        }
    }



    return 0;
}
