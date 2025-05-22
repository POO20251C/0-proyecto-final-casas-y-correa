//
// Created by caren on 21/05/2025.
//

#include "../include/Inventory.h"

Inventory::Inventory(std::vector<Object> objects) {
    this -> objects = objects;
}

void Inventory::addObject(Object element) {
    objects.push_back(element);
}

