#ifndef ENEMY_H
#define ENEMY_H

#include "Character.h"


class Enemy : public Character {
public:
    Enemy() = default;
    Enemy(const std::string &name, const Attribute &attributes, int rank);

    int getRank() const;
private:
    int rank;
};

#endif //ENEMY_H