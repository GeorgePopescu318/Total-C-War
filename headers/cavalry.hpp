//
// Created by George on 11/9/2022.
//

#ifndef MAIN_CPP_CAVALRY_HPP
#define MAIN_CPP_CAVALRY_HPP

#include "../headers/unit.hpp"
class cavalry : public unit{
    int charge_bonus{};
public:
    cavalry() =default;
    cavalry(int player_, int x_, int y_);
    cavalry(const int health_, const int dmg_, const int defence_, const int range_, const int movement_pts_,
            const int charge_bonus_,const int x_, const int y_, const int player_)
            : unit(health_,dmg_,defence_,range_,movement_pts_,x_,y_,player_), charge_bonus{charge_bonus_}{}
    friend std::ostream& operator<<(std::ostream& os,const cavalry& cav);
    cavalry(const cavalry& other) : unit(other), charge_bonus{other.charge_bonus}{}
    void print_value() override{
        int value = 4+ this->player;
        std::cout<<value;
    }
    virtual ~cavalry();

};


#endif //MAIN_CPP_CAVALRY_HPP
