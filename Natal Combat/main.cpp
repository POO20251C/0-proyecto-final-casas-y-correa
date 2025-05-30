#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <fstream>

#include "include/json.hpp"
#include "include/Hero.h"
#include "include/Player.h"
#include "include/Room.h"
#include "include/Dungeon.h"
#include "include/ItemRepository.h"
#include "include/Market.h"

using namespace std;
using json = nlohmann::json;

const int MAX_HEROES = 3;
const int MIN_HEORES = 1;
const string helperName = "Gonzo";
//ItemRepository& itemRepository = ItemRepository::getInstance();

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

void displayHero(Hero &hero) {
    const Attribute attributes = hero.getAttributes();
    Weapon weapon = hero.getWeapon();
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

    for (const auto &attack: hero.getAttacks()) {
        cout << "   -Nombre: " << attack.getName() << endl;
        cout << "   -Poder: x" << to_string(attack.getPower()) << endl;
        cout << "-------------------------------------" << endl;
    }

    cout << "=========================" << endl;
}

void displayHeroes(const vector<Hero> &heroes) {
    cout << "--- Lista de Heroes ---" << endl;
    for (auto hero: heroes) {
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

void displayInventoryWeapons(Player &player) {
    vector<Weapon>& weapons = player.getInventory().getWeapons();

    if (weapons.empty()) {
        sendMessage("No tienes armas en este momento.");
        return;
    }

    for (size_t i = 0; i < weapons.size(); ++i) {
        cout << i + 1 << ". " << weapons[i].getName() << endl;
    }
    cout << weapons.size() + 1 << ". Salir" << endl;

    int option = getOption();

    if (option == weapons.size() + 1) {
        return;
    }

    if (option > 0 && option <= (weapons.size())) {
        Weapon selectedWeapon = weapons[option - 1];

        sendMessage("Elige a quien equiparle el arma:");
        for (size_t i = 0; i < player.getHeroes().size(); ++i) {
            cout << i + 1 << ". " << player.getHeroes()[i].getName() << endl;
        }

        int heroOption = getOption();
        if (heroOption > 0 && heroOption <= (player.getHeroes().size())) {
            Hero& hero = player.getHeroes()[heroOption - 1];

            if (hero.getWeapon().getName() != selectedWeapon.getName()) {
                Weapon oldWeapon = hero.getWeapon();

                sendMessage(hero.equipWeapon(selectedWeapon)); // equipa
                player.getInventory().addWeapon(oldWeapon);    // guarda arma anterior
                player.getInventory().removeWeapon(selectedWeapon); // elimina arma equipada

            } else {
                sendMessage("El heroe seleccionado ya tiene esta arma.");
            }

            return;

        } else {
            sendMessage("Opcion de heroe invalida.");
        }

    } else {
        sendMessage("Opcion invalida.");
    }

    displayInventoryWeapons(player);
}

void displayInventoryArmors(Player &player) {
    vector<Armor>& armors = player.getInventory().getArmors();

    if (armors.empty()) {
        sendMessage("No tienes armaduras en este momento.");
        return;
    }

    for (size_t i = 0; i < armors.size(); ++i) {
        cout << i + 1 << ". " << armors[i].getName() << endl;
    }
    cout << armors.size() + 1 << ". Salir" << endl;

    int option = getOption();

    if (option == armors.size() + 1) {
        return;
    }

    if (option > 0 && option <= armors.size()) {
        Armor selectedArmor = armors[option - 1];

        sendMessage("Elige a quien equiparle la armadura:");
        for (size_t i = 0; i < player.getHeroes().size(); ++i) {
            cout << i + 1 << ". " << player.getHeroes()[i].getName() << endl;
        }

        int heroOption = getOption();
        if (heroOption > 0 && heroOption <= player.getHeroes().size()) {
            Hero& hero = player.getHeroes()[heroOption - 1];

            if (hero.getArmor().getName() != selectedArmor.getName()) {
                Armor oldArmor = hero.getArmor();

                sendMessage(hero.equipArmor(selectedArmor));       // equipa
                player.getInventory().addArmor(oldArmor);          // guarda armadura anterior
                player.getInventory().removeArmor(selectedArmor);  // elimina armadura equipada

            } else {
                sendMessage("El heroe seleccionado ya tiene esta armadura.");
            }

            return;

        } else {
            sendMessage("Opcion de heroe invalida.");
        }

    } else {
        sendMessage("Opcion invalida.");
    }

    displayInventoryArmors(player);
}

void displayInventoryPotions(Player &player) {
    vector<Potion>& potions = player.getInventory().getPotions();

    if (potions.empty()) {
        sendMessage("No tienes pociones en este momento.");
        return;
    }

    for (size_t i = 0; i < potions.size(); ++i) {
        cout << i + 1 << ". x" << potions[i].getStack() << " " << potions[i].getName() << endl;
    }

    cout << potions.size() + 1 << ". Salir" << endl;

    int option = getOption();

    if (option == potions.size() + 1) {
        return;
    }

    if (option > 0 && option <= potions.size()) {
        Potion selectedPotion = potions[option - 1];

        sendMessage("Elige con quien usar la pocion: ");
        for (size_t i = 0; i < player.getHeroes().size(); ++i) {
            cout << i + 1 << ". " << player.getHeroes()[i].getName() << endl;
        }

        int heroOption = getOption();
        if (heroOption > 0 && heroOption <= player.getHeroes().size()) {
            Hero& hero = player.getHeroes()[heroOption - 1];

            if (selectedPotion.usePotion(hero)) {
                sendMessage("La pocion fue usada exitosamente!");
                player.getInventory().removePotion(selectedPotion);
            } else {
                sendMessage("No se pudo usar la pocion con " + hero.getName());
            }

            return;

        } else {
            sendMessage("Opcion de heroe invalida.");
        }

    } else {
        sendMessage("Opcion invalida.");
    }

    displayInventoryPotions(player);
}

bool displayInventory(Player &player) {
    bool exit = false;

    cout << "===== INVENTARIO =====" << endl;
    cout << "1. Armas" << endl;
    cout << "2. Armaduras" << endl;
    cout << "3. Posciones" << endl;
    cout << "4. Tus Heroes" << endl;
    cout << "5. Salir" << endl;
    int option = getOption();

    switch (option) {
        case 1:
            sendMessage("Mostrando Armas...");
            displayInventoryWeapons(player);
            break;
        case 2:
            sendMessage("Mostrando Armaduras...");
            displayInventoryArmors(player);
            break;
        case 3:
            sendMessage("Mostrando Posciones...");
            displayInventoryPotions(player);

            break;
        case 4:
            sendMessage("Mostrando heroes...");
            displayHeroes(player.getHeroes());
            break;

        case 5:
            sendMessage("Saliendo del inventario...");
            exit = true;
            break;
        default:
            cout << "Opcinn no valida. Intenta de nuevo." << endl;
    }

    return exit;
}

void displayMarketWeapons(Player &player, Market &market) {
    vector<Weapon> &weapons = market.getWeapons();

    cout << "--- ARMAS DISPONIBLES ---" << endl;
    for (size_t i = 0; i < weapons.size(); ++i) {
        cout << i + 1 << ". " << weapons[i].getName()
                << " (+" << weapons[i].getAtk() << " ATK)" << endl;
    }
    cout << weapons.size() + 1 << ". Salir" << endl;

    int option = getOption();

    // Si selecciona un arma valida
    if (option > 0 && option <= weapons.size()) {
        string weapon_name = weapons[option - 1].getName();

        sendMessage("Selecciona un heroe para equipar el arma:");
        for (size_t i = 0; i < player.getHeroes().size(); ++i) {
            Hero &hero = player.getHeroByIndex(i);
            cout << i + 1 << ". " << hero.getName() << endl;
        }

        int heroOption = getOption();
        if (heroOption > 0 && heroOption <= player.getHeroes().size()) {
            Hero &selectedHero = player.getHeroByIndex(heroOption - 1);
            sendMessage(market.buyWeapon(selectedHero, weapon_name));
        } else {
            sendMessage("Opcion de heroe invalida.");
        }
    } else if (option == weapons.size() + 1) {
        // Salir del menú
        return;
    } else {
        sendMessage("Opcinn invalida.");
    }

    displayMarketWeapons(player, market);
}

void displayMarketArmors(Player &player, Market &market) {
    vector<Armor> &armors = market.getArmors();

    cout << "--- ARMADURAS DISPONIBLES ---" << endl;
    for (size_t i = 0; i < armors.size(); ++i) {
        cout << i + 1 << ". " << armors[i].getName()
                << " (+" << armors[i].getDef() << " DEF)" << endl;
    }
    cout << armors.size() + 1 << ". Salir" << endl;

    int option = getOption();

    if (option > 0 && option <= armors.size()) {
        string armor_name = armors[option - 1].getName();

        sendMessage("Selecciona un heroe para equipar la armadura:");
        for (size_t i = 0; i < player.getHeroes().size(); ++i) {
            Hero &hero = player.getHeroByIndex(i);
            cout << i + 1 << ". " << hero.getName() << endl;
        }

        int heroOption = getOption();
        if (heroOption > 0 && heroOption <= player.getHeroes().size()) {
            Hero &selectedHero = player.getHeroByIndex(heroOption - 1);
            sendMessage(market.buyArmor(selectedHero, armor_name));
        } else {
            sendMessage("Opcinn de heroe invalida.");
        }
    } else if (option == armors.size() + 1) {
        return;
    } else {
        sendMessage("Opcinn invalida.");
    }

    displayMarketArmors(player, market);
}


void displayMarket(Player &player, Market &market) {
    cout << "===== MERCADO =====" << endl;
    cout << "1. Ver armas" << endl;
    cout << "2. Ver armaduras" << endl;
    cout << "3. Ver heroes" << endl;
    cout << "4. Salir" << endl;

    int option = getOption();


    switch (option) {
        case 1:
            sendMessage("Mostrando Armas...");
            displayMarketWeapons(player, market);
            break;
        case 2:
            sendMessage("Mostrando Armaduras...");
            displayMarketArmors(player, market);
            break;
        case 3:
            sendMessage("Mostrando Heroes...");
            displayHeroes(player.getHeroes());
            break;
        case 4:
            sendMessage("Saliendo del Mercado...");
            return;;
        default:
            sendMessage("Opcion invalida.");
    }

    displayMarket(player, market);
}

/*Dungeon loadDungeon(const Player &player, ItemRepository &itemRepository) {
    Dungeon dungeon(player);


    // Room 1
    Reward rewardRoom1("Cofre");
    Enemy enemy1("Soldado", Attribute(100, 103, 10, 10, 10), 1, 25);

    Room room1("Mazmorra de las Sombras", player, rewardRoom1);

    enemy1.addAttack(itemRepository.getAttackByName("Golpe fuerte"));
    room1.addEnemy(enemy1);

    /* Room 2

    Room room2("Caverna del Olvido", player);


    Room room3("Cripta del Destino", player);


    Room room4("Templo de la Perdicinn", player);


    Room room5("Ruinas del Eco", player);


    Room room6("Fortaleza de la Agonía", player);


    Room room7("Abismo Carmesí", player);


    Room room8("Santuario Roto", player);


    Room room9("Torre del Silencio", player);


    Room room10("Nido de la Niebla", player);
    Enemy boss("Tung Tung Tung Sahur", Attribute(999, 99, 99, 99, 99), 10, 0);
    room10.addEnemy(boss);

    dungeon.addRoom(room1);
    dungeon.addRoom(room2);
    dungeon.addRoom(room3);
    dungeon.addRoom(room4);
    dungeon.addRoom(room5);
    dungeon.addRoom(room6);
    dungeon.addRoom(room7);
    dungeon.addRoom(room8);
    dungeon.addRoom(room9);
    dungeon.addRoom(room10);

    dungeon.addRoom(room1);

    return dungeon;
}*/

bool checkAccuracy(int accuracy) {
    if (accuracy < 0) {
        return false;
    }

    int rng = rand() % 101;

    return rng <= accuracy;
}

bool checkDodge(int lck) {
    if (lck < 0) {
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

void displayReward(Reward& reward) {
    vector<Weapon> reward_weapons = reward.getWeapons();
    vector<Armor> reward_armors = reward.getArmors();
    vector<Potion> reward_potions = reward.getPotions();

    cout << "===== RECOMPENSAS =====" << endl;
    cout << "Armadursa: " << endl;
    if (!reward_armors.empty()) {
        for (const auto& armor : reward_armors) {
            cout << "   - " << armor.getName() << endl;
        }
    } else {
        cout << "   - No habia ninguna armadura." << endl;
    }

    cout << "Armas: " << endl;
    if (!reward_potions.empty()) {
        for (const auto& weapon : reward_weapons) {
            cout << "   - " << weapon.getName() << endl;
        }
    } else {
        cout << "   - No habia ninguna arma." << endl;
    }

    cout << "Pociones: " << endl;
    if (!reward_potions.empty()) {
        for (const auto& potion : reward_potions) {
            cout << "   - " << potion.getName() << endl;
        }

    } else {
        cout << "   - No habia niguna pocion." << endl;
    }



}

bool startRoom(Player &player, Dungeon &dungeon) {
    srand(time(nullptr));

    int currentHeroTurn = 0;

    bool result = true;
    cout << "holaaa" << endl;

    try {
        cout << player.getCurrentRoom() << endl;
        cout << dungeon.getRooms().size() << endl;
        Room room = dungeon.getRoom(player.getCurrentRoom());
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
                    sendMessage(
                        player_hero.getName() + " ha caído en batalla a manos de " + objetive.getName() + "...");
                    player.removeHero(player_hero.getName());
                    sendMessage(
                        "Te quedan " + to_string(player.getHeroes().size()) + " de " + to_string(MIN_HEORES) +
                        " heroes.");

                    if (player.getHeroes().size() < MIN_HEORES) {
                        sendMessage("Necesitas al menos " + to_string(MIN_HEORES) + " heroes para seguir luchando.");
                        result = false;
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

        if (result) {
            // dar recompensa
            //¡Enhorabuena, [nombre]! Has conseguido derrotar a todos los enemigos de la [zona]. Tu recompensa es un [recompensa].
            sendMessage("Enhorabuena, " + player.getName() + "! Has conseguido derrotar a todos los enemigos de la " + room.getName() + ". Tu recompensa es un " + room.getRewardName() + ".");
            displayReward(room.getReward());

            sendMessage(room.giveReward());
        }
    } catch (out_of_range &e) {
        sendMessage(e.what());
    }


    return result;
}

int main() {
    ItemRepository &itemRepository = ItemRepository::getInstance();
    Market market("Mercado");
    Dungeon* dungeon = nullptr;

    int currentDungeon = 0;

    Player* player = nullptr;
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

                player = new Player(playerName);

                sendMessage("Hola, " + playerName + ". Preparate para el combate!");
                enterToContinue();
                sendMessage("Selecciona 3 heroes para la batalla");
                enterToContinue();
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
                            if (player -> getHeroes().size() < MAX_HEROES) {
                                string heroName;
                                cout << "Para seleccionar a un heroe, escribe su nombre: ";
                                getline(cin, heroName);

                                if (!player -> isHeroExists(heroName)) {
                                    try {
                                        Hero hero = itemRepository.getHeroByName(heroName);
                                        sendMessage(player -> addHero(hero));
                                    } catch (runtime_error &e) {
                                        //sendMessage("SYSTEM", "Error cargando heroe, " + to_string(e.what()) + endl);
                                        cout << "Error cargando heroe, " << e.what() << endl;
                                    };
                                } else {
                                    sendMessage("Ese heroe ya esta en tu equipo.");
                                }
                            } else {
                                sendMessage("Ya tienes 3 heroes seleccionados.");
                            }
                            break;
                        }
                        case 2: {
                            if (!player -> getHeroes().empty()) {
                                string heroName;
                                cout << "Escribe el nombre del heroe que deseas eliminar: ";
                                getline(cin, heroName);

                                bool removed = player -> removeHero(heroName);

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
                            if (!player -> getHeroes().empty()) {
                                displayHeroes(player -> getHeroes());
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
                            if (player -> getHeroes().size() == MAX_HEROES) {
                                //state = "load_dungeons";
                                state = "Market";
                                exit = true;
                            } else {
                                sendMessage("Aun no has seleccionado todos los heroes.");
                            }
                            break;
                        }

                        default:
                            cout << "Opcion invalida." << endl;
                            break;
                    }
                }
            }
        } else if (state == "load_dungeons") {
            sendMessage("Cargando dungeons...");
            dungeon = new Dungeon(*player);
            //dungeon = loadDungeon(player, itemRepository);
            state = "Ready";
            //cout << "Referencia del jugador: " << &(*player) << endl;

        } else if (state == "Ready") {
            enterToContinue();

            if (startRoom(*player, *dungeon)) {
                player -> increaseCurrentRoom(1);

                cout << "hola" << endl;

                if (player -> getCurrentRoom() >= dungeon->getRooms().size()) {
                    // Ya gano, esto falta acomodarlo ipipipipipipi
                    cout << "ya gano" << endl;
                    enable = false;
                } else {
                    state = "Inventory";
                }
            } else {
                state = "end_game";
            }
        } else if (state == "Market") {
            displayMarket(*player, market);

            state = "load_dungeons";
        } else if (state == "Inventory") {
            if (displayInventory(*player) == true) {
                state = "Ready";
            }
        } else if (state == "end_game") {
            cout << "Ya perdiste" << endl;
        }
    }

    delete player;
    delete dungeon;

    return 0;
}