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

public:
    Weapon() = default;
    Weapon(const std::string &name, const std::string &desc, int atk, int bleed);
    std::string getName() const;
    std::string getDesc() const;
    int getAtk() const;
};



#endif
