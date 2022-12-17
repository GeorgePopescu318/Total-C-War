//
// Created by George on 11/8/2022.
//
#include <iostream>
#include "../headers/unit.hpp"
#include <cmath>
std::ostream& operator<<(std::ostream& os, const unit& un){
    os <<"Health: " << un.health << ";Damage: " << un.dmg << "; Defence: " << un.defence << "; Range: " << un.range <<"; Movement Points: " << un.movement_pts
       <<"; X Location: " << un.x << "; Y Location: "<< un.y << "; Player:"<<un.player;
    return  os;
}

int unit::getHealth() const {
    return health;
}

int unit::getPlayer() const {
    return player;
}

int unit::getMovementPts() const {
    return movement_pts;
}

int unit::distance_between(const unit &other) const {
    return abs(this->x + this->y - other.x - other.y);
}

std::string unit::get_position() const {
     return "at " + std::to_string(this->x) + " " +std::to_string(this->y);
}
