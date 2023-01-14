/// {infantry, archers, cavalry};
#include "headers/game.hpp"
#include "headers/eroare.hpp"
#include <iostream>
int main() {
    try {
        game::getInstance()->run();
    }
        catch (end_game &err) {
            std::cout << err.what() << "\n";
        }
    catch (name_error &err) {
        std::cout << err.what() << "\n";
    }

    return 0;
}


