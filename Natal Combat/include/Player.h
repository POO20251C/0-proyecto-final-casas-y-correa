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
    int getCurrentRoom();

    void increaseCurrentRoom(int amount);
    void increaseScore(int amount);
    int getScore() const;

    void increaseHealthLost(int amount);
    int getTotalHealthLost() const;

    void restoreFullHealth();
    void boostAllStatsByPercentage(int amount);

    bool removeHero(const std::string &name);
    bool isHeroExists(const std::string &name) const;
    std::string addHero(const Hero &hero);
};



#endif //PLAYER_H
