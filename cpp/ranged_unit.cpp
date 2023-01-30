//
// Created by George on 1/29/2023.
//

#include <Random.hpp>
#include "../headers/ranged_unit.hpp"

using Random = effolkronium::random_static;

void ranged_unit::set_enemy(unit &other) {
    if (this->distance_between(other)) {
        in_range = true;
        enemy = &other;
    }
}

double ranged_unit::attack() {
    return this->dmg / 4;
}

double ranged_unit::attack_ranged() {
    auto val = Random::get(miss_chance, 1.0);
    if (in_range) {
        return this->dmg * val / 100;
    } else {
        return 0;
    }
}

void ranged_unit::check_range() {
    if (enemy != nullptr) {
        if (!this->distance_between(*enemy)) {
            in_range = false;
        }
        if (in_range) {
            enemy->defend(this->attack_ranged());
        }
    }

}

ranged_unit::ranged_unit(const double health, const double dmg, const double defence, const int range,
                         const int movementPts,
                         const int x, const int y, const int player, const std::string &name, double missChance,
                         unit *enemy, bool inRange) : unit(health, dmg, defence, range, movementPts, x, y, player,
                                                           name), miss_chance(missChance), enemy(enemy),
                                                      in_range(inRange) {}

void ranged_unit::defend(double enemy_attack) {
    auto val = Random::get(0.7, 1.1);
    this->health -= int(enemy_attack * (100.0 / (100 + this->defence)) * val);
}
