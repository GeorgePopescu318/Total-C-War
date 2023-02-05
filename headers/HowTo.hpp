//
// Created by George on 2/5/2023.
//

#ifndef MAIN_CPP_HOWTO_HPP
#define MAIN_CPP_HOWTO_HPP

#include "Button.hpp"

class HowTo : public Button {
public:
    std::string output(int &mapLength, int &mapWidth, int &armySize) override {
        std::cout << "Ask George!\nThe Map Length is " << mapLength << "\nThe Map Width is " << mapWidth
                  << "\nThe Army Size is "
                  << armySize << "\nYou can change these in the Options menu";
        return "\nHow to play ended!\n\n";
    }

};

#endif //MAIN_CPP_HOWTO_HPP
