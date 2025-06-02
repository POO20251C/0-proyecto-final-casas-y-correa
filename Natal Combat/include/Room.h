#ifndef ROOM_H
#define ROOM_H

#include <string>
#include <vector>

#include "Player.h"
#include "Enemy.h"
#include "Reward.h"

class Room {
private:
    std::string name;
    Player* player;
    std::vector<Enemy> enemies;
    Reward reward;
public:
    Room(const std::string &name, Player& player, Reward& reward);
    void addEnemy(const Enemy& enemy);
    void removeEnemy(const Enemy& enemy);

    Enemy& getLowRankEnemy();
    std::vector<Enemy> getEnemies() const;
    std::string getName() const;
    Reward& getReward();

    std::string giveReward();
    std::string getRewardName();
};



#endif //ROOM_H
