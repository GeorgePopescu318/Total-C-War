//
// Created by George on 11/9/2022.
//
#include "../headers/archers.hpp"
#include "../headers/infantry.hpp"
#include <random>
#include <memory>

using Random = effolkronium::random_static;
archers::archers(int player_, int x_, int y_): miss_chance(75),enemy(nullptr),in_range(false){
    health = 30;
    dmg = 30;
    defence = 5;
    range = 4;
    movement_pts = 4;
    x = x_;
    y = y_;
    player = player_;
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
int archers::attack() {
        return this->dmg/4;
}
void archers::set_enemy( unit& other){
    if(this->distance_between(other) > 1 && this->distance_between(other) < this->range){
        in_range = true;
        enemy = &other;
    }
}
void archers::check_range() {
    if(!(this->distance_between(*enemy) > 1 && this->distance_between(*enemy) < this->range)){
        in_range = false;
    }
    if (in_range){
        enemy->defend(this->attack_ranged());
    }
}
void archers::defend(float enemy_attack) {
    auto val = Random::get(70.0, 100.0);
    this->health -=int(enemy_attack*(100.0/(100+this->defence))*(val/100));
}

//std::shared_ptr<unit> archers::getEnemy() const {
//    return enemy;
//}

