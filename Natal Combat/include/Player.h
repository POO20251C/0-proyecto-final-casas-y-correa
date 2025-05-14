//
// Created by alejandro10213 on 14/05/2025.
//

#ifndef PLAYER_H
#define PLAYER_H

#include <vector>

#include "Hero.h"

class Player {
private:
    std::vector<Hero> heroes;
    // inventario
public:
    Player() = default;
    Player(std::vector<Hero> &heroes);

    std::vector<Hero> getHeroes();

};



#endif //PLAYER_H
