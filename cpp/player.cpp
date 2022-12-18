//
// Created by George on 11/9/2022.


#include <utility>
#include "../headers/player.hpp"
player::player(): units_nr(0), id(0) ,f1(0),f2(0),f3(0){
    unitsv.reserve(8);
    for (int j = 0; j < 8; ++j){
        unitsv.emplace_back(nullptr);
    }
}
std::ostream& operator<<(std::ostream& os,const player& ply){
    os << ply.name;
    return os;
}

void player::set_id_name(int id_, std::string name_) {
    this->id = id_;
    this->name = std::move(name_);
}

void player::emplace_units(const std::shared_ptr<unit>& other) {
    this->unitsv.emplace_back(other);
}

void player::set_flags(int f1_, int f2_, int f3_) {
    this->f1 = f1_;
    this->f2 = f2_;
    this->f3 = f3_;
}

int player::getId() const {
    return id;
}

int player::view_units() {
    int total_health = 0;
    std::cout<<"For "<<this->name<<" ";
    for (unsigned long long i = 0; i < unitsv.size(); ++i){
        if (unitsv.at(i)->getHealth() != 0) {
            total_health+= unitsv.at(i)->getHealth();
            std::cout << typeid(i).name() << " at " << unitsv.at(i)->get_position() << " has health:" << unitsv.at(i)->getHealth()<<'\n';
        }
        else{
            unitsv.at(i) = nullptr;
            unitsv.erase(unitsv.begin() + i);
        }
    }
    std::cout<<"\n";
    return total_health;
}

void player::zero_units() {
//    if (unitsv.empty())
//        ;
        //throw
}

const std::string &player::getName() const {
    return name;
}
