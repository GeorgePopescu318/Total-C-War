//
// Created by George on 11/9/2022.
//
#include "../headers/game.hpp"
#include <random>
#include <cmath>
#include <Random.hpp>
using Random = effolkronium::random_static;
std::string game::cut(std::string s){
    s.erase(std::remove_if(s.begin(), s.end(), ::isdigit), s.end());
    return s;
}
template <class T> int game::config(int player_){
    int x_ =-1, y_=-1;
    int units_nr = 0;
    int units_order = 1;
    std::cout<<"The number of "<<cut(typeid(T).name())<<" units will be:";
    std::cin>>units_nr;
    for (auto i = 0; i < units_nr; i++) {
        std::cout << "Position of infantry " << units_order++ << " will be:\n";
        std::cin>>x_>>y_;
            for (int j = 0 ; j < 8; ++j) {
                if (y_ == j) {
                    if (x_ == (map_size+3)*(player_-1)) {
                        location0.at(j) = new T(player_, x_, y_);
                    }
                    if (x_ == 1+(map_size+3)*(player_-1)) {
                        location1.at(j) = new T(player_, x_, y_);
                    }
                    if (x_ == 2+(map_size+3)*(player_-1)) {
                        location2.at(j) = new T(player_, x_, y_);
                    }
                }
            }
        }
    return units_nr;
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
void game::print_board(){
    for (const auto &iter: board) {
        for (auto jter: iter) {
            if (jter == nullptr) {
                std::cout << "0" << " ";
            } else {
                jter->print_value();
                std::cout << " ";
            }
        }
        std::cout << "\n";
    }
}
void game::start_game() {
    std::cout<<"   [FOR PLAYER 1] \n";
    std::cout<<"You can set units in rows "<<0<<"-"<<2<<"\n";
    player1_units_nr += this->config<infantry>(1);
    // add max unit counter
    player1_units_nr += this->config<archers>(1);
    player1_units_nr += this->config<cavalry>(1);
    board.emplace_back(location0);
    board.emplace_back(location1);
    board.emplace_back(location2);
    std::cout<<'\n';
    board_fill();
    std::cout<<"   [FOR PLAYER 2] \n";
    std::cout<<"You can set units in rows "<<0+(map_size+3)<<"-"<<2+(map_size+3)<<"\n";
        fill_n(location0.begin(),8,nullptr);
        fill_n(location1.begin(),8,nullptr);
        fill_n(location2.begin(),8,nullptr);
    player2_units_nr += this->config<infantry>(2);
    player2_units_nr += this->config<archers>(2);
    player2_units_nr += this->config<cavalry>(2);
    board.emplace_back(location0);
    board.emplace_back(location1);
    board.emplace_back(location2);
    std::cout<<"\n";
    print_board();
}
void game::move_unit(int x_init, int y_init, int x_dest, int y_dest) {
    if (board.at(x_init).at(y_init) != nullptr) {
        if (board.at(x_dest).at(y_dest) == nullptr) {
            board.at(x_dest).at(y_dest) = board.at(x_init).at(y_init);
            board.at(x_init).at(y_init) = nullptr;
        } else {
            if (board.at(x_dest).at(y_dest) != nullptr) {
               std::swap(board.at(x_init).at(y_init), board.at(x_dest).at(y_dest));
            }
        }
    }
}
int game::print_option(int player_){
    int option = 0;
    std::cout<<"The options of player "<<player_<<":\nMove unit [1]\nNothing [0]\nSurrender [-1]\n";
    std::cin>>option;
    return option;
}
void game::end_game(int player_){
    std::cout<<"Congrats Player: "<<player_;
}
void game::mid_game(){
    int winner = 0;
    auto turn = Random::get({1, 2});
    int moves = 0;
    while (true) {
        if (player1_units_nr == 0 && player2_units_nr == 0){
            std::cout<<"Draw";
            break;
        }if (player1_units_nr == 0){
            end_game(2);
            break;
        }
        if (player2_units_nr == 0){
            end_game(1);
            break;
        }
        while (moves <= 3) {
            std::cout<<"You have "<< moves <<" moves\n";
            switch (print_option(turn)) {
                case 1: {
                    int x_init, y_init, x_dest, y_dest;
                    std::cout << "Enter the initial position:";
                    std::cin >> x_init >> y_init;
                    if (board.at(x_init).at(y_init)->view_player()!= turn){
                        std::cout<<"error not your unit\n";
                        break;
                    }
                    if (board.at(x_init).at(y_init) == nullptr){
                        std::cout<<"error not a unit there\n";
                        break;
                    }
                    std::cout << "Enter the destination position:";
                    std::cin >> x_dest >> y_dest;
                    if (abs((x_init+y_init)-(x_dest+y_dest)) > 4)
                    {
                        std::cout << "error distance too long\n";
                        break;
                    }
                    if (board.at(x_dest).at(y_dest) != nullptr){
                        move_unit(x_init,y_init,x_dest,y_dest);
                        moves+=2;
                        print_board();
                        break;
                    }
                    move_unit(x_init, y_init, x_dest, y_dest);
                    moves++;
                    print_board();
                    break;
                }
                case 0: {
                    moves += 5;
                    break;
                }
                case -1: {
                    if (turn == 1)
                        winner = 2;
                    else
                        winner = 1;
                    moves += 5;
                    break;
                }
                default: {
                    moves++;
                    break;
                }
            }
                }
        if (winner != 0) {
            end_game(winner);
            break;
        }
        if(turn ==1)
            turn = 2;
        else
            turn = 1;
        moves = 0;
        print_board();
    }
}
void game::run()
{
    start_game();
    mid_game();
}
game::game(){
    player1_units_nr = 0;
    player2_units_nr = 0;
    map_size = 4;
    location0.reserve(8);
    location1.reserve(8);
    location2.reserve(8);
    for (int j = 0; j < 8; ++j){
        location0.emplace_back(nullptr);
        location1.emplace_back(nullptr);
        location2.emplace_back(nullptr);
    }
    board.reserve((map_size+6)*8);
}
game::~game(){
    for (const auto& i:board){
        for (auto j:i){
            delete j;
        }
    }
}
