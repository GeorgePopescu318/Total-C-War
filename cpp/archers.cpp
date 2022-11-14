//
// Created by George on 11/9/2022.
//
#include "../headers/archers.hpp"
archers::archers(int player_, int x_, int y_) {
    health = 30;
    dmg = 30;
    defence = 5;
    range = 5;
    movement_pts = 7;
    miss_chance = 10;
    x = x_;
    y = y_;
    player = player_;
}
std::ostream& operator<<(std::ostream& os,const archers& arch){
    os << "Health: " << arch.health << "; Damage: " << arch.dmg << "; Defence: " << arch.defence << "; Range: " << arch.range <<"; Movement Points: "
       << arch.movement_pts <<"; X Location: "<<arch.x<<"; Y Location: "<<arch.y<< "; Miss chance: " << arch.miss_chance;
    return os;
}
archers::~archers(){
    delete this;
}

