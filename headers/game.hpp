//
// Created by George on 11/9/2022.
//

#ifndef MAIN_CPP_GAME_HPP
#define MAIN_CPP_GAME_HPP

#include <iostream>
#include <vector>
#include "../headers/player.hpp"
#include "../headers/unit.hpp"
#include "../headers/infantry.hpp"
#include "../headers/archers.hpp"
#include "../headers/cavalry.hpp"
#include "../headers/catapult.hpp"
#include "../headers/Singeton.hpp"

class game : public Singleton<game> {
    std::vector<std::vector<std::shared_ptr<unit>>> board;
    std::vector<std::shared_ptr<unit>> location0;
    std::vector<std::shared_ptr<unit>> location1;
    std::vector<std::shared_ptr<unit>> location2;
    int map_size;
    int army_size;
    player p1;
    player p2;
public:
    game();

    void run();

    ~game() = default;

private:
    template<class T>
    int config(player &ply, int nr_units_left);

    void board_fill();

    void start_game();

    //friend std::ostream& operator<<(std::ostream& os,const game& gme);
    void mid_game();

    void print_board();

    static int print_option();

    void move_unit(int x_init, int y_init, int x_dest, int y_dest);

    static std::string cut(std::string s);

    static std::string get_name(int player_);

    void init_player(player &ply, int id);

    void check_for_attack();
};

//int game::balance_of_power = 0;
#endif //MAIN_CPP_GAME_HPP
