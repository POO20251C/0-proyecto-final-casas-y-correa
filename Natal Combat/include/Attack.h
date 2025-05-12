#include <string>

#ifndef ATTACK_H
#define ATTACK_H

class Attack {
private:
    std::string name;
    std::string desc;
    std::string action;
    int dmg;
    int accuracy;

public:
    Attack(std::string name, std::string desc, std::string action, int dmg, int accuracy);
};



#endif //ATTACK_H
