//
// Created by George on 11/8/2022.
//
#include <iostream>
#include "../headers/unit.hpp"
#include <cmath>

std::ostream &operator<<(std::ostream &os, const unit &un) {
    os << un.x << " " << un.y;
    return os;
}

double unit::getHealth() const {
    return health;
}

int unit::getPlayer() const {
    return this->player;
}

int unit::getMovementPts() const {
    return movement_pts;
}

bool unit::distance_between(const unit &other) const {
    if (abs((this->x + this->y) - (other.x + other.y)) > 1 &&
        abs((this->x + this->y) - (other.x + other.y)) <= this->range) {
        return true;
    }
    return false;

}
void unit::setX(int x_) {
    this->x = x_;
}

void unit::setY(int y_) {
    this->y = y_;
}

int unit::getX() const {
    return x;
}

int unit::getY() const {
    return y;
}
//
//void set_coordonate(int x_, int y_){
//    this->x = x_;
//    this->y = y_;
//}