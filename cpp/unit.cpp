//
// Created by George on 11/8/2022.
//
#include <iostream>
#include "../headers/unit.hpp"
#include <cmath>
std::ostream& operator<<(std::ostream& os, const unit& un){
    os <<un.x<<" "<<un.y;
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
    return abs(this->x + this->y - other.getX() - other.getY());
}

void unit::setX(int x_) {
    unit::x = x_;
}

void unit::setY(int y_) {
    unit::y = y_;
}

int unit::getX() const {
    return x;
}

int unit::getY() const {
    return y;
}
