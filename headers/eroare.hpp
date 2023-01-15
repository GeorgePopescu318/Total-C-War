//
// Created by George on 12/18/2022.
//

#ifndef MAIN_CPP_EROARE_HPP
#define MAIN_CPP_EROARE_HPP

#include <stdexcept>


class main_error : public std::runtime_error {
    using std::runtime_error::runtime_error;
};

class name_error : public main_error {
public:
    explicit name_error(const std::string &string_) : main_error("Invalid name: " + string_) {}
};

class end_game : public main_error {
public:
    explicit end_game(const std::string &string_) : main_error(string_) {}
};

#endif //MAIN_CPP_EROARE_HPP
