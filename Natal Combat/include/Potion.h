#ifndef POTION_H
#define POTION_H

#include <string>

#include "Hero.h"

class Potion {
private:
    std::string name;
    std::string type;
    int stack;
    int amount;
public:
    Potion() = default;
    Potion(const std::string &name, const std::string &type, int amount);

    bool usePotion(Hero& hero);

    void increaseStack(int amount);

    std::string getName() const;
    int getStack();
    std::string getType();
    int getAmount();
};



#endif //POTION_H
