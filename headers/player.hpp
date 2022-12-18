//
// Created by George on 11/9/2022.
//

#ifndef MAIN_CPP_PLAYER_HPP
#define MAIN_CPP_PLAYER_HPP
#include <utility>
#include <vector>
#include <memory>
#include "unit.hpp"
class player{
    std::vector<std::shared_ptr<unit>> unitsv;
    int units_nr;
    int id;
    int f1,f2,f3;
    std::string name;
public:
    player();
    //player(int id_, std::string name_): id(id_), name(std::move(name_)){};
    void set_id_name(int id_, std::string name_);
    friend std::ostream& operator<<(std::ostream& os,const player& ply);
    void emplace_units(const std::shared_ptr<unit>& vector);
    void set_flags(int f1_, int f2_, int f3_);
    bool is_0(const std::shared_ptr<unit>& other){
        return other->getHealth() == 0;
    }
    int view_units();
    int getId() const;
    void zero_units();
    const std::string &getName() const;
    ~player() = default;

};



#endif //MAIN_CPP_PLAYER_HPP
