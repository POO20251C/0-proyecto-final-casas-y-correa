//
// Created by caren on 21/05/2025.
//

#include "../include/Object.h"

#include <bits/fs_fwd.h>

Object::Object() {
    name = "Unknown";
    category = "Unknown";
    stack = 0;
}

Object::Object(std::string name, std::string category, int stack) {
    this->name = name;
    this->category = category;
    this->stack = stack;
}

std::string Object::getName() {
    return name;
}
std::string Object::getCategory() {
    return category;
}
int Object::getStack() {
    return stack;
}