#ifndef ARMOR_H
#define ARMOR_H

#include <string>

class Armor {
private:
    std::string name;
    int def;
public:
    Armor() = default;
    Armor(const std::string &name, int def);
    std::string getName() const;
    int getDef() const;
    void setValue(int value);
};



#endif
