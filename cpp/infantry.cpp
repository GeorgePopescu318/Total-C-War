//
// Created by George on 11/8/2022.
//
#include <Random.hpp>
#include "../headers/infantry.hpp"
#include <random>

using Random = effolkronium::random_static;

infantry::infantry(int player_, int x_, int y_) {
    health = 100.0;
    dmg = 50.0;
    defence = 50.0;
    range = 1;
    movement_pts = 3;
    block_chance = 0.2;
    x = x_;
    y = y_;
    player = player_;
    name = "infantry";
}

std::ostream &operator<<(std::ostream &os, const infantry &inf) {
    os << "Name: " << inf.name << "\n Health: " << inf.health << "\n Damage: " << inf.dmg << "\n Defence: "
       << inf.defence << "\n Range: "
       << inf.range << "\n Movement Points: " << inf.movement_pts
       << "\n X Location: " << inf.x << "\n Y Location: " << inf.y << "\n Player:" << inf.player << "\n Block chance: "
       << inf.block_chance;
    return os;
}

double infantry::attack() {
    return this->dmg;
}

void infantry::defend(double enemy_attack) {
    auto val = Random::get(0.7, 1.0);
    this->health -= enemy_attack * (100.0 / (100 + this->defence)) * (val - this->block_chance);
}
