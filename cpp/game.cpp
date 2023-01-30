//
// Created by George on 11/9/2022.
//
#include "../headers/game.hpp"
#include "../headers/eroare.hpp"
#include <random>
#include <vector>
#include <cmath>
#include <Random.hpp>

using Random = effolkronium::random_static;

game::game() {
    map_length = 10;
    map_width = 16;
    army_size = 9;
    location0.reserve(map_width);
    location1.reserve(map_width);
    location2.reserve(map_width);
    for (int j = 0; j < map_width; ++j) {
        location0.emplace_back(nullptr);
        location1.emplace_back(nullptr);
        location2.emplace_back(nullptr);
    }
    board.reserve((map_length + spawn_limit * 2) * map_width);
}

void game::check_for_attack() {
    for (int iter = 0; iter < map_length + spawn_limit * 2; ++iter) {
        for (int jter = 0; jter < map_width; ++jter) {
            if (board.at(iter).at(jter) != nullptr) {
                std::cout << iter << " " << jter << "\n";
                double flanks = 1.0;
                if (iter + 1 < map_length + spawn_limit * 2) {
                    std::cout << "in jos1\n";
                    if (board.at(iter + 1).at(jter) != nullptr) {
                        std::cout << "in jos2\n";
                        if (board.at(iter).at(jter)->getPlayer() != board.at(iter + 1).at(jter)->getPlayer()) {
                            std::cout << "in jos3\n";
                            board.at(iter).at(jter)->defend(board.at(iter + 1).at(jter)->attack());
                        }
                    }
                }
                if (jter + 1 < map_width) {
                    std::cout << ";in dreapta1;\n";
                    if (board.at(iter).at(jter + 1) != nullptr) {
                        std::cout << ";in dreapta2;\n";
                        if (board.at(iter).at(jter)->getPlayer() != board.at(iter).at(jter + 1)->getPlayer()) {
                            std::cout << ";in dreapta3;\n";
                            flanks += 0.25;
                            board.at(iter).at(jter)->defend(board.at(iter).at(jter + 1)->attack() * flanks);
                        }
                    }
                }
                if (iter - 1 >= 0) {
                    std::cout << ";in sus1;\n";
                    if (board.at(iter - 1).at(jter) != nullptr) {
                        std::cout << ";in sus2;\n";
                        if (board.at(iter).at(jter)->getPlayer() != board.at(iter - 1).at(jter)->getPlayer()) {
                            std::cout << ";in sus3;\n";
                            flanks += 0.25;
                            board.at(iter).at(jter)->defend(flanks * board.at(iter - 1).at(jter)->attack());
                        }
                    }
                }
                if (jter - 1 >= 0) {
                    std::cout << ";in stanga1;\n";
                    if (board.at(iter).at(jter - 1) != nullptr) {
                        std::cout << ";in stanga2;\n";
                        if (board.at(iter).at(jter)->getPlayer() != board.at(iter).at(jter - 1)->getPlayer()) {
                            std::cout << ";in stanga3;\n";
                            flanks += 0.25;
                            board.at(iter).at(jter)->defend(flanks * board.at(iter).at(jter - 1)->attack());
                        }
                    }
                }
                if (board.at(iter).at(jter)->getHealth() <= 0) {
                    board.at(iter).at(jter) = nullptr;
                    break;
                }
            }
        }
    }
}

//   1
// 1 1 1
//   1
template<typename T>
int game::config(player &ply, int nr_units_left, const std::string &unit_type) {
    int x_ = -1, y_ = -1;
    int units_nr = 0;
    int units_order = 1;
    std::cout << "The number of " << unit_type << " units will be:";
    std::cin >> units_nr;
    while (units_nr > army_size) {
        std::cout << "Error too many units, try again!\n";
        std::cin >> units_nr;
    }
    while (units_nr > nr_units_left) {
        std::cout << "You don't have that many units left, try again!\n";
        std::cin >> units_nr;
    }
    for (auto i = 0; i < units_nr; i++) {
        std::cout << "Position of " << unit_type << " " << units_order++ << " will be:\n";
        std::cin >> x_ >> y_;
        for (int j = 0; j < map_width; ++j) {
            if (y_ == j) {
                if (x_ == (map_length + spawn_limit) * (ply.getId() - 1)) {
                    location0.at(j) = std::make_shared<T>(ply.getId(), x_, y_);
                    ply.getUnitsv().push_back(location0.at(j));
                }
                if (x_ == 1 + (map_length + spawn_limit) * (ply.getId() - 1)) {
                    location1.at(j) = std::make_shared<T>(ply.getId(), x_, y_);
                    ply.getUnitsv().push_back(location1.at(j));
                }
                if (x_ == 2 + (map_length + spawn_limit) * (ply.getId() - 1)) {
                    location2.at(j) = std::make_shared<T>(ply.getId(), x_, y_);
                    ply.getUnitsv().push_back(location2.at(j));
                }
            }
        }
    }
    return units_nr;

}

void game::board_fill() {
    std::vector<std::shared_ptr<unit>> fill;
    for (int j = 0; j < map_width; ++j) {
        fill.emplace_back(nullptr);
    }
    for (int i = 0; i < map_length; ++i) {
        board.emplace_back(fill);
    }
}

void game::print_board() {
    for (int l = 0; l < int(log10(map_length + 2 * spawn_limit) + 1) + 2; ++l) {
        // here I determine how much space I have to have between the board and the algebraic notation
        std::cout << " ";
    }
    for (int i = 0; i < map_width; ++i) {
        std::cout << i << " ";
    }
    for (int l = 0; l < int(log10(map_length + 2 * spawn_limit) + 1); ++l) {
        // here I determine how much space I have to have between the board and the algebraic notation
        std::cout << "\n";
    }
    int counter = 0;
    int j = 0;
    for (const auto &iter: board) {
        std::cout << j++;
        for (int l = 0; l <= int(log10(map_length + 2 * spawn_limit) + 1) - (j > 10 ? int(log10(j) + 1) - 1 : 0); ++l) {
            std::cout << " ";
        }
        for (auto jter: iter) {
            counter++;
            if (jter == nullptr) {
                std::cout << "0";
            } else {
                jter->print_value();
            }
            for (int l = 1; l <= (counter > 9 ? int(log10(map_length + 2 * spawn_limit) + 1) : 1); ++l) {
                // here I determine how much space I have to have between the board and the algebraic notation
                std::cout << " ";
            }
        }
        counter = 0;
        std::cout << "\n";
    }
    std::cout << "\n";
}

//// a1 a2 a3 a4 a5
////  0  1  2  3  4
void game::init_player(player &ply, int id) {
    ply.set_id_name(id, get_name(id));
    std::cout << "   [FOR " << ply << "] \n";
    std::cout << "You can set units in rows " << 0 + (map_length + spawn_limit) * (id - 1) << "-"
              << spawn_limit - 1 + (map_length + spawn_limit) * (id - 1)
              << "\n";
    std::cout << "You can set units in columns " << 0 << "-" << map_width - 1 << "\n";
    int nr_1 = 0;
    int nr_2 = 0;
    int nr_3 = 0;
    int nr_4 = 0;
    int nr_units_left = army_size;
    std::cout << "You have " << nr_units_left << " units left\n";
    nr_1 = this->config<infantry>(ply, nr_units_left, "infantry");
    nr_units_left -= nr_1;
    std::cout << "You have " << nr_units_left << " units left\n";
    nr_2 = this->config<archers>(ply, nr_units_left, "archers");
    nr_units_left -= nr_2;
    std::cout << "You have " << nr_units_left << " units left\n";
    nr_3 = this->config<cavalry>(ply, nr_units_left, "cavalry");
    nr_units_left -= nr_3;
    std::cout << "You have " << nr_units_left << " units left\n";
    nr_4 = this->config<catapult>(ply, nr_units_left, "catapult");
    nr_units_left -= nr_4;
    board.emplace_back(location0);
    board.emplace_back(location1);
    board.emplace_back(location2);
    std::cout << '\n';
}

void game::start_game() {
    for (int l = 0; l < int(log10(map_length + 2 * spawn_limit) + 1) + 2; ++l) {
        // here I determine how much space I have to have between the board and the algebraic notation
        std::cout << " ";
    }
    for (int i = 0; i < map_width; ++i) {
        std::cout << i << " ";
    }
    for (int l = 0; l < int(log10(map_length + 2 * spawn_limit) + 1); ++l) {
        // here I determine how much space I have to have between the board and the algebraic notation
        std::cout << "\n";
    }
    int k = 0;
    for (int i = 0; i < map_length + 2 * spawn_limit; ++i) {
        std::cout << k++;
        for (int l = 0; l <= int(log10(map_length + 2 * spawn_limit) + 1) - (k > 10 ? int(log10(k) + 1) - 1 : 0); ++l) {
            // here I determine how much space I have to have between the board and the algebraic notation
            std::cout << " ";
        }
        for (int j = 0; j < map_width; ++j) {
            std::cout << "0";
            for (int l = 1; l <= (j > 8 ? int(log10(map_length + 2 * spawn_limit) + 1) : 1); ++l) {
                // here I determine how much space I have to have between the board and the algebraic notation
                std::cout << " ";
            }
        }
        std::cout << "\n";
    }
    std::cout << "\n";
    init_player(p1, 1);
    board_fill();
    fill_n(location0.begin(), map_width, nullptr);
    fill_n(location1.begin(), map_width, nullptr);
    fill_n(location2.begin(), map_width, nullptr);
    print_board();
    init_player(p2, 2);
    std::cout << "\n";
    print_board();
    if (p1.getName() == p2.getName()) {
        throw name_error("Can't use the name " + p1.getName() + " for each player!");
    }
}

void game::move_unit(int x_init, int y_init, int x_dest, int y_dest) {
    if (board.at(x_init).at(y_init) != nullptr) {
        if (board.at(x_dest).at(y_dest) == nullptr) {
            board.at(x_init).at(y_init)->setX(x_dest);
            board.at(x_init).at(y_init)->setY(y_dest);
            board.at(x_dest).at(y_dest) = board.at(x_init).at(y_init);
            board.at(x_init).at(y_init) = nullptr;
        } else {
            if (board.at(x_dest).at(y_dest) != nullptr) {
                std::cout << "It can't go there!";
            }
        }
    }
}

int game::print_option() {
    int option = 0;
    std::cin >> option;
    return option;
}

void game::mid_game() {
    //  auto first = (Random::get({1, 2}));
    player *turn;
    player *other;
    turn = &p1;
    other = &p2;
//    if (first == 2){
//        std::swap(turn,other);
//    }
    int moves = 3;
    while (true) {
        if (turn->zero_units()) {
            if (other->zero_units()) {
                throw end_game("Draw!");
            }
            throw end_game("Congrats " + other->getName() + "!");
        } else {
            if (other->zero_units()) {
                throw end_game("Congrats " + turn->getName() + "!");
            }
        }
        while (moves > 0) {
            p1.view_units();
            p2.view_units();
            std::cout << "You have " << moves << " moves\n";
            auto balance_of_power = p1.getUnitsv().size() - p2.getUnitsv().size();
            std::cout << "The balance of power is: " << balance_of_power << "\n";
            std::cout << "The options of  " << *turn
                      << ":Skip turn [0]\nMove unit [1]\nArcher Target [2]\nCatapult Target[3]\nUnit Info[4]\nSurrender [-1]\n";
            switch (print_option()) {
                case 1: {
                    int x_init, y_init, x_dest, y_dest;
                    std::cout << "Enter the initial position:";
                    std::cin >> x_init >> y_init;
                    if (board.at(x_init).at(y_init) == nullptr) {
                        std::cout << "error not a unit there\n";
                        break;
                    }
                    if (board.at(x_init).at(y_init)->getPlayer() != turn->getId()) {
                        std::cout << "error not your unit\n";
                        break;
                    }
                    std::cout << "Enter the destination position:";
                    std::cin >> x_dest >> y_dest;
                    if (abs((x_init + y_init) - (x_dest + y_dest)) > board.at(x_init).at(y_init)->getMovementPts()) {
                        std::cout << "error distance too long\n";
                        break;
                    }
                    if (board.at(x_dest).at(y_dest) != nullptr) {
                        move_unit(x_init, y_init, x_dest, y_dest);
                        print_board();
                        break;
                    }
                    moves--;
                    move_unit(x_init, y_init, x_dest, y_dest);
                    print_board();
                    break;
                }
                case 2: {
                    int x_init, y_init, x_dest, y_dest;
                    std::cout << "Enter the archer's position: ";
                    std::cin >> x_init >> y_init;
                    if (board.at(x_init).at(y_init) == nullptr) {
                        std::cout << "Error invalid unit";
                        break;
                    }
                    std::cout << "Enter the target's position: ";
                    std::cin >> x_dest >> y_dest;
                    if (board.at(x_dest).at(y_dest) == nullptr) {
                        std::cout << "Error invalid unit";
                        break;
                    }
                    std::cout << "\n";
                    std::shared_ptr selected = std::dynamic_pointer_cast<archers>(board.at(x_init).at(y_init));
                    if (selected == nullptr) {
                        std::cout << "Error insert another unit, those are not archers";
                        break;
                    } else {
                        selected->set_enemy(*board.at(x_dest).at(y_dest));
                    }
                    break;
                }
                case 3: {
                    int x_init, y_init, x_dest, y_dest;
                    std::cout << "Enter the catapult's position: ";
                    std::cin >> x_init >> y_init;
                    if (board.at(x_init).at(y_init) == nullptr) {
                        std::cout << "Error invalid unit";
                        break;
                    }
                    std::cout << "Enter the target's position: ";
                    std::cin >> x_dest >> y_dest;
                    if (board.at(x_dest).at(y_dest) == nullptr) {
                        std::cout << "Error invalid unit";
                        break;
                    }
                    std::cout << "\n";
                    std::shared_ptr selected = std::dynamic_pointer_cast<catapult>(board.at(x_init).at(y_init));
                    if (selected == nullptr) {
                        std::cout << "Error insert another unit, that is not a catapult";
                        break;
                    } else {
                        selected->set_enemy(*board.at(x_dest).at(y_dest));
                    }
                    break;
                }
                case 4: {
                    int x_init, y_init;
                    std::cout << "Enter the unit's position: ";
                    std::cin >> x_init >> y_init;
                    if (board.at(x_init).at(y_init) == nullptr) {
                        std::cout << "Error invalid unit";
                        break;
                    }
                    board.at(x_init).at(y_init)->print_info();
                    std::cout << "\n";
                    break;
                }
                case 0: {
                    moves -= 5;
                    break;
                }
                case -1: {
                    throw end_game("Congrats " + other->getName());
                }
                default: {
                    moves--;
                    break;
                }

            }
        }
        check_for_attack();
        turn->view_ranged_units();
        std::swap(turn, other);
        turn->view_ranged_units();
        moves = 3;
        print_board();
        std::cout << "\n";
    }
}

std::string game::get_name(int player_) {
    std::string name_;
    std::cout << "Insert the name of player " << player_ << ":";
    std::cin >> name_;
    return name_;
}

void game::run() {
    start_game();
    mid_game();
}

