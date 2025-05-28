//
// Created by caren on 26/05/2025.
//

#ifndef POTION_H
#define POTION_H

#include <string>

class Potion {
private:
    std::string name;
    std::string category;
    int stack;
    int cure;
    int value;
public:
    Potion() = default;
    Potion(std::string name, std::string category, int stack, int cure, int value);

    std::string getName();
    std::string getCategory();
    int getStack();
    int getCure();
    int getValue();
};



#endif //POTION_H
