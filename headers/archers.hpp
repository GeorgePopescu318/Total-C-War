//
// Created by George on 11/9/2022.
//
#ifndef MAIN_CPP_ARCHERS_H
#define MAIN_CPP_ARCHERS_H

#include <memory>
#include "../headers/unit.hpp"
#include "ranged_unit.hpp"

class archers : public ranged_unit {
    double miss_chance = 0.75;
    unit *enemy = nullptr;
    bool in_range = false;
public:
    archers(int player_, int x_, int y_);

    archers(const double health_, const double dmg_, const double defence_, const int range_, const int movement_pts_,
            const double miss_chance_,
            const int x_, const int y_, const int player_, unit *enemy_, bool in_range_)
            : ranged_unit(health_, dmg_, defence_, range_, movement_pts_, x_, y_, player_, "archers", miss_chance_,
                          enemy_, in_range_) {}

    friend std::ostream &operator<<(std::ostream &os, const archers &arch);

    archers(const archers &other) : ranged_unit(other), miss_chance{other.miss_chance}, enemy{other.enemy},
                                    in_range{other.in_range} {}

    void print_value() override {
        int value = 2 + this->player;
        std::cout << value;
    }

    void print_info() override {
        std::cout << *this;
    }

    std::shared_ptr<unit> clone() const override { return std::make_shared<archers>(*this); }

    ~archers() override = default;
};


#endif //MAIN_CPP_ARCHERS_H
