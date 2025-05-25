//
// Created by alejandro10213 on 14/05/2025.
//

#ifndef PLAYER_H
#define PLAYER_H

#include <vector>
#include <string>

#include "Hero.h"
#include "Inventory.h"

class Player {
private:
    std::vector<Hero> heroes;
    std::string name;
    Inventory inventory;

    void orderHeroes();
public:
    Player() = default;
    Player(const std::string &name);

    std::vector<Hero> getHeroes();
    bool removeHero(const std::string &name);

    std::string getName() const;
    Hero& getHero(const std::string &name);
    Hero& getHeroByIndex(int index);

    bool isHeroExists(const std::string &name) const;

    std::string addHero(const Hero &hero);
};



#endif //PLAYER_H
