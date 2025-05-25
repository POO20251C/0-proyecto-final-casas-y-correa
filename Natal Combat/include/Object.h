//
// Created by caren on 21/05/2025.
//

#ifndef OBJECT_H
#define OBJECT_H
#include <string>


class Object {
protected:
    std::string name;
    std::string category;
    int stack;

public:
    Object();
    Object(std::string name, std::string category, int stack);
    std::string getName();
    std::string getCategory();
    int getStack();
};



#endif //OBJECT_H
