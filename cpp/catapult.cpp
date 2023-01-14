//
// Created by George on 1/9/2023.
//
#include <Random.hpp>
#include "../headers/catapult.hpp"
#include <random>
#include <memory>
using Random = effolkronium::random_static;
int catapult::attack() {
    return this->dmg / 4;
}

std::ostream &operator<<(std::ostream &os, const catapult &catapult) {
    os << static_cast<const unit &>(catapult) << " miss_chance: " << catapult.miss_chance << " enemy: "
       << catapult.enemy << " in_range: " << catapult.in_range;
    return os;
}

void catapult::defend(float enemy_attack) {
    auto val = Random::get(70.0, 100.0);
    this->health -= int(enemy_attack * (100.0 / (100 + this->defence)) * (val / 100));
}

void catapult::set_enemy(unit &other) {
    if (this->distance_between(other) > 1 && this->distance_between(other) < this->range) {
        in_range = true;
        enemy = &other;
    }
}

void catapult::check_range() {
    if (enemy != nullptr) {
        if (!(this->distance_between(*enemy) > 1 && this->distance_between(*enemy) < this->range)) {
            in_range = false;
        }
        if (in_range) {
            enemy->defend(this->attack_ranged());
        }
    }
}

int catapult::attack_ranged() {
    auto val = Random::get(miss_chance, 100);
    if (in_range) {
        return this->dmg * val / 100;
    } else {
        return 0;
    }
}

catapult::catapult(int player_, int x_, int y_) : miss_chance(75), enemy(nullptr), in_range(false) {
    health = 50;
    dmg = 60;
    defence = 10;
    range = 6;
    movement_pts = 1;
    x = x_;
    y = y_;
    player = player_;
}
