//
// Created by George on 11/8/2022.
//
#include "../headers/infantry.hpp"
infantry::infantry(int player_, int x_, int y_){
    health = 100;
    dmg = 50;
    defence = 50;
    range = 1;
    movement_pts = 5;
    block_chance = 10;
    x = x_;
    y = y_;
    player = player_;

}
std::ostream& operator<<(std::ostream& os,const infantry& inf){
    os << "Health: " << inf.health << "; Damage: " << inf.dmg << "; Defence: " << inf.defence << "; Range: " << inf.range <<"; Movement Points: " << inf.movement_pts
       <<"; X Location: "<< inf.x<<"; Y Location: "<<inf.y<<"; Player:"<<inf.player <<"; Block chance: " << inf.block_chance;
    return os;
}

