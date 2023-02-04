//
// Created by George on 1/9/2023.
//
#include <Random.hpp>
#include "../headers/catapult.hpp"
#include <random>
#include <memory>
#include<cstdio>

using Random = effolkronium::random_static;

catapult::catapult(int player_, int x_, int y_) {
    health = 50.0;
    dmg = 60.0;
    defence = 10.0;
    range = 6;
    movement_pts = 1;
    x = x_;
    y = y_;
    player = player_;
    name = "catapult";
    miss_chance = 0.75;
    enemy = nullptr;
    in_range = false;
}

std::ostream &operator<<(std::ostream &os, const catapult &cat) {
    os << "Name: " << cat.name << "\n Health: ";
    std::printf("%.2f", cat.health);
    std::cout << "\n Damage: ";
    std::printf("%.2f", cat.dmg);
    std::cout << "\n Defence: ";
    std::printf("%.2f", cat.defence);
    std::cout << "\n Range: " << cat.range << "\n Movement Points: " << cat.movement_pts
              << "\n X Location: " << cat.x << "\n Y Location: " << cat.y << "\n Player:" << cat.player
              << "\n Miss Chance: [";
    std::printf("%.2f", cat.miss_chance);
    std::cout << ",100]";
    return os;
}

