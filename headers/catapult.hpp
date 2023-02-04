//
// Created by George on 1/9/2023.
//

#ifndef MAIN_CPP_CATAPULT_HPP
#define MAIN_CPP_CATAPULT_HPP

#include <ostream>
#include "../headers/unit.hpp"
#include "ranged_unit.hpp"

class catapult : public ranged_unit {
public:
    catapult(const double health_, const double dmg_, const double defence_, const int range_, const int movement_pts_,
             const int x_, const int y_, const int player_, double miss_chance_, unit *enemy_, bool in_range_)
            : ranged_unit(health_, dmg_, defence_, range_, movement_pts_, x_, y_, player_, "catapult", miss_chance_,
                          enemy_, in_range_) {}

    catapult(int player_, int x_, int y_);

    std::shared_ptr<unit> clone() const override { return std::make_shared<catapult>(*this); }

    catapult(const catapult &other) = default;

    friend std::ostream &operator<<(std::ostream &os, const catapult &catapult);

    void print_value() override {
        int value = this->player;
        std::cout << 6 + value;
    }

    void print_info() override {
        std::cout << this;
    }

    ~catapult() override = default;
};

#endif //MAIN_CPP_CATAPULT_HPP
