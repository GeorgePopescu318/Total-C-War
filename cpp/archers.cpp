//
// Created by George on 11/9/2022.
//
#include "../headers/archers.hpp"
#include "../headers/infantry.hpp"
#include <random>
#include <memory>
#include<cstdio>

using Random = effolkronium::random_static;

archers::archers(int player_, int x_, int y_) {
    health = 30.0;
    dmg = 30.0;
    defence = 5.0;
    range = 4;
    movement_pts = 4;
    x = x_;
    y = y_;
    player = player_;
    name = "archers";
    miss_chance = 0.70;
    enemy = nullptr;
    in_range = false;
}

std::ostream &operator<<(std::ostream &os, const archers &arch) {
    os << "Name: " << arch.name << "\n Health: ";
    std::printf("%.2f", arch.health);
    std::cout << "\n Damage: ";
    std::printf("%.2f", arch.dmg);
    std::cout << "\n Defence: ";
    std::printf("%.2f", arch.defence);
    std::cout << "\n Range: " << arch.range << "\n Movement Points: " << arch.movement_pts
              << "\n X Location: " << arch.x << "\n Y Location: " << arch.y << "\n Player:" << arch.player
              << "\n Miss Chance: [";
    std::printf("%.2f", arch.miss_chance);
    std::cout << ",100]";
    return os;
}
