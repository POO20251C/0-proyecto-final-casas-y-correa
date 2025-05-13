#include <iostream>
#include <string>
#include <vector>

#include "../include/Hero.h"

using namespace std;

vector<Hero> loadHeroes() {
    vector<Hero> heroes;
    heroes.emplace_back("Alejo", Attribute(100, 40, 50, 10, 20), Weapon("Espada de madera", "Hola", 10), Armor("Armadura", "hola", 100));

    return heroes;
}

void displayHeroes(const vector<Hero> &heroes) {
    for (const auto &hero : heroes) {
        cout << hero
    }
}

int main() {
    vector<Hero> heroes = loadHeroes();
    displayHeroes(heroes);

    return 0;
}