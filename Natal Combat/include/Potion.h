//
// Created by caren on 26/05/2025.
//

#ifndef POTION_H
#define POTION_H
#include "Object.h"


class Potion : public Object {
private:
    int cure;
    int value;
public:
    Potion(std::string name, std::string category, int stack, int cure, int value);
    //getters
    int getCure() const;
    int getValue() const;
};



#endif //POTION_H
