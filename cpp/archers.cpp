//
// Created by George on 11/9/2022.
//
#include "../headers/archers.hpp"
#include "../headers/infantry.hpp"
#include <random>
#include <memory>

using Random = effolkronium::random_static;

archers::archers(int player_, int x_, int y_) : miss_chance(0.75), enemy(nullptr), in_range(false) {
    health = 30.0;
    dmg = 30.0;
    defence = 5.0;
    range = 4;
    movement_pts = 4;
    x = x_;
    y = y_;
    player = player_;
    name = "archers";
}

std::ostream &operator<<(std::ostream &os, const archers &arch) {
    os << "Name: " << arch.name << "\n Health: " << arch.health << "\n Damage: " << arch.dmg << "\n Defence: "
       << arch.defence << "\n Range: " << arch.range << "\n Movement Points: "
       << arch.movement_pts << "\n X Location: " << arch.x << "\n Y Location: " << arch.y << "\n Miss chance: "
       << arch.miss_chance;
    return os;
}
