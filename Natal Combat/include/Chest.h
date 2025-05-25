//
// Created by caren on 21/05/2025.
//

#ifndef CHEST_H
#define CHEST_H
#include "Object.h"
#include <string>
#include <vector>

class Chest {
private:
    std::string type;
    std::vector<Object> items;
public:
    Chest();
    Chest(std::string type, std::vector<Object> items);
    std::string getType();
    std::vector<Object> getItems();
};



#endif //CHEST_H
