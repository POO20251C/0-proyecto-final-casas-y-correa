#ifndef POTION_H
#define POTION_H

#include <string>

class Potion {
private:
    std::string name;
    std::string type;
    int stack;
    int amount;
public:
    Potion() = default;
    Potion(const std::string &name, const std::string &type, int amount);

    std::string getName();
};



#endif //POTION_H
