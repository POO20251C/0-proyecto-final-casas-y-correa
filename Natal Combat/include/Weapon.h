#ifndef WEAPON_H
#define WEAPON_H

#include <vector>

#include "Attack.h"

class Weapon {
private:
    std::string name;
    std::string desc;
    int bleed;
    std::vector<Attack> attacks;

public:
    Weapon(std::string name, std::string desc, int bleed);
};



#endif
