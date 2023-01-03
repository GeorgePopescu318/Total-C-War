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
std::string game::cut(std::string s){
    s.erase(std::remove_if(s.begin(), s.end(), ::isdigit), s.end());
    return s;
}
void game::check_for_attack() {
    for (int iter = 0; iter < map_size + 6;++iter) {
        for (int jter = 0; jter < 8; ++jter) {
            if (board.at(iter).at(jter) != nullptr){
                float flanks = 1;
                if (board.at(iter).at(jter)->getHealth() <= 0){
                    board.at(iter).at(jter) = nullptr;
                    break;
                }
                if (iter+1 < map_size + 6)
                    if (board.at(iter+1).at(jter) != nullptr)
                        if(board.at(iter).at(jter)->getPlayer() != board.at(iter+1).at(jter)->getPlayer()) {
                            board.at(iter).at(jter)->defend(board.at(iter+1).at(jter)->attack());
                }
                if (jter+1 < 8)
                    if(board.at(iter).at(jter+1) != nullptr)
                        if(board.at(iter).at(jter)->getPlayer() != board.at(iter).at(jter+1)->getPlayer()) {
                            flanks += 0.25;
                            board.at(iter).at(jter)->defend(flanks*board.at(iter).at(jter+1)->attack());
                }
                if (iter-1 <= 0)
                    if(board.at(iter-1).at(jter) != nullptr)
                        if(board.at(iter).at(jter)->getPlayer() != board.at(iter-1).at(jter)->getPlayer()) {
                            flanks += 0.25;
                            board.at(iter).at(jter)->defend(flanks*board.at(iter-1).at(jter)->attack());
                }
                if (jter-1 >= 0)
                    if(board.at(iter).at(jter-1) != nullptr)
                        if(board.at(iter).at(jter)->getPlayer() != board.at(iter).at(jter-1)->getPlayer()) {
                            flanks += 0.25;
                            board.at(iter).at(jter)->defend(flanks*board.at(iter).at(jter-1)->attack());
                }
            }
        }
    }
}
//   1
// 1 1 1
//   1
template <typename T> int game::config(player& ply){
    int x_ =-1, y_=-1;
    int units_nr = 0;
    int units_order = 1;
    std::cout<<"The number of "<<cut(typeid(T).name())<<" units will be:";
    std::cin>>units_nr;
   while (units_nr > 9)
    {
        std::cout<<"Error too many units, try again!\n";
        std::cin>>units_nr;
    }
    for (auto i = 0; i < units_nr; i++) {
        std::cout << "Position of "<< cut(typeid(T).name())  <<" " << units_order++ << " will be:\n";
        std::cin>>x_>>y_;
            for (int j = 0 ; j < 8; ++j) {
                if (y_ == j) {
                    if (x_ == (map_size+3)*(ply.getId()-1)) {
                        location0.at(j) = std::make_shared<T>(ply.getId(),x_,y_);
                        ply.getUnitsv().push_back( location0.at(j));
                    }
                    if (x_ == 1+(map_size+3)*(ply.getId()-1)) {
                        location1.at(j) = std::make_shared<T>(ply.getId(),x_,y_);
                        ply.emplace_units( location1.at(j));
                    }
                    if (x_ == 2+(map_size+3)*(ply.getId()-1)) {
                        location2.at(j) = std::make_shared<T>(ply.getId(),x_,y_);
                        ply.emplace_units( location2.at(j));
                    }
                }
            }
        }
    return units_nr;

}
void game::board_fill() {
    std::vector<std::shared_ptr<unit>> fill;
    for (int j = 0; j < 8; ++j){
        fill.emplace_back(nullptr);
    }
    for (int i = 0; i < map_size; ++i) {
        board.emplace_back(fill);
    }
}
void game::print_board(){
    std::cout<<"   ";
    for (int i = 0; i < 8; ++i) {
        std::cout<<i<<" ";
    }
    std::cout<<"\n";
    int j = 0;
    for (const auto &iter: board) {
        std::cout<<j++<<"  ";
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
//// a1 a2 a3 a4 a5
////  0  1  2  3  4
void game::init_player(player& ply, int id) {
    ply.set_id_name(id, get_name(id));
    std::cout<<"   [FOR "<<ply<<"] \n";
    std::cout<<"You can set units in rows "<<0+(map_size+3)*(id-1)<<"-"<<2+(map_size+3)*(id-1)<<"\n";
    std::cout<<"You can set units in columns "<<0<<"-"<<7<<"\n";
    int nr_1 = 0;
    int nr_2 = 0;
    int nr_3 = 0;
    nr_1 = this->config<infantry>(ply);
    // add max unit counter
    nr_2 = this->config<archers>(ply);
    nr_3 = this->config<cavalry>(ply);
    ply.set_flags(nr_1 - 1,nr_1+nr_2-1,nr_1+nr_2+nr_3-1);
    board.emplace_back(location0);
    board.emplace_back(location1);
    board.emplace_back(location2);
    std::cout<<'\n';
}
void game::start_game() {
    init_player(p1,1);
    board_fill();
        fill_n(location0.begin(),8,nullptr);
        fill_n(location1.begin(),8,nullptr);
        fill_n(location2.begin(),8,nullptr);
    init_player(p2,2);
    std::cout<<"\n";
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
               std::swap(board.at(x_init).at(y_init), board.at(x_dest).at(y_dest));
            }
        }
    }
}
int game::print_option(){
    int option = 0;
    std::cin>>option;
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
        if (turn->zero_units()){
            if(other->zero_units()) {
                throw end_game("Draw!");
            }
            throw end_game("Congrats "+other->getName()+"!");
        }
        else{
            if (other->zero_units()) {
                throw end_game("Congrats "+turn->getName()+"!");
            }
        }
        while (moves  > 0) {
            std::cout << "You have " << moves << " moves\n";
            int balance_of_power = turn->view_units() - other->view_units();
            std::cout << "The balance of power is: " << balance_of_power << "\n";
            std::cout << "The options of  " << *turn
                      << ":\nMove unit [1]\nNothing [0]\nSurrender [-1]\nArcher Target [2]";
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
                        moves -= 2;
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
                    std::cout << "Enter the target's position: ";
                    std::cin >> x_dest >> y_dest;
                    std::cout << "\n";
                    std::shared_ptr selected = std::dynamic_pointer_cast<archers>(board.at(x_init).at(y_init));
                    if (selected == nullptr) {
                        std::cout << "Error insert another unit, those are not archers";
                        break;
                    } else {
                        selected->set_enemy(board.at(x_dest).at(y_dest));
                    }
                    moves-=1;
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
            turn->view_archers();
            std::swap(turn,other);
            check_for_attack();
            turn->view_archers();
            moves = 3;
            print_board();
            std::cout<<"\n";
    }
}
std::string game::get_name(int player_) {
    std::string name_;
    std::cout<<"Insert the name of player "<<player_<<":";
    std::cin>>name_;
    return name_;
}
void game::run(){
    start_game();
    mid_game();
}
game::game(){
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

