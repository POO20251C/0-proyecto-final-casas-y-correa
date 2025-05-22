//
// Created by caren on 21/05/2025.
//

#ifndef INVENTORY_H
#define INVENTORY_H
#include "Object.h"
#include <vector>

class Inventory {
private:
    std::vector<Object> objects;
public:
    //constructores
    Inventory();

    //getters
    std::vector<Object> getObjects();
    //metodos
    void addObject(Object element);
};



#endif //INVENTORY_H
