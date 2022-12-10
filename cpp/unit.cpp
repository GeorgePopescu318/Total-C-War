//
// Created by George on 11/8/2022.
//
#include <iostream>
#include "../headers/unit.hpp"
std::ostream& operator<<(std::ostream& os, const unit& un){
    os <<"Health: " << un.health << ";Damage: " << un.dmg << "; Defence: " << un.defence << "; Range: " << un.range <<"; Movement Points: " << un.movement_pts
       <<"; X Location: " << un.x << "; Y Location: "<< un.y << "; Player:"<<un.player;
    return  os;
}
int unit::view_player() {
    return this->player;
}