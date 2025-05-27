//
// Created by alejandro10213 on 22/05/2025.
//

#include "../include/Enemy.h"

#include "../include/ItemRepository.h"

Enemy::Enemy(const std::string &name, const Attribute &attributes, int rank, int drop) {
    this -> name = name;
    this -> attributes = attributes;
    this -> rank = rank;
    this -> drop = drop;

    this->initEquipment();
}
int Enemy::getRank() const {
    return rank;
}
