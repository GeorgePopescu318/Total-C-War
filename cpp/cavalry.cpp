//
// Created by George on 11/9/2022.
//
#include "../headers/cavalry.hpp"
#include <Random.hpp>
#include "../headers/infantry.hpp"
#include <random>
#include <cmath>
#include <iostream>

using Random = effolkronium::random_static;

cavalry::cavalry(int player_, int x_, int y_) : charge_bonus(1), old_x(x_), old_y(y_) {
    health = 75;
    dmg = 40;
    defence = 40;
    range = 1;
    movement_pts = 5;
    x = x_;
    y = y_;
    player = player_;
}

std::ostream &operator<<(std::ostream &os, const cavalry &cav) {
    os << "Health: " << cav.health << "; Damage: " << cav.dmg << "; Defence: " << cav.defence << "; Range: "
       << cav.range << "; Movement Points: "
       << cav.movement_pts << "; X Location: " << cav.x << "; Y Location: " << cav.y << "; Charge bonus: "
       << cav.charge_bonus;
    return os;
}

int cavalry::attack() {
    return int((this->dmg) * (1. + 0.1 * (this->position_difference())));
}

void cavalry::defend(float enemy_attack) {
    auto val = Random::get(70.0, 100.0);
    this->health -= int(enemy_attack * (100.0 / (100 + this->defence)) * (val / 100));
}

int cavalry::position_difference() {
    int distance = std::abs((this->x + this->y) - (this->old_y + this->old_x));
    old_x = x;
    old_y = y;
    return distance + charge_bonus;
}


