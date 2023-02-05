//
// Created by George on 2/5/2023.
//

#ifndef MAIN_CPP_MENU_HPP
#define MAIN_CPP_MENU_HPP

#include <iostream>
#include <memory>
#include "Button.hpp"
#include "begin.hpp"
#include "Options.hpp"
#include "HowTo.hpp"

class Menu : public Singleton<Menu> {
private:
    int mapLength;
    int mapWidth;
    int armySize;
public:
    Menu() {
        mapLength = 5;
        mapWidth = 9;
        armySize = 9;
    }

    Menu(int mapLength, int mapWidth, int armySize) : mapLength(mapLength), mapWidth(mapWidth), armySize(armySize) {}

    void interface() {
        std::shared_ptr<Button> button;
        int option = 99;
        std::cout << "Welcome to TOTAL C WAR\n";
        while (option != -1) {
            std::cout << "Begin game [0]\nOptions [1]\nHow to play [2]\nExit[-1]";
            std::cout << "\nEnter your option:";
            std::cin >> option;
            switch (option) {
                case 0: {
                    button = std::make_shared<begin>();
                    break;
                }
                case 1: {
                    button = std::make_shared<Options>();
                    break;
                }
                case 2: {
                    button = std::make_shared<HowTo>();
                    break;
                }
                case -1: {
                    throw end_game("Exit successful!");
                }
                default: {
                    break;
                }
            }
            button->output(mapLength, mapWidth, armySize);
            button.reset();
        }
    }

    ~Menu() = default;

};

#endif //MAIN_CPP_MENU_HPP
