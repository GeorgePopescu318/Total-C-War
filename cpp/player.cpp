//
// Created by George on 11/9/2022.


#include <utility>
#include "../headers/player.hpp"
#include "../headers/archers.hpp"

player::player(): id(0){}
std::ostream& operator<<(std::ostream& os,const player& ply){
    os << ply.name;
    return os;
}

void player::set_id_name(int id_, std::string name_) {
    this->id = id_;
    this->name = std::move(name_);
}

void player::emplace_units(const std::shared_ptr<unit>& other) {
    this->unitsv.push_back(other->clone());
}
int player::getId() const {
    return id;
}

void player::view_units() {
    std::cout<<"For "<<this->name<<" ";
    for (unsigned long long i = 0; i < unitsv.size(); ++i){
        if (unitsv.at(i)->getHealth() > 0) {
            std::cout <<" unit at " << *unitsv.at(i)<< " has health:" << unitsv.at(i)->getHealth()<<'\n';
        }
        else{
            unitsv.at(i) = nullptr;
            unitsv.erase(unitsv.begin() + i);
        }
    }
}
void player::view_archers(){
    for (const auto& i:unitsv){
        if (std::dynamic_pointer_cast<archers>(i) != nullptr) {
            std::dynamic_pointer_cast<archers>(i)->archers::check_range();
        }
    }
}
bool player::zero_units() {
    return unitsv.empty();
}

const std::string &player::getName() const {
    return name;
}

std::vector<std::shared_ptr<unit>> &player::getUnitsv()  {
    return unitsv;
}
