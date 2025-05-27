#ifndef WEAPON_H
#define WEAPON_H

#include <vector>

#include "Attack.h"

class Weapon {
private:
    std::string name;
    std::string desc;
    int atk;
    int bleed;
    std::vector<Attack> attacks;
    int value;

public:
    Weapon() = default;
    Weapon(const std::string &name, int atk, int bleed);
    std::string getName() const;
    int getAtk() const;
    int getValue();
    void setValue(int value);
};



#endif
