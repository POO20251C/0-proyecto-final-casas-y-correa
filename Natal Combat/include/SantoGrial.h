//
// Created by caren on 21/05/2025.
//

#ifndef SANTOGRIAL_H
#define SANTOGRIAL_H
#include "Hero.h"
#include <vector>

class SantoGrial{
private:
  std::vector<Hero*> heroes;
  public:
    SantoGrial();
    SantoGrial(std::vector<Hero*> heroes);
    std::vector<Hero*> getHeroes();
    void healHeroes();
};

#endif //SANTOGRIAL_H
