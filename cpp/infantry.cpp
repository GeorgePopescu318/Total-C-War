//
// Created by George on 11/8/2022.
//
#include <Random.hpp>
#include "../headers/infantry.hpp"
#include <random>
using Random = effolkronium::random_static;
infantry::infantry(int player_, int x_, int y_){
    health = 100;
    dmg = 50;
    defence = 50;
    range = 1;
    movement_pts = 5;
    block_chance = 15;
    x = x_;
    y = y_;
    player = player_;
}
std::ostream& operator<<(std::ostream& os,const infantry& inf){
    os << "Health: " << inf.health << "; Damage: " << inf.dmg << "; Defence: " << inf.defence << "; Range: " << inf.range <<"; Movement Points: " << inf.movement_pts
       <<"; X Location: "<< inf.x<<"; Y Location: "<<inf.y<<"; Player:"<<inf.player <<"; Block chance: " << inf.block_chance;
    return os;
}

int infantry::attack(const unit& other) const{
    if (this->distance_between(other) <= this->range) {
        return this->dmg;
    }
    else{
        return 0;
    }
}

void infantry::defend(const unit& enemy) {
    auto val = Random::get(70.0, 100.0);
    this->health -=enemy.attack(*this)*(100.0/(100+this->defence))*(val-this->block_chance)/100;
}
