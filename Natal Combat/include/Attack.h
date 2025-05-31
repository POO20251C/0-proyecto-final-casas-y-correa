#ifndef ATTACK_H
#define ATTACK_H

#include <string>

class Attack {
private:
    std::string name;
    std::string action;
    float power;
    int accuracy;

public:
    Attack() = default;
    Attack(const std::string &name, const std::string &action, float power, int accuracy);

    std::string getName() const;
    std::string getAction() const;

    float getPower() const;
    int getAccuracy() const;
};



#endif //ATTACK_H
