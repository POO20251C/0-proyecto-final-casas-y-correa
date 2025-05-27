//
// Created by caren on 21/05/2025.
//

#include "../include/Inventory.h"

Inventory::Inventory() = default;

void Inventory::addObject(Object element) {
    objects.push_back(element);
}