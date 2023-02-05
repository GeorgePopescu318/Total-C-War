//
// Created by George on 2/5/2023.
//

#ifndef MAIN_CPP_OPTIONS_HPP
#define MAIN_CPP_OPTIONS_HPP

#include <Random.hpp>
#include "Button.hpp"
#include <random>

using Random = effolkronium::random_static;

class Options : public Button {
public:
    std::string output(int &mapLength, int &mapWidth, int &armySize) override {
        std::cout
                << "\nYou can change:\nMap Length (defalut = 5) [0]\nMap Width (default = 11) [1]\nArmy size (default = 9) [2]"
                   "\n Random [3]\nExit [-1]";
        int option = 99;
        while (option != -1) {
            std::cout << "\nEnter your option: ";
            std::cin >> option;
            switch (option) {
                case 0: {
                    std::cout << "Enter your custom Map Lenght(between 1 and 25): ";
                    std::cin >> mapLength;
                    while (!(mapLength >= 1 && mapLength <= 25)) {
                        std::cout << "Map Lenght not supported, try again";
                        std::cin >> mapLength;
                    }
                    break;
                }
                case 1: {
                    std::cout << "Enter your custom Map Width(between 1 and 25): ";
                    std::cin >> mapWidth;
                    while (!(mapWidth >= 1 && mapWidth <= 25)) {
                        std::cout << "Map Width not supported, try again";
                        std::cin >> mapWidth;
                    }
                    break;
                }
                case 2: {
                    std::cout << "Enter your custom Army size(between 1 and 16): ";
                    std::cin >> armySize;
                    while (!(armySize >= 1 && armySize <= 16)) {
                        std::cout << "Map Width not supported, try again";
                        std::cin >> armySize;
                    }
                    break;
                }
                case 3: {
                    mapLength = Random::get(10, 25);
                    mapWidth = Random::get(10, 25);
                    armySize = Random::get(5, 16);
                    break;
                }
                default: {
                    break;
                }
            }
        }
        return "\nOptions completed!\n\n";
    }

};


#endif //MAIN_CPP_OPTIONS_HPP
