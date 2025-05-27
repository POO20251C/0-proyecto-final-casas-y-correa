//
// Created by caren on 26/05/2025.
//

#include "../include/Market.h"

Market::Market() {
    // Como la tienda es la misma para todas las partidas se iniciara los valores predeterminados de
    // los productos de la tienda

    // se crean 20 pociones y se agregan a potions
    for (int i=0; i< 20; i++) {
        potions.push_back(Potion("Pocion", "Pocion", 1, 60, 50));
    }

    // se crean 6 armaduras y se añaden a armors
    Armor arm1 = Armor("Basic Armor", 50);
    arm1.setValue(60);
    armors.push_back(arm1);
    Armor arm2 = Armor("Cota de malla", 80);
    arm2.setValue(115);
    armors.push_back(arm2);
    Armor arm3 = Armor("Grellols armor", 110);
    arm3.setValue(170);
    armors.push_back(arm3);
    Armor arm4 = Armor("Gonzos armor", 150);
    arm4.setValue(250);
    armors.push_back(arm4);
    Armor arm5 = Armor("Zeldrons Armor", 200);
    arm5.setValue(350);
    armors.push_back(arm5);
    Armor arm6 = Armor("Armadura super epica y LEGENDARIA", 1); //armadura troll
    arm6.setValue(400);
    armors.push_back(arm6);

    // se crean 8 armas y se añaden a weapons
    Weapon wea1 = Weapon("Dagger", 40, 80);
    wea1.setValue(50);
    weapons.push_back(wea1);
    Weapon wea2 = Weapon("Sword", 80, 40);
    wea2.setValue(70);
    weapons.push_back(wea2);
    Weapon wea3 = Weapon("Hammer", 90, 10);
    wea3.setValue(80);
    weapons.push_back(wea3);
    Weapon wea4 = Weapon("Katana", 110, 180);
    wea4.setValue(170);
    weapons.push_back(wea4);
    Weapon wea5 = Weapon("Dark Moon Greatsword", 170, 25);
    wea5.setValue(250);
    weapons.push_back(wea5);
    Weapon wea6 = Weapon("The Dragon Slayer", 220, 100);
    wea6.setValue(350);
    weapons.push_back(wea6);
    Weapon wea7 = Weapon("Machete montanero", 25, 130);
    wea7.setValue(25);
    weapons.push_back(wea7);
    Weapon wea8 = Weapon("Z sword", 1, 999999999); //espada troll
    wea8.setValue(180);
    weapons.push_back(wea8);
}

// los getters
std::vector<Potion> Market::getPotions() {
    return potions;
}
std::vector<Armor> Market::getArmors() {
    return armors;
}
std::vector<Weapon> Market::getWeapons() {
    return weapons;
}

// mostrar la informacion del Inventario
std::string Market::showPotions() {
    std::string ans = "";
    for (int i = 0; i < potions.size(); i++) {
        ans += std::to_string(i+1) + potions[i].getName() + ": " + std::to_string(potions[i].getValue()) + "$\n";
    }
    return ans;
}
std::string Market::showArmors() {
    std::string ans = "";
    for (int i = 0; i < armors.size(); i++) {
        ans += std::to_string(i+1) + armors[i].getName() + ": " + std::to_string(armors[i].getValue()) + "$\n";
    }
    return ans;
}
std::string Market::showWeapons() {
    std::string ans = "";
    for (int i = 0; i < weapons.size(); i++) {
        ans += std::to_string(i+1) + weapons[i].getName() + ": " + std::to_string(weapons[i].getValue()) + "$\n";
    }
    return ans;
}
std::string Market::showAll() {
    std::string ans = "";
    ans += showPotions() + "\n" + showArmors() + "\n" + showWeapons();
    return ans;
}

// comprar elementos de inventario:
// comprar Pociones
std::string Market::buyPotion(Inventory& invent, int& money, int cuant) {
    try {
        if (cuant > potions.size()) {
            throw std::out_of_range("Error: No hay suficientes pociones en la tienda.");
        }
        if (money < potions[0].getValue() * cuant) {
            throw std::runtime_error("Error: Dinero insuficiente para realizar esta compra.");
        }

        for (int i = 0; i < cuant; i++) {
            invent.addObject(potions[0]);
        }

        money -= potions[0].getValue() * cuant;
        return "Compra exitosa! Se agregaron " + std::to_string(cuant) + " pociones.";

    } catch (const std::exception& e) {
        return "Error en la compra: " + std::string(e.what());
    }
}
// comprar Armas
void Market::buyWeapon(Hero& hero, int money, int index) {
    hero.equipWeapon(weapons[index]);
    weapons.erase(weapons.begin() + index);
}
// comprar Armadura
void Market::buyArmor(Hero &hero, int money, int index) {
    hero.equipArmor(armors[index]);
    armors.erase(armors.begin() + index);
}