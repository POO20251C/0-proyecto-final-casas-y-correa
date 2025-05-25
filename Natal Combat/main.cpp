#include <iostream>
#include <string>
#include <vector>

#include "include/Hero.h"
#include "include/Player.h"
#include "include/Room.h"
#include "include/Dungeon.h"
#include "include/ItemRepository.h"

using namespace std;

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

//Funciones para copiar objetos
/*Armor copyArmor(const string &name, const vector<Armor> &armors) {
    Armor armor;

    for (const auto armor: armors) {
        if (armor.getName() == name) {
            return armor;
        }
    }

    throw runtime_error("Armadura no encontrada");
}

Weapon copyWeapon(const string &name, const vector<Weapon> &weapons) {
    Weapon weapon;

    for (const auto weapon: weapons) {
        if (weapon.getName() == name) {
            return weapon;
        }
    }

    throw runtime_error("Weapon no encontrada");
}

// Funciones para cargar objetos
vector<Weapon> loadWeapons() {
    vector<Weapon> weapons;

    // Espada de madera
    weapons.emplace_back("Espada de Hierro", 50, 10);
    weapons.emplace_back("Espada Larga de Acero", 65, 10);
    weapons.emplace_back("Hacha de Mano", 55, 10);
    weapons.emplace_back("Lanza de Madera Reforzada", 40, 10);
    weapons.emplace_back("Maza de Bronce", 60, 10);
    weapons.emplace_back("Daga Curva", 45, 10);
    weapons.emplace_back("Martillo de Guerra", 70, 10);
    weapons.emplace_back("Arco de Cazador", 50, 10);
    weapons.emplace_back("Ballesta Liviana", 55, 10);
    weapons.emplace_back("Espada Bastarda", 75, 10);

    return weapons;
}

vector<Armor> loadArmors() {
    vector<Armor> armors;

    // Armadura de metal
    armors.emplace_back("Armadura de Hierro", 60);
    armors.emplace_back("Armadura de Acero", 70);
    armors.emplace_back("Armadura de Cuero Reforzado", 45);
    armors.emplace_back("Armadura de Cadena", 55);
    armors.emplace_back("Armadura de Plata", 65);
    armors.emplace_back("Armadura de Bronce", 50);
    armors.emplace_back("Armadura de Titanio", 80);
    armors.emplace_back("Armadura de Escamas", 40);
    armors.emplace_back("Armadura de Latón", 48);
    armors.emplace_back("Armadura de Placas", 75);

    return armors;
}

vector<Hero> loadHeroes(const vector<Weapon> &weapons, const vector<Armor> &armors) {
    vector<Hero> heroes;

    string name;
    Attribute attribute;
    Weapon weapon;
    Armor armor;

    // Alejo
    try {
        name = "Alejo";
        armor = copyArmor("Armadura de Hierro", armors);
        weapon = copyWeapon("Espada de Hierro", weapons);
        attribute = Attribute(100, 40, 50, 10, 20);

        heroes.emplace_back(name, attribute, weapon, armor);
    } catch (runtime_error &e) {
        sendMessage("SYSTEM", e.what());
    }

    // Juan
    try {
        name = "Juan";
        armor = copyArmor("Armadura de Hierro", armors);
        weapon = copyWeapon("Espada de Hierro", weapons);
        attribute = Attribute(100, 40, 50, 10, 20);

        heroes.emplace_back(name, attribute, weapon, armor);
    } catch (runtime_error &e) {
        sendMessage("SYSTEM", e.what());
    }

    // Gonzo
    try {
        name = "Gonzo";
        armor = copyArmor("Armadura de Hierro", armors);
        weapon = copyWeapon("Espada de Hierro", weapons);
        attribute = Attribute(100, 40, 50, 10, 20);

        heroes.emplace_back(name, attribute, weapon, armor);
    } catch (runtime_error &e) {
        sendMessage("SYSTEM", e.what());
    }

    return heroes;
}

/*
void loadDungeon(Player &player, Dungeon &dungeon, vector<Armor> &armors, vector<Weapon> weapons) {
    Armor armor = copyArmor("Armadura de metal", armors);
    Weapon weapon = copyWeapon("Espada de madera", weapons);

    Attribute attribute = Attribute(100, 40, 50, 10, 20);

    Room room(player);
    room.addEnemy(std::make_unique<Soldier>("Hola", attribute, weapon, armor));

    dungeon.addRoom(move(room));
}
*/

vector<Room> loadRooms(const Player &player) {
    vector<Room> rooms;

    return rooms;
}

Hero getHero(const string &name, const vector<Hero> &heroes) {
    for (const auto &hero: heroes) {
        if (hero.getName() == name) {
            return hero;
        }
    }

    throw runtime_error("Hero no encontrada");
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

    cout << "=========================" << endl;
}

void displayHeroes(const vector<Hero> &heroes) {
    cout << "--- Lista de Heroes ---" << endl;
    for (const auto &hero: heroes) {
        displayHero(hero);
    }
}

void displayHeroAttacks(const Hero &hero) {
    cout << "--- Lista de ataques disponibles (dano | Precisión) ---" << endl;

    const auto& attacks = hero.getAttacks();
    for (size_t i = 0; i < attacks.size(); ++i) {
        const Attack& attack = attacks[i];
        cout << i + 1 << ". " << attack.getName() << " (" << attack.getDmg() << " dano | " << to_string(attack.getAccuracy()) << "% precisión)" << endl;
    }
}

Dungeon loadDungeon(const Player &player, const ItemRepository &itemRepository) {
    Dungeon dungeon(player);


    // Room 1
    Room room1("Mazmorra de las Sombras", player);
    room1.addEnemy(Enemy("Soldado", Attribute(100, 10, 10, 10, 10), itemRepository.getWeaponByName("Espada de Hierro"),
                         itemRepository.getArmorByName("Armadura de Hierro"), 1));
    dungeon.addRoom(room1);

    // Room 2

    return dungeon;
}

bool startRoom(const Player &player, const Dungeon &dungeon, int currentDungeon) {
    bool result = true;
    try {
        Room room = dungeon.getRoom(currentDungeon);
        cout << "Bienvenido a la " << room.getName() << endl;
        while (!room.getEnemies().empty() && result) {
            Enemy& objetive = room.getLowRankEnemy();

            while (objetive.getAttributes().getHp() > 0) {
                Hero player_hero = player.getLowSpeedHero();

                sendMessage("Turno de " + player_hero.getName());
                displayHeroAttacks(player_hero);
                int option = getOption();
            }
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

    const int MAX_HEROES = 3;
    const int MIN_HEORES = 1;
    const string helperName = "Gonzo";

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
                            if (player.getHeroes().size() == 3) {
                                state = "load_dungeons";
                                exit = true;
                            } else {
                                sendMessage("Aun no has seleccionado todos los heroes.");
                            }
                            break;
                        }

                        default:
                            cout << "Opción inválida." << endl;
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
            if (player.getHeroes().size() == MIN_HEORES) {
                break;
            }
            enterToContinue();

            startRoom(player, dungeon, currentDungeon);
        }
    }


    // displayHeroes(heroes);


    return 0;
}
