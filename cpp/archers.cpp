//
// Created by George on 11/9/2022.
//
#include "../headers/archers.hpp"
#include "../headers/infantry.hpp"
#include <random>
using Random = effolkronium::random_static;
archers::archers(int player_, int x_, int y_) {
    health = 30;
    dmg = 30;
    defence = 5;
    range = 5;
    movement_pts = 7;
    miss_chance =15;
    x = x_;
    y = y_;
    player = player_;
}
std::ostream& operator<<(std::ostream& os,const archers& arch){
    os << "Health: " << arch.health << "; Damage: " << arch.dmg << "; Defence: " << arch.defence << "; Range: " << arch.range <<"; Movement Points: "
       << arch.movement_pts <<"; X Location: "<<arch.x<<"; Y Location: "<<arch.y<< "; Miss chance: " << arch.miss_chance;
    return os;
}

int archers::attack(const unit& other) const {
    auto val = Random::get(0, this->miss_chance);
    if (this->distance_between(other) <= 1) {
        return this->dmg/4;
    }
    if (this->distance_between(other) <= this->range) {
        return this->dmg*val/100;
    }
    else{
        return 0;
    }
}

void archers::defend(const unit &enemy) {
    auto val = Random::get(70.0, 100.0);
    this->health -=enemy.attack(*this)*(100.0/(100+this->defence))*(val/100);
}

