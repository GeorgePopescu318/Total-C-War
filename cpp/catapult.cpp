//
// Created by George on 1/9/2023.
//
#include <Random.hpp>
#include "../headers/catapult.hpp"
#include <random>
#include <memory>

using Random = effolkronium::random_static;

catapult::catapult(int player_, int x_, int y_) : miss_chance(75), enemy(nullptr), in_range(false) {
    health = 50.0;
    dmg = 60.0;
    defence = 10.0;
    range = 6;
    movement_pts = 1;
    x = x_;
    y = y_;
    player = player_;
    name = "catapult";
}

std::ostream &operator<<(std::ostream &os, const catapult &cat) {
    os << "Name: " << cat.name << "\n Health: " << cat.health << "\n Damage: " << cat.dmg << "\n Defence: "
       << cat.defence << "\n Range: "
       << cat.range << "\n Movement Points: "
       << cat.movement_pts << "\n X Location: " << cat.x << "\n Y Location: " << cat.y << "\n Miss Chance: "
       << "[" << cat.miss_chance << ",100]";
    return os;
}

