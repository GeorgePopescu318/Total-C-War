//
// Created by George on 2/5/2023.
//

#ifndef MAIN_CPP_BEGIN_HPP
#define MAIN_CPP_BEGIN_HPP


#include "Button.hpp"
#include "Singeton.hpp"
#include "game.hpp"

class begin : public Button {
public:
    void output(int &mapLength, int &mapWidth, int &armySize) override {
        game g1(mapLength, mapWidth, armySize);
        g1.run();
    }

    ~begin() override = default;

    begin() = default;
};


#endif //MAIN_CPP_BEGIN_HPP
