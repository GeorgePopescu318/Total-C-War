//
// Created by George on 2/5/2023.
//

#ifndef MAIN_CPP_BUTTON_HPP
#define MAIN_CPP_BUTTON_HPP


#include <string>

class Button {
public:
    virtual std::string output(int &mapLength, int &mapWidth, int &armySize) = 0;

    virtual ~Button() = default;
};


#endif //MAIN_CPP_BUTTON_HPP
