#include "../include/ItemRepository.h"

#include <iostream>
#include <stdexcept>
#include <bits/ostream.tcc>


ItemRepository::ItemRepository() {
    // Ataques:
    // Los ataques tienen un maximo de 70 de presicion
    attacks.emplace_back("Golpe fuerte", 1.1, 70);
    attacks.emplace_back("Drago_Aliento", 2.5, 40);
    attacks.emplace_back("Estocada_Oscura", 2.0, 50);
    attacks.emplace_back("Golpe_Oseo", 1.0, 68);
    attacks.emplace_back("Abracadabra", 1.5, 60);
    attacks.emplace_back("Bofetada", 0.8, 70);
    attacks.emplace_back("Picadura_poderoza", 1.4, 65);
    attacks.emplace_back("Impacto_rocoso", 2.2, 45);
    attacks.emplace_back("Ice_age", 2.0, 50);
    attacks.emplace_back("Golpe_de_Gracia", 3.0, 35);

    // Armaduras
    armors.emplace_back("Sin armadura", 0);
    armors.emplace_back("Ropaje", 10);
    armors.emplace_back("Armadura de huesos", 20);
    armors.emplace_back("Armadura de Hierro", 60);
    armors.emplace_back("Armadura de Acero", 70);
    armors.emplace_back("Armadura de Cuero Reforzado", 45);
    armors.emplace_back("Armadura de Plata", 65);
    armors.emplace_back("Armadura de Bronce", 50);
    armors.emplace_back("Armadura de Titanio", 80);
    armors.emplace_back("Armadura de Escamas", 40);
    armors.emplace_back("Armadura de Laton", 48);
    armors.emplace_back("Tunica magica", 45);
    armors.emplace_back("Cota de malla", 32);
    armors.emplace_back("Armadura Berserker", 90);
    armors.emplace_back("Armadura de escamas de dragon", 80);

    // Armas:
    weapons.emplace_back("Sin arma", 0);
    weapons.emplace_back("Espada de Hierro", 10);
    weapons.emplace_back("Espada Larga de Acero", 65);
    weapons.emplace_back("Hacha de Mano", 55);
    weapons.emplace_back("Lanza de Madera Reforzada", 40);
    weapons.emplace_back("Maza de Bronce", 60);
    weapons.emplace_back("Daga Curva", 45);
    weapons.emplace_back("Martillo de Guerra", 70);
    weapons.emplace_back("Arco de Cazador", 50);
    weapons.emplace_back("Ballesta Liviana", 55);
    weapons.emplace_back("Espada Bastarda", 75);
    weapons.emplace_back("Dragon slayer", 100);
    weapons.emplace_back("Colmillo de sabueso", 80);
    weapons.emplace_back("Katana", 75);
    weapons.emplace_back("Chainsaw", 70);

    // pociones
    potions.emplace_back("Pocion Pequena de Salud", "Health", 10);
    potions.emplace_back("Pocion Mediana de Salud", "Health", 25);
    potions.emplace_back("Pocion Grande de Salud", "Health", 50);
    potions.emplace_back("Elixir de Salud", "Health", 100);


    try {
        std::string name1 = "Kratos";
        Attribute attribute1(80, 90, 25, 30, 40);
        Hero hero1(name1, attribute1);
        hero1.equipArmor(this->getArmorByName("Armadura de Cuero Reforzado"));
        hero1.equipWeapon(this->getWeaponByName("Espada Bastarda"));
        hero1.addAttack(this->getAttackByName("Golpe_de_Gracia"));
        hero1.addAttack(this->getAttackByName("Estocada_Oscura"));
        hero1.addAttack(this->getAttackByName("Golpe fuerte"));
        heroes.push_back(hero1);


        std::string name2 = "Atreus";
        Attribute attribute2(140, 40, 80, 20, 45);
        Hero hero2(name2, attribute2);
        hero2.equipArmor(this->getArmorByName("Armadura de Titanio"));
        hero2.equipWeapon(this->getWeaponByName("Lanza de Madera Reforzada"));
        hero2.addAttack(this->getAttackByName("Golpe_Oseo"));
        hero2.addAttack(this->getAttackByName("Bofetada"));
        hero2.addAttack(this->getAttackByName("Picadura_poderoza"));
        heroes.push_back(hero2);


        std::string name3 = "Ragnar";
        Attribute attribute3(120, 85, 55, 25, 10);
        Hero hero3(name3, attribute3);
        hero3.equipArmor(this->getArmorByName("Armadura Berserker"));
        hero3.equipWeapon(this->getWeaponByName("Martillo de Guerra"));
        hero3.addAttack(this->getAttackByName("Impacto_rocoso"));
        hero3.addAttack(this->getAttackByName("Drago_Aliento"));
        hero3.addAttack(this->getAttackByName("Golpe fuerte"));
        heroes.push_back(hero3);


        std::string name4 = "Selene";
        Attribute attribute4(100, 75, 40, 35, 12);
        Hero hero4(name4, attribute4);
        hero4.equipArmor(this->getArmorByName("Tunica magica"));
        hero4.equipWeapon(this->getWeaponByName("Katana"));
        hero4.addAttack(this->getAttackByName("Ice_age"));
        hero4.addAttack(this->getAttackByName("Abracadabra"));
        hero4.addAttack(this->getAttackByName("Golpe fuerte"));
        heroes.push_back(hero4);


        std::string name5 = "Lior";
        Attribute attribute5(110, 65, 60, 30, 35);
        Hero hero5(name5, attribute5);
        hero5.equipArmor(this->getArmorByName("Armadura de Plata"));
        hero5.equipWeapon(this->getWeaponByName("Espada de Hierro"));
        hero5.addAttack(this->getAttackByName("Golpe fuerte"));
        hero5.addAttack(this->getAttackByName("Abracadabra"));
        hero5.addAttack(this->getAttackByName("Estocada_Oscura"));
        heroes.push_back(hero5);

    } catch (std::runtime_error &e) {
        std::cout << e.what() << std::endl;
    }
}

Armor ItemRepository::getArmorByName(const std::string &name) {
    for (const auto armor: armors) {
        if (armor.getName() == name) {
            return armor;
        }
    }

    throw std::runtime_error("No se encontro la armadura " + name);
}

Weapon ItemRepository::getWeaponByName(const std::string &name) {
    for (const auto weapon: weapons) {
        if (weapon.getName() == name) {
            return weapon;
        }
    }

    throw std::runtime_error("No se encontro el arma " + name);
}

Hero ItemRepository::getHeroByName(const std::string &name) {
    for (const auto hero: heroes) {
        if (hero.getName() == name) {
            return hero;
        }
    }

    throw std::runtime_error("No se encontro el heroe " + name);
}

Attack ItemRepository::getAttackByName(const std::string &name) {
    for (const auto attack: attacks) {
        if (attack.getName() == name) {
            return attack;
        }
    }

    throw std::runtime_error("No se encontro el ataque " + name);
}

Potion ItemRepository::getPotionByName(const std::string &name) {
    for (auto potion: potions) {
        if (potion.getName() == name) {
            return potion;
        }
    }

    throw std::runtime_error("No se encontro la pocion " + name);
}


ItemRepository &ItemRepository::getInstance() {
    static ItemRepository instance;
    return instance;
}


std::vector<Hero> ItemRepository::getHeroes() const {
    return heroes;
}
