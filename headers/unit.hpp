//
// Created by George on 11/8/2022.
//

#ifndef MAIN_CPP_UNIT_H
#define MAIN_CPP_UNIT_H
#include <iostream>

class unit {
protected:
    int health = 0;
    int dmg = 0;
    int defence = 0;
    int range = 0;
    int movement_pts = 0;
    int x = 0;
    int y = 0;
    int player = -1;
public:
    unit() = default;

    unit(const int health_, const int dmg_, const int defence_, const int range_, const int movement_pts_, const int x_,
         const int y_, const int player_) :
            health{health_}, dmg{dmg_}, defence{defence_}, range{range_}, movement_pts{movement_pts_}, x{x_}, y{y_} , player{player_}{}

    unit(const unit &other) : health(other.health), dmg(other.dmg), defence(other.defence),
                              range(other.range), movement_pts(other.movement_pts), x{other.x}, y{other.y}, player{other.player}{}

    unit &operator=(const unit &other) {
        health = other.health;
        dmg = other.dmg;
        defence = other.defence;
        range = other.range;
        movement_pts = other.movement_pts;
        x = other.x;
        y = other.y;
        player = other.player;
        return *this;
    }
    virtual void print_value(){
        std::cout<< -1;
    };
    friend std::ostream &operator<<(std::ostream &os, const unit &un);
    //virtual void attack(unit *enemy) = 0;
    ~unit() = default;
};


#endif //MAIN_CPP_UNIT_H
