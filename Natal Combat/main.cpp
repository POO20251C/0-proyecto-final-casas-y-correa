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
#include "include/Score.h"

using namespace std;
using json = nlohmann::json;

const int MAX_HEROES = 3;
const int MIN_HEORES = 1;
const string helperName = "Gonzo";
//ItemRepository& itemRepository = ItemRepository::getInstance();

// Funciones auxiliares
void sendMessage(const string &message) {
    cout << helperName << ": " << message << endl;
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
    vector<Weapon> &weapons = player.getInventory().getWeapons();

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
            Hero &hero = player.getHeroes()[heroOption - 1];

            if (hero.getWeapon().getName() != selectedWeapon.getName()) {
                Weapon oldWeapon = hero.getWeapon();

                sendMessage(hero.equipWeapon(selectedWeapon)); // equipa
                player.getInventory().addWeapon(oldWeapon); // guarda arma anterior
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
    vector<Armor> &armors = player.getInventory().getArmors();

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
            Hero &hero = player.getHeroes()[heroOption - 1];

            if (hero.getArmor().getName() != selectedArmor.getName()) {
                Armor oldArmor = hero.getArmor();

                sendMessage(hero.equipArmor(selectedArmor)); // equipa
                player.getInventory().addArmor(oldArmor); // guarda armadura anterior
                player.getInventory().removeArmor(selectedArmor); // elimina armadura equipada
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
    vector<Potion> &potions = player.getInventory().getPotions();

    if (potions.empty()) {
        sendMessage("No tienes pociones en este momento.");
        return;
    }

    for (size_t i = 0; i < potions.size(); ++i) {
        cout << i + 1 << ". x" << potions[i].getStack() << " " << potions[i].getName() << " (+" << potions[i].getAmount() << "%" << endl;
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
            Hero &hero = player.getHeroes()[heroOption - 1];

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

string displayInventory(Player &player) {
    string result = "continue";

    cout << "===== INVENTARIO =====" << endl;
    cout << "Score: " << to_string(player.getScore()) << endl;
    cout << "1. Armas" << endl;
    cout << "2. Armaduras" << endl;
    cout << "3. Posciones" << endl;
    cout << "4. Tus Heroes" << endl;
    cout << "5. Abandonar partida" << endl;
    cout << "6. Salir" << endl;
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
            sendMessage("Partida terminada. Esperamos verte pronto de nuevo...");
            result = "quit";
            break;
        case 6:
            sendMessage("Saliendo del inventario...");
            result = "exit";
            break;
        default:
            sendMessage("Opcion invalida.");
    }

    return result;
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
            Hero &hero = player.getHeroes()[i];
            cout << i + 1 << ". " << hero.getName() << endl;
        }

        int heroOption = getOption();
        if (heroOption > 0 && heroOption <= player.getHeroes().size()) {
            Hero &selectedHero = player.getHeroes()[heroOption - 1];
            sendMessage(market.buyWeapon(selectedHero, weapon_name));
        } else {
            sendMessage("Opcion de heroe invalida.");
        }
    } else if (option == weapons.size() + 1) {
        // Salir del menu
        return;
    } else {
        sendMessage("Opcion invalida.");
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
            Hero &hero = player.getHeroes()[i];
            cout << i + 1 << ". " << hero.getName() << endl;
        }

        int heroOption = getOption();
        if (heroOption > 0 && heroOption <= player.getHeroes().size()) {
            Hero &selectedHero = player.getHeroes()[heroOption - 1];
            sendMessage(market.buyArmor(selectedHero, armor_name));
        } else {
            sendMessage("Opcion de heroe invalida.");
        }
    } else if (option == armors.size() + 1) {
        return;
    } else {
        sendMessage("Opcion invalida.");
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
    sendMessage("Opcion invalida.");
    return getPlayerAttack(player_hero);
}

void execute_player_attack(Player &player, Hero &player_hero, Enemy &objetive) {
    sendMessage("Turno de " + player_hero.getName() + "(Salud: " + to_string(player_hero.getAttributes().getHp()) +
                "/" + to_string(player_hero.getAttributes().getMax_hp()) + ")");

    Attack hero_attack = getPlayerAttack(player_hero); //player_hero.getAttackByIndex(0);

    // Probabilidad de que el ataque acierte + la suerete base del jugador
    if (checkAccuracy(hero_attack.getAccuracy() + player_hero.getAttributes().getLck())) {
        int score = 10;

        if (checkDodge(objetive.getAttributes().getLck())) {
            // Esquiva, no recibe daño
            //score += 0;
            sendMessage(objetive.getName() + " esquivo el ataque de " + player_hero.getName());
        } else {
            // No esquiva, sí recibe daño
            int dmg = objetive.receiveDamage(player_hero.getAttackDamage(hero_attack));
            score += dmg;
            sendMessage("Golpe acertado " + objetive.getName() + " pierde " + to_string(dmg) + " de salud. " +
                        "(Salud: " + to_string(objetive.getAttributes().getHp()) + "/" +
                        to_string(objetive.getAttributes().getMax_hp()) + ")");
        }

        player.increaseScore(score);
    } else {
        sendMessage(player_hero.getName() + " ha fallado su ataque.");
    }
}

void execute_enemy_attack(Player &player, Enemy &enemy, Hero &objetive) {
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
            player.increaseHealthLost(dmg);
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

void displayReward(Reward &reward) {
    vector<Weapon> reward_weapons = reward.getWeapons();
    vector<Armor> reward_armors = reward.getArmors();
    vector<Potion> reward_potions = reward.getPotions();

    cout << "===== RECOMPENSAS =====" << endl;
    cout << "Armadura: " << endl;
    if (!reward_armors.empty()) {
        for (const auto &armor: reward_armors) {
            cout << "   - " << armor.getName() << endl;
        }
    } else {
        cout << "   - No habia ninguna armadura." << endl;
    }

    cout << "Armas: " << endl;
    if (!reward_potions.empty()) {
        for (const auto &weapon: reward_weapons) {
            cout << "   - " << weapon.getName() << endl;
        }
    } else {
        cout << "   - No habia ninguna arma." << endl;
    }

    cout << "Pociones: " << endl;
    if (!reward_potions.empty()) {
        for (const auto &potion: reward_potions) {
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

    try {
        Room room = dungeon.getRoom(player.getCurrentRoom());
        sendMessage("Bienvenido a la " + room.getName());
        while (!room.getEnemies().empty() && result) {
            Enemy &objetive = room.getLowRankEnemy();
            cout << player.getHeroes().size() << endl;

            sendMessage(
                "Un enemigo de rango " + to_string(objetive.getRank()) + " ha aparecido! Preparate para derrotarlo!");

            while (objetive.getAttributes().getHp() > 0) {
                currentHeroTurn++;

                if (currentHeroTurn >= player.getHeroes().size()) {
                    currentHeroTurn = 0;
                }

                Hero &player_hero = player.getHeroes()[currentHeroTurn];

                execute_player_attack(player, player_hero, objetive);
                if (objetive.getAttributes().getHp() == 0) {
                    break;
                }

                enterToContinue();
                execute_enemy_attack(player, objetive, player_hero);
                enterToContinue();

                if (player_hero.getAttributes().getHp() == 0) {
                    sendMessage(
                        player_hero.getName() + " ha caido en batalla a manos de " + objetive.getName() + "...");
                    if (player.removeHero(player_hero.getName())) {
                        cout << "si " << endl;
                    } else {
                        cout << "No " << endl;
                    }
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
            }

            sendMessage(objetive.getName() + " ha sido derrotado!");
            room.removeEnemy(objetive);
            enterToContinue();
        }

        if (result) {
            // dar recompensa
            //¡Enhorabuena, [nombre]! Has conseguido derrotar a todos los enemigos de la [zona]. Tu recompensa es un [recompensa].
            sendMessage(
                "Enhorabuena, " + player.getName() + "! Has conseguido derrotar a todos los enemigos de la " + room.
                getName() + ". Tu recompensa es un " + room.getRewardName() + ".");
            displayReward(room.getReward());

            sendMessage(room.giveReward());
        }
    } catch (out_of_range &e) {
        sendMessage(e.what());
    }


    return result;
}

string formatCurrentTime() {
    auto now = chrono::system_clock::now();
    time_t now_c = chrono::system_clock::to_time_t(now);

    tm localTime = *localtime(&now_c);

    ostringstream oss;
    oss << put_time(&localTime, "%Y-%m-%d %H:%M:%S");
    return oss.str();
}

void displayGameRecord(Score &top, Player &player) {
    string name = player.getName();
    string date = formatCurrentTime();
    int room = player.getCurrentRoom();
    int health = player.getTotalHealthLost();
    int score = player.getScore();

    top.addScore(name, date, room, health, score);


    cout << "--- Registro de Partida ---" << endl;
    cout << "Nombre: " << name << endl;
    cout << "Fecha: " << date << endl;
    cout << "Maxima sala superada: " << room << endl;
    cout << "Salud perdida: " << health << endl;
    cout << "----------------------------------" << endl;
    cout << "Puntuacion final: " << score << endl;
}

void displayTop5(Score &score) {
    auto top5 = score.getTop(5);

    if (top5.empty()) {
        cout << "No hay personas en el Top aun. Conviertete en el primero!" << endl;
    } else {
        cout << "--- Top 5 Jugadores ---" << endl;
        for (size_t i = 0; i < top5.size(); ++i) {
            const auto &r = top5[i];
            cout << i + 1 << ". " << r.name << " | Score: " << r.score
                    << " | Fecha: " << r.date << " | Salud perdida: " << r.health
                    << " | Maxima sala: " << r.rooms << endl;
        }
    }
}

int main() {
    ItemRepository &itemRepository = ItemRepository::getInstance();
    Market market("Mercado");
    Dungeon *dungeon = nullptr;
    Player *player = nullptr;
    Score score;

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
                    displayTop5(score);
                    break;
                case 3:
                    enable = false;
                    break;
                default:
                    sendMessage("Opcion invalida.");
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
                            if (player->getHeroes().size() < MAX_HEROES) {
                                string heroName;
                                cout << "Para seleccionar a un heroe, escribe su nombre: ";
                                getline(cin, heroName);

                                if (!player->isHeroExists(heroName)) {
                                    try {
                                        Hero hero = itemRepository.getHeroByName(heroName);
                                        sendMessage(player->addHero(hero));
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
                            if (!player->getHeroes().empty()) {
                                string heroName;
                                cout << "Escribe el nombre del heroe que deseas eliminar: ";
                                getline(cin, heroName);

                                bool removed = player->removeHero(heroName);

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
                            if (!player->getHeroes().empty()) {
                                displayHeroes(player->getHeroes());
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
                            if (player->getHeroes().size() == MAX_HEROES) {
                                //state = "load_dungeons";
                                state = "Market";
                                exit = true;
                            } else {
                                sendMessage("Aun no has seleccionado todos los heroes.");
                            }
                            break;
                        }

                        default:
                            sendMessage("Opcion invalida.");
                            break;
                    }
                }
            }
        } else if (state == "load_dungeons") {
            sendMessage("Cargando dungeons...");
            dungeon = new Dungeon(*player);
            state = "Ready";
        } else if (state == "Ready") {
            enterToContinue();

            if (startRoom(*player, *dungeon)) {
                player->increaseCurrentRoom(1);

                if (player->getCurrentRoom() >= dungeon->getRooms().size()) {
                    sendMessage("Felicidades, has superado todas las dungeons!");
                    enable = false;
                } else {
                    player->increaseScore(100); // + 100 por cada mazmorra

                    if (player -> getCurrentRoom() >= floor(dungeon -> getRooms().size() * 0.8)) {
                        // Si supero el 80% del juego entonces evento santo grial
                        // vida y 10% mas de stats

                        player -> restoreFullHealth();
                        player -> boostAllStatsByPercentage(10);

                        sendMessage("Has encontrado el Santo Grial.");
                        enterToContinue();
                        sendMessage("Salud restaurada y +10% en todas las estadisticas.");
                        enterToContinue();
                    }

                    state = "Inventory";
                }
            } else {
                state = "end_game";
            }
        } else if (state == "Market") {
            displayMarket(*player, market);

            state = "load_dungeons";
        } else if (state == "Inventory") {
            string result = displayInventory(*player);
            if (result == "exit") {
                state = "Ready";
            } else if (result == "quit") {
                enable = false;
            }
        } else if (state == "end_game") {
            sendMessage("Has sido derrotado. No lograste completar todas las dungeons :(.");
            enable = false;
        }
    }

    if (player != nullptr) {
        sendMessage("Tu puntuacion se mostrara a continuacion...");
        enterToContinue();


        displayGameRecord(score, *player);
    }

    displayTop5(score);

    delete player;
    delete dungeon;

    return 0;
}
