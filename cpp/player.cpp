//
// Created by George on 11/9/2022.
//

#include "../headers/player.hpp"

void player::init(const int inf_nr,const int arch_nr,const int cav_nr){
    for (int itr = 0; itr< inf_nr;itr++){
        infv.push_back(infantry());
    }
    for (int itr = 0; itr< arch_nr;itr++){
        archv.push_back(archers());
    }
    for (int itr = 0; itr< cav_nr;itr++){
        cavv.push_back(cavalry());
    }

}
std::ostream& operator<<(std::ostream& os,const player& ply){
    for (auto itr: ply.infv) {
        os << itr <<"\n";
    }
    for (auto itr: ply.archv) {
        os << itr <<"\n";
    }
    for (auto itr: ply.cavv) {
        os << itr <<"\n";
    }
    return os;
}
