//
// Created by George on 11/9/2022.
//
#include "../headers/game.hpp"
#include <memory>
void game::delete_pointer(unit* const ptr)
{
    delete ptr;
}
void game::config(int player_){
    int x_ =-1, y_=-1;
    std::cout<<"   [FOR PLAYER "<<player_<<"] \n";
    std::vector<unit*> location0;
    std::vector<unit*> location1;
    std::vector<unit*> location2;
    int units_nr = 0;
    int units_order = 1;
    location0.reserve(8);
    location1.reserve(8);
    location2.reserve(8);
    board.reserve((map_size+6)*8);
    std::cout<<"The number of infantry units will be:";
    std::cin>>units_nr;
    for (int j = 0; j < 8; ++j){
        location0.emplace_back(nullptr);
        location1.emplace_back(nullptr);
        location2.emplace_back(nullptr);
    }
    for (auto i = 0; i < units_nr; i++) {
        std::cout << "Position of infantry " << units_order++ << " will be:\n";
        std::cin>>x_>>y_;
            for (int j = 0 ; j < 8; ++j) {
                if (y_ == j) {
                    if (x_ == (map_size+3)*(player_-1)) {
                        location0.at(j) = new infantry(player_, x_, y_);
                    }
                    if (x_ == 1+(map_size+3)*(player_-1)) {
                        location1.at(j) = new infantry(player_, x_, y_);
                    }
                    if (x_ == 2+(map_size+3)*(player_-1)) {
                        location2.at(j) = new infantry(player_, x_, y_);
                    }
                }
            }
        }
        units_nr = 0;
        units_order = 1;
    std::cout<<"The number of archers units will be:";
    std::cin>>units_nr;
    for (auto i = 0; i < units_nr; i++) {
        std::cout << "Position of archer " << units_order++ << " will be:\n";
        std::cin>>x_>>y_;
        for (int j = 0; j < 8; ++j) {
            if (y_ == j) {
                if (x_ == (map_size+3)*(player_-1)) {
                    location0.at(j) = new archers(player_, x_, y_);
                }
                if (x_ == 1+(map_size+3)*(player_-1)) {
                    location1.at(j) = new archers(player_, x_, y_);
                }
                if (x_ == 2+(map_size+3)*(player_-1)) {
                    location2.at(j) = new archers(player_, x_, y_);
                }
            }
        }
    }
    units_nr = 0;
    units_order = 1;
    std::cout<<"The number of cavalry units will be:";
    std::cin>>units_nr;
    for (auto i = 0; i < units_nr; i++) {
        std::cout << "Position of cavalry " << units_order++ << " will be:\n";
        std::cin>>x_>>y_;
        for (int j = 0; j < 8; ++j) {
            if (y_ == j) {
                if (x_ == (map_size+3)*(player_-1)) {
                    location0.at(j) = new cavalry(player_, x_, y_);
                }
                if (x_ == 1+(map_size+3)*(player_-1)) {
                    location1.at(j) = new cavalry(player_, x_, y_);
                }
                if (x_ == 2+(map_size+3)*(player_-1)) {
                    location2.at(j) = new cavalry(player_, x_, y_);
                }
            }
        }
    }
        board.emplace_back(location0);
        board.emplace_back(location1);
        board.emplace_back(location2);
}
void game::board_fill() {
    std::vector<unit*> fill;
    for (int j = 0; j < 8; ++j){
        fill.emplace_back(nullptr);
    }
    for (int i = 0; i < map_size; ++i) {
        board.emplace_back(fill);
    }
}
void game::start_game() {
    this->config(1);
    std::cout<<'\n';
    board_fill();
    this->config(2);
    for (const auto &iter:board){
        for(auto jter:iter) {
            if (jter == nullptr) {
                std::cout << "0" << " ";
            } else {
                jter->print_value();
                std::cout << " ";
            }
        }
        std::cout<<"\n";
    }
    for (auto i:board){
        for (auto j:i){
            delete_pointer(j);
        }
    }

}
//std::ostream& operator<<(std::ostream& os,const game& gme){
//    os <<"   [PLAYER 1]\n"<< gme.p1 <<"   [PLAYER 2]\n"<< gme.p2;
//    return os;
//}
