//
// Created by George on 11/9/2022.
//
#include "../headers/cavalry.hpp"
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

