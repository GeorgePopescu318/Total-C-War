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
    void config(int player_);
    void board_fill();
    void start_game(game& gme);
    //friend std::ostream& operator<<(std::ostream& os,const game& gme);
    ~game() = default;
};


#endif //MAIN_CPP_GAME_HPP
