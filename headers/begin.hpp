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
    std::string output(int &mapLength, int &mapWidth, int &armySize) override {
        std::shared_ptr<game> g1 = std::make_shared<game>(mapLength, mapWidth, armySize);
        g1->run();
        return "";
    }
};


#endif //MAIN_CPP_BEGIN_HPP
