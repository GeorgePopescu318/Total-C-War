//
// Created by George on 11/9/2022.
//

#ifndef MAIN_CPP_GAME_HPP
#define MAIN_CPP_GAME_HPP
#include <iostream>
#include "../headers/player.hpp"
class game{
    player p1,p2;
    // std::vector<std::vector<int> > board;
public:
    game() = default;
    void config();
    void start_game(const game& gme);
    friend std::ostream& operator<<(std::ostream& os,const game& gme);
    ~game() = default;
};


#endif //MAIN_CPP_GAME_HPP
