//
// Created by George on 11/8/2022.
//

#ifndef MAIN_CPP_UNIT_H
#define MAIN_CPP_UNIT_H

#include <iostream>
#include <memory>
#include <string>
#include <utility>

class unit {
protected:
    double health = 0.0;
    double dmg = 0.0;
    double defence = 0.0;
    int range = 0;
    int movement_pts = 0;
    int x = 0;
    int y = 0;
    int player = -1;
    std::string name;
public:
    unit() = default;

    unit(const double health_, const double dmg_, const double defence_, const int range_, const int movement_pts_,
         const int x_,
         const int y_, const int player_, std::string name_) :
            health{health_}, dmg{dmg_}, defence{defence_}, range{range_}, movement_pts{movement_pts_}, x{x_}, y{y_},
            player{player_}, name{std::move(name_)} {}

    unit(const unit &other) : health(other.health), dmg(other.dmg), defence(other.defence),
                              range(other.range), movement_pts(other.movement_pts), x{other.x}, y{other.y},
                              player{other.player}, name{other.name} {}

    unit &operator=(const unit &other) {
        health = other.health;
        dmg = other.dmg;
        defence = other.defence;
        range = other.range;
        movement_pts = other.movement_pts;
        x = other.x;
        y = other.y;
        player = other.player;
        return *this;
    }

    virtual void print_value() {
        std::cout << -1;
    };

    virtual void print_info() {
        std::cout << *this;
    };

    void print_name() {
        std::cout << this->name;
    }

    friend void swap(unit &u1, unit &u2) {
        using std::swap;
        swap(u1.health, u2.health);
        swap(u1.dmg, u2.dmg);
        swap(u1.defence, u2.defence);
        swap(u1.range, u2.range);
        swap(u1.movement_pts, u2.movement_pts);
        swap(u1.x, u2.x);
        swap(u1.y, u2.y);
        swap(u1.player, u2.player);
    }

    double getHealth() const;

    int getPlayer() const;

    int getMovementPts() const;

    friend std::ostream &operator<<(std::ostream &os, const unit &un);

    virtual double attack() = 0;

    virtual void defend(double enemy_attack) = 0;

    bool distance_between(const unit &other) const;

    virtual std::shared_ptr<unit> clone() const = 0;

    virtual ~unit() = default;

    void setX(int x_);

    void setY(int y_);

    int getX() const;

    int getY() const;

    void set_coordonate(int x_, int y_);
};


#endif //MAIN_CPP_UNIT_H
