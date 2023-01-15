//
// Created by George on 11/9/2022.
//

#ifndef MAIN_CPP_PLAYER_HPP
#define MAIN_CPP_PLAYER_HPP

#include <utility>
#include <vector>
#include <memory>
#include "unit.hpp"

class player {
    std::vector<std::shared_ptr<unit>> unitsv;
    int id;
    std::string name;
public:
    player();

    //player(int id_, std::string name_): id(id_), name(std::move(name_)){};
    void set_id_name(int id_, std::string name_);

    friend std::ostream &operator<<(std::ostream &os, const player &ply);

    void emplace_units(const std::shared_ptr<unit> &vector);

    bool is_0(const std::shared_ptr<unit> &other) {
        return other->getHealth() == 0;
    }

    std::vector<std::shared_ptr<unit>> &getUnitsv();

    void view_units();

    void view_ranged_units();

    int getId() const;

    bool zero_units();

    const std::string &getName() const;

    ~player() = default;
};


#endif //MAIN_CPP_PLAYER_HPP
