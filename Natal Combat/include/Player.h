//
// Created by alejandro10213 on 14/05/2025.
//

#ifndef PLAYER_H
#define PLAYER_H

#include <vector>
#include <string>

#include "Hero.h"
#include "Inventory.h"
#include "ItemRepository.h"
#include "Potion.h"

class Player {
private:
    std::vector<Hero> heroes;
    std::string name;
    Inventory inventory;
    int currentRoom;
    int score;
    int totalHealthLost;

    void orderHeroes();
public:
    Player(const std::string &name);

    std::vector<Hero>& getHeroes();
    Inventory& getInventory();
    std::string getName() const;
    Hero& getHero(const std::string &name);
    Hero& getHeroByIndex(int index);
    int getCurrentRoom();

    void increaseCurrentRoom(int amoun);
    void increaseScore(int amount);
    int getScore() const;

    void increaseHealthLost(int amount);
    int getTotalHealthLost() const;

    void santoGrial();
    void restoreFullHealth();
    void boostAllStatsByPercentage(int amount);

    bool removeHero(const std::string &name);
    void setMoney(int money);
    bool isHeroExists(const std::string &name) const;
    std::string addHero(const Hero &hero);
    void usePotion(Hero& hero);
};



#endif //PLAYER_H
