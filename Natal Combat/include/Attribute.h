#include <string>

#ifndef ATTRIBUTE_H
#define ATTRIBUTE_H



class Attribute {
private:
    int hp;
    int atk;
    int def;
    int spd;
    int lck;
public:
    Attribute(int hp, std::string atk, std::string def, int spd, int lck);
};



#endif
