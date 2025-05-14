#include <iostream>
#include <string>
#include <vector>

#include "../include/Hero.h"
#include "../include/Player.h"

using namespace std;

Armor copyArmor(const string &name, vector<Armor> &armors) {
    Armor armor;

    for (auto armor : armors) {
        if (armor.getName() == name) {
            return armor;
        }
    }

    throw runtime_error("Armadura no encontrada");
}

Weapon copyWeapon(const string &name, vector<Weapon> &weapons) {
    Weapon weapon;

    for (auto weapon : weapons) {
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
    for (const auto &hero : heroes) {
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
    for (const auto &hero : heroes) {
        displayHero(hero);
    }

}

int main() {
    vector<Weapon> weapons = loadWeapons();
    vector<Armor> armors = loadArmors();
    vector<Hero> heroes = loadHeroes(weapons, armors);

    displayHeroes(heroes);
    vector<Hero> h;

    while (true) {
        if (h.size() == 3) {
            break;
        }

        string name;

        cout << "Nombre del heroe: " << endl;
        cin >> name;

        try {
            Hero hero = getHero(name, heroes);
            h.emplace_back(hero);

        } catch (runtime_error &e) {
            cout << "Error cargando heroe, " << "Alejo" << endl;
        };
    }

    return 0;
}