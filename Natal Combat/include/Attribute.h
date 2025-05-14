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
    Attribute() = default;
    Attribute(int hp, int atk, int def, int spd, int lck);

    int getHp() const;
    int getAtk() const;
    int getDef() const;
    int getSpd() const;
    int getLck() const;
};



#endif
