#ifndef ARMOR_H
#define ARMOR_H

#include <string>

class Armor {
private:
    std::string name;
    std::string desc;
    int def;
public:
    Armor() = default;
    Armor(const std::string &name, const std::string &desc, int def);
    std::string getName() const;
    std::string getDesc() const;
    int getDef() const;
};



#endif
