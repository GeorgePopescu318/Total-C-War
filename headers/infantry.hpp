//
// Created by George on 11/8/2022.
//

#ifndef MAIN_CPP_INFANTRY_H
#define MAIN_CPP_INFANTRY_H
#include "../headers/unit.hpp"

class infantry : public unit{
    int block_chance{};
public:
    infantry() = default;
    infantry( int player_, int x_, int y_);
    infantry(const int health_, const int dmg_, const int defence_, const int range_, const int movement_pts_,
             const int block_chance_, const int x_, const int y_, const int player_)
            : unit(health_,dmg_,defence_,range_,movement_pts_,x_,y_,player_), block_chance{block_chance_}{}
    friend std::ostream& operator<<(std::ostream& os,const infantry& inf);
    infantry(const infantry& other) : unit(other), block_chance{other.block_chance}{}
    void print_value() override{
        int value = this->player;
        std::cout<<value;
    }
    ~infantry()=default;
//    virtual void attack(unit *enemy) override{
//        this->dmg
//    }

};


#endif //MAIN_CPP_INFANTRY_H
