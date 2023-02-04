//
// Created by George on 1/29/2023.
//

#ifndef MAIN_CPP_RANGED_UNIT_HPP
#define MAIN_CPP_RANGED_UNIT_HPP


#include "unit.hpp"

class ranged_unit : public unit {
protected:
    double miss_chance{};
    unit *enemy = nullptr;
    bool in_range = false;
public:
    ranged_unit() = default;

    ranged_unit(double health, double dmg, double defence, int range, int movementPts, int x,
                int y, int player, const std::string &name, double missChance, unit *enemy, bool inRange);

    ~ranged_unit() override = default;
    void set_enemy(unit &other);

    double attack() override;

    double attack_ranged();

    void check_range();

    void defend(double enemy_attack) override;

};


#endif //MAIN_CPP_RANGED_UNIT_HPP
