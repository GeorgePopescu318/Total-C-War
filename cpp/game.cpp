//
// Created by George on 11/9/2022.
//
#include "../headers/game.hpp"
void game::config(){
    int inf_nr1 = 0,arch_nr1 = 0,cav_nr1 = 0;
    std::cout<<"   [FOR PLAYER 1] \n";
    std::cout<<"The number of infantry units will be:";
    std::cin>>inf_nr1;
    std::cout<<"The number of archers units will be:";
    std::cin>>arch_nr1;
    std::cout<<"The number of cavalry units will be:";
    std::cin>>cav_nr1;
    p1.init(inf_nr1,arch_nr1,cav_nr1);
    int inf_nr2 = 0,arch_nr2 = 0,cav_nr2 = 0;
    std::cout<<"\n   [FOR PLAYER 2] \n";
    std::cout<<"The number of infantry units will be:";
    std::cin>>inf_nr2;
    std::cout<<"The number of archers units will be:";
    std::cin>>arch_nr2;
    std::cout<<"The number of cavalry units will be:";
    std::cin>>cav_nr2;
    p2.init(inf_nr1,arch_nr1,cav_nr1);
}
void game::start_game(const game& gme) {
    config();
    std::cout<<"\n/| EACH PLAYER'S ARMY /|\n";
    std::cout<<gme;
}
std::ostream& operator<<(std::ostream& os,const game& gme){
    os <<"   [PLAYER 1]\n"<< gme.p1 <<"   [PLAYER 2]\n"<< gme.p2;
    return os;
}
