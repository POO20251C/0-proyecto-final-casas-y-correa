//
// Created by caren on 21/05/2025.
//

#include "../include/SantoGrial.h"

SantoGrial::SantoGrial(std::vector<Hero*> heroes){
  this->heroes = heroes;
}
std::vector<Hero*> SantoGrial::getHeroes(){
  return this->heroes;
}

void SantoGrial::healHeroes() {
  if (heroes.empty()){
    for (int i = 0; i < heroes.size(); i++){
      //int amhp = heroes[i]->getAttributes().getMhp();
      //heroes[i]->setHp(amhp);
    }
  }
}