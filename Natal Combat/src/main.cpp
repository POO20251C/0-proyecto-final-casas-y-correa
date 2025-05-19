#include <iostream>
#include <string>
#include <vector>

#include "../include/Hero.h"
#include "../include/Player.h"

using namespace std;

Armor copyArmor(const string &name, vector<Armor> &armors) {
    Armor armor;

    for (auto armor: armors) {
        if (armor.getName() == name) {
            return armor;
        }
    }

    throw runtime_error("Armadura no encontrada");
}

Weapon copyWeapon(const string &name, vector<Weapon> &weapons) {
    Weapon weapon;

    for (const auto weapon: weapons) {
        if (weapon.getName() == name) {
            return weapon;
        }
    }

    throw runtime_error("Weapon no encontrada");
}

vector<Weapon> loadWeapons() {
    vector<Weapon> weapons;

    // Espada de madera
    weapons.emplace_back("Espada de madera", "test", 40, 5);
    return weapons;
}

vector<Armor> loadArmors() {
    vector<Armor> armors;

    // Armadura de metal
    armors.emplace_back("Armadura de metal", "test", 55);

    return armors;
}

vector<Hero> loadHeroes(vector<Weapon> &weapons, vector<Armor> &armors) {
    vector<Hero> heroes;
    Weapon weapon;
    Armor armor;

    // Alejo

    try {
        armor = copyArmor("Armadura de metal", armors);
        weapon = copyWeapon("Espada de madera", weapons);

        heroes.emplace_back("Alejo", Attribute(100, 40, 50, 10, 20), weapon, armor);
    } catch (runtime_error &e) {
        cout << "Error cargando heroe, " << "Alejo" << endl;
    }


    // Otro heroe
    try {
        armor = copyArmor("Armadura de metal", armors);
        weapon = copyWeapon("Espada de madera", weapons);

        heroes.emplace_back("Juan", Attribute(100, 40, 50, 10, 20), weapon, armor);
    } catch (runtime_error &e) {
        cout << "Error cargando heroe, " << "Juan" << endl;
    }

    // mas
    try {
        armor = copyArmor("Armadura de metal", armors);
        weapon = copyWeapon("Espada de madera", weapons);

        heroes.emplace_back("Pepe", Attribute(100, 40, 50, 10, 20), weapon, armor);
    } catch (runtime_error &e) {
        cout << "Error cargando heroe, " << "Pepe'" << endl;
    }

    return heroes;
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
    cout << "   -Salud: " << attributes.getHp() << endl;
    cout << "   -Fuerza: " << attributes.getAtk() << endl;
    cout << "   -Defensa: " << attributes.getDef() << endl;
    cout << "   -Velocidad: " << attributes.getSpd() << endl;
    cout << "   -Suerte: " << attributes.getLck() << endl;

    cout << "Arma: " << endl;
    cout << "   -Nombre: " << weapon.getName() << endl;
    cout << "   -Descripcion: " << weapon.getDesc() << endl;
    cout << "   -Daño: " << weapon.getAtk() << endl;

    cout << "Armadura: " << hero.getArmor().getName() << endl;
    cout << "   -Nombre: " << armor.getName() << endl;
    cout << "   -Descripcion: " << armor.getDesc() << endl;
    cout << "   -Defensa: " << armor.getDef() << endl;

    cout << "=========================" << endl;
}

void displayHeroes(const vector<Hero> &heroes) {
    cout << "--- Lista de Heroes ---" << endl;
    for (const auto &hero: heroes) {
        displayHero(hero);
    }
}


void sendMessage(const string &name, const string &message) {
    cout << name << ": " << message << endl;
}

void enterToContinue() {
    cout << "Pressione ENTER para continuar." << endl;
    cin.get();
}

int main() {
    vector<Weapon> weapons = loadWeapons();
    vector<Armor> armors = loadArmors();
    vector<Hero> heroes = loadHeroes(weapons, armors);

    string helperName = "Nodirsa";

    Player player;
    string state;
    string playerName = "None";
    vector<Hero> player_heroes;

    bool enable = true;

    while (enable) {
        if (playerName == "None") {
            cout << "======================================" << endl;
            cout << "    ¡Bienvenido a Natal Kombat!       " << endl;
            cout << "======================================" << endl;
            cout << "Introduce tu nombre: ";
            getline(cin, playerName);
            player = Player(playerName);
            player_heroes = player.getHeroes();
            state = "Heroes";
        } else if (state == "Heroes") {
            sendMessage(helperName, "Hola, " + playerName + ". ¡Prepárate para el combate!");
            sendMessage(helperName, "Selecciona 3 heroes para la batalla");
            sendMessage(helperName, "Para seleccionar a un héroe, escribe su nombre");
            enterToContinue();

            int option;
            bool exit = false;
            while (!exit) {
                cout << "1. Agregar héroe" << endl;
                cout << "2. Eliminar héroe" << endl;
                cout << "3. Mostrar tus héroes" << endl;
                cout << "4. Mostrar héroes" << endl;
                cout << "5. Salir" << endl;

                cin >> option;
                switch (option) {
                    case 1: {
                        if (player_heroes.size() < 3) {
                            string heroName;
                            cout << "Para seleccionar a un héroe, escribe su nombre: ";
                            cin >> heroName;

                            if (!player.isHeroExists(heroName)) {
                                try {
                                    Hero hero = getHero(heroName, heroes);
                                    sendMessage(helperName, player.addHero(hero));
                                    player_heroes = player.getHeroes();
                                } catch (runtime_error &e) {
                                    //sendMessage("SYSTEM", "Error cargando heroe, " + to_string(e.what()) + endl);
                                    cout << "Error cargando heroe, " << e.what() << endl;
                                };
                            } else {
                                sendMessage(helperName, "Ese héroe ya está en tu equipo.");
                            }
                        } else {
                            sendMessage(helperName, "Ya tienes 3 héroes seleccionados.");
                        }
                        break;
                    }
                    case 2: {
                        if (!player_heroes.empty()) {
                            string heroName;
                            cout << "Escribe el nombre del héroe que deseas eliminar: ";
                            cin >> heroName;
                        }
                        break;
                    }
                    case 3: {
                        if (!player_heroes.empty()) {
                            displayHeroes(player_heroes);
                        } else {
                            sendMessage(helperName, "Aún no has seleccionado héroes.");
                        }
                        break;
                    }

                    case 4: {
                        break;
                    }
                    case 5: {
                        if (player_heroes.size() == 3) {
                            state = "Ready";
                            exit = true;
                        } else {
                            sendMessage(helperName, "Aún no has seleccionado todos los héroes.");
                        }
                        break;
                    }

                    default:
                        cout << "Opción inválida." << endl;
                        cin.clear();
                        cin.ignore();
                        break;
                }
            }
        } else if (state == "Ready") {
            sendMessage(helperName, "¡Prepárate para el combate!");
            enterToContinue();
        }
    }


    // displayHeroes(heroes);


    return 0;
}
