//
// Created by George on 11/9/2022.
//
#ifndef MAIN_CPP_ARCHERS_H
#define MAIN_CPP_ARCHERS_H

#include <memory>
#include "../headers/unit.hpp"
class archers : public unit{
    int miss_chance {};
    unit* enemy;
    bool in_range;
public:
    archers() =default;
    archers(int player_, int x_, int y_);
    archers(const int health_, const int dmg_, const int defence_, const int range_, const int movement_pts_,const int miss_chance_,
            const int x_, const int y_, const int player_, unit* enemy_, bool in_range_)
            : unit(health_,dmg_,defence_,range_,movement_pts_,x_,y_,player_), miss_chance{miss_chance_}, enemy{enemy_}, in_range{in_range_}{}
    friend std::ostream& operator<<(std::ostream& os,const archers& arch);
    archers(const archers& other) : unit(other), miss_chance{other.miss_chance}, enemy{other.enemy}, in_range{other.in_range}{}
    void print_value() override{
        int value = 2 + this->player;
        std::cout<<value;
    }
    void set_enemy( unit& other);
    std::shared_ptr<unit> clone() const override{ return std::make_shared<archers>(*this);}
    void check_range();
    int attack_ranged();
    int attack() override;
    void defend(float enemy_attack) override;
    //std::shared_ptr<unit> getEnemy() const;
    ~archers()=default;
};


#endif //MAIN_CPP_ARCHERS_H
