//
// Created by George on 11/8/2022.
//

#ifndef MAIN_CPP_INFANTRY_H
#define MAIN_CPP_INFANTRY_H

#include "../headers/unit.hpp"
#include <random>
#include <Random.hpp>

class infantry : public unit {
    double block_chance = 75.0;
public:
    infantry() = default;

    infantry(int player_, int x_, int y_);

    infantry(const double health_, const double dmg_, const double defence_, const int range_, const int movement_pts_,
             const double block_chance_, const int x_, const int y_, const int player_)
            : unit(health_, dmg_, defence_, range_, movement_pts_, x_, y_, player_, "infantry"),
              block_chance{block_chance_} {}

    friend std::ostream &operator<<(std::ostream &os, const infantry &inf);

    infantry(const infantry &other) : unit(other), block_chance{other.block_chance} {}

    void print_value() override {
        int value = this->player;
        std::cout << value;
    }

    void print_info() override {
        std::cout << *this;
    }

    std::shared_ptr<unit> clone() const override { return std::make_shared<infantry>(*this); }

    ~infantry() override = default;

    double attack() override;

    void defend(double enemy_attack) override;
};


#endif //MAIN_CPP_INFANTRY_H
