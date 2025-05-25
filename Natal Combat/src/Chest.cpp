//
// Created by caren on 21/05/2025.
//

#include "../include/Chest.h"

Chest::Chest(std::string type, std::vector<Object> items) {
    this->type = type;
    this->items = items;
}
std::string Chest::getType() {
    return this->type;
}
std::vector<Object> Chest::getItems() {
    return this->items;
}
