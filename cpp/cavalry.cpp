//
// Created by George on 11/9/2022.
//
#include "../headers/cavalry.hpp"
#include <Random.hpp>
#include "../headers/infantry.hpp"
#include <random>
using Random = effolkronium::random_static;
cavalry::cavalry(int player_, int x_, int y_) {
    health = 75;
    dmg = 40;
    defence = 40;
    range = 1;
    movement_pts = 10;
    charge_bonus = 10;
    x = x_;
    y = y_;
    player = player_;
}

std::ostream& operator<<(std::ostream& os,const cavalry& cav){
    os << "Health: " << cav.health << "; Damage: " << cav.dmg << "; Defence: " << cav.defence << "; Range: " << cav.range <<"; Movement Points: "
       << cav.movement_pts <<"; X Location: "<<cav.x<<"; Y Location: "<<cav.y<< "; Charge bonus: " << cav.charge_bonus;
    return os;
}

int cavalry::attack(const unit& other) const {
    if (this->distance_between(other) <= this->range) {
        return this->dmg*(100+range*10)/100;
    }
    else{
        return 0;
    }
}

void cavalry::defend(const unit &enemy) {
    auto val = Random::get(70.0, 100.0);
    this->health -=enemy.attack(*this)*(100.0/(100+this->defence))*(val/100);
}

