//
// Created by George on 1/9/2023.
//

#ifndef MAIN_CPP_CATAPULT_HPP
#define MAIN_CPP_CATAPULT_HPP

#include <ostream>
#include "../headers/unit.hpp"

class catapult : public unit {
    int miss_chance = 70;
    unit *enemy = nullptr;
    bool in_range = false;
public:
    catapult() = default;

    catapult(int player_, int x_, int y_);

    std::shared_ptr<unit> clone() const override { return std::make_shared<catapult>(*this); }

    friend std::ostream &operator<<(std::ostream &os, const catapult &catapult);

    void print_value() override {
        int value = this->player;
        std::cout << 6 + value;
    }

    int attack() override;

    void defend(float enemy_attack) override;

    void set_enemy(unit &other);

    void check_range();

    int attack_ranged();

    ~catapult() override = default;
};

#endif //MAIN_CPP_CATAPULT_HPP
