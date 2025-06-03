#ifndef WEAPON_H
#define WEAPON_H

#include <string>

class Weapon {
private:
    std::string name;
    int atk;
public:
    Weapon() = default;
    Weapon(const std::string &name, int atk);
    std::string getName() const;
    int getAtk() const;
};



#endif
