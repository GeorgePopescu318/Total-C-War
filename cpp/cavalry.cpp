//
// Created by George on 11/9/2022.
//
#include "../headers/cavalry.hpp"
#include <Random.hpp>
#include "../headers/infantry.hpp"
#include <random>
#include <cmath>
#include <iostream>
#include<cstdio>

using Random = effolkronium::random_static;

cavalry::cavalry(int player_, int x_, int y_) : charge_bonus(1.0), old_x(x_), old_y(y_) {
    health = 75.0;
    dmg = 40.0;
    defence = 40.0;
    range = 1;
    movement_pts = 5;
    x = x_;
    y = y_;
    player = player_;
    name = "cavalry";
}

std::ostream &operator<<(std::ostream &os, const cavalry &cav) {
    os << "Name: " << cav.name << "\n Health: ";
    std::printf("%.2f", cav.health);
    std::cout << "\n Damage: ";
    std::printf("%.2f", cav.dmg);
    std::cout << "\n Defence: ";
    std::printf("%.2f", cav.defence);
    std::cout << "\n Range: " << cav.range << "\n Movement Points: " << cav.movement_pts
              << "\n X Location: " << cav.x << "\n Y Location: " << cav.y << "\n Player:" << cav.player
              << "\n Charge bonus: ";
    std::printf("%.2f", cav.charge_bonus);
    return os;
}

double cavalry::attack() {
    auto dmg_reduction = Random::get(0.7, 1.0);// this determines the random reduction of the dmg
    return (this->dmg * position_difference()) * dmg_reduction;
}

void cavalry::defend(double enemy_attack) {
    this->health -= enemy_attack * (100.0 / (100.0 + this->defence));
}

double cavalry::position_difference() {
    int distance = std::abs((this->x + this->y) - (this->old_y + this->old_x));
    old_x = x;
    old_y = y;
    if (distance == 1) {
        return 1.0;
    }
    return 1. + (0.1 * (distance + charge_bonus));
}


