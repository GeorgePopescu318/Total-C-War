//
// Created by George on 11/9/2022.
//
#include "../headers/archers.hpp"
#include "../headers/infantry.hpp"
#include <random>
#include <memory>

using Random = effolkronium::random_static;
archers::archers(int player_, int x_, int y_) {
    health = 30;
    dmg = 30;
    defence = 5;
    range = 5;
    movement_pts = 7;
    miss_chance =75;
    x = x_;
    y = y_;
    player = player_;
    enemy = nullptr;
    in_range = false;
}
std::ostream& operator<<(std::ostream& os,const archers& arch){
    os << "Health: " << arch.health << "; Damage: " << arch.dmg << "; Defence: " << arch.defence << "; Range: " << arch.range <<"; Movement Points: "
       << arch.movement_pts <<"; X Location: "<<arch.x<<"; Y Location: "<<arch.y<< "; Miss chance: " << arch.miss_chance;
    return os;
}
int archers::attack_ranged() {
    auto val = Random::get( this->miss_chance, 100);
    if (in_range) {
        return this->dmg*val/100;
    }
    else{
        return 0;
    }
}
int archers::attack(const unit& other) const {
    if (this->distance_between(other) <= 1) {
        return this->dmg/4;
    }
    else{
        return 0;
    }
}
void archers::set_enemy(const std::shared_ptr<unit>& other){
    if(this->distance_between(*enemy) > 1 && this->distance_between(*enemy) < this->range){
        in_range = true;
        enemy = other;
    }
}
void archers::check_range() {
    if(!(this->distance_between(*enemy) > 1 && this->distance_between(*enemy) < this->range)){
        in_range = false;
        enemy = nullptr;
    }
    if (in_range){
        enemy->defend(*this);
    }
}
void archers::defend(const unit &opponent) {
    auto val = Random::get(70.0, 100.0);
    this->health -=opponent.attack(*this)*(100.0/(100+this->defence))*(val/100);
}

std::shared_ptr<unit> archers::getEnemy() const {
    return enemy;
}

