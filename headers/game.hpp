//
// Created by George on 11/9/2022.
//

#ifndef MAIN_CPP_GAME_HPP
#define MAIN_CPP_GAME_HPP
#include <iostream>
#include <vector>
#include "../headers/unit.hpp"
#include "../headers/infantry.hpp"
#include "../headers/archers.hpp"
#include "../headers/cavalry.hpp"
class game{
    std::vector< std::vector<unit*> > board;
    std::vector<unit*> location0;
    std::vector<unit*> location1;
    std::vector<unit*> location2;
    int player1_units_nr;
    int player2_units_nr;
    int map_size;
public:
    game();
    void run();
    ~game();
private:
    template <class T> int config(int player_);
    void board_fill();
    void start_game();
    //friend std::ostream& operator<<(std::ostream& os,const game& gme);
    void mid_game();
    void print_board();
    int print_option(int player_);
    void move_unit(int x_init, int y_init, int x_dest, int y_dest);
    void end_game(int player_);
    std::string cut(std::string s);
};


#endif //MAIN_CPP_GAME_HPP
