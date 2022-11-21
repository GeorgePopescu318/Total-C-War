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
    int map_size = 4;
public:
    game() = default;
    void run();
    ~game() = default;
private:
    void config(int player_);
    void board_fill();
    void start_game();
    //friend std::ostream& operator<<(std::ostream& os,const game& gme);
    void mid_game();
    void print_board();
    int print_option(int player_);
    void move_unit(int x_init, int y_init, int x_dest, int y_dest);
    void end_game(int player_);
    void delete_pointer(unit* const ptr );
};


#endif //MAIN_CPP_GAME_HPP
