#include <iostream>
#include <vector>
/// {infantry, archers, cavalry};
class unit{
protected:
    int health;
    int dmg;
    int defence;
    int range;
    int movement_pts;
public:
    unit() = default;
    unit(const int health_, const int dmg_,const int defence_, const int range_, const int movement_pts_) :
            health{health_},dmg{dmg_},defence{defence_},range{range_}, movement_pts{movement_pts_}{}
    unit(const unit& other) :health(other.health),dmg(other.dmg),defence(other.defence),
                             range(other.range), movement_pts(other.movement_pts){}
    unit& operator=(const unit& other){
        health = other.health;
        dmg = other.dmg;
        defence = other.defence;
        range = other.range;
        movement_pts = other.movement_pts;
        std::cout<<"="<<"\n";
        return  *this;
    }
    friend std::ostream& operator<<(std::ostream& os, const unit& un);
    ~unit() = default;
};
class infantry : public unit{
    int block_chance;
public:
    infantry();
    infantry(const int health_, const int dmg_, const int defence_, const int range_, const int movement_pts_, const int block_chance_)
            : unit(health_,dmg_,defence_,range_,movement_pts_), block_chance{block_chance_}{}
    friend std::ostream& operator<<(std::ostream& os, infantry& inf);
    infantry(const infantry& other) : unit(other), block_chance{other.block_chance}{}
    ~infantry() = default;
};
class archers : public unit{
    int miss_chance;
public:
    archers();
    archers(const int health_, const int dmg_, const int defence_, const int range_, const int movement_pts_,const int miss_chance_)
            : unit(health_,dmg_,defence_,range_,movement_pts_), miss_chance{miss_chance_}{}
    friend std::ostream& operator<<(std::ostream& os,archers& arch);
    archers(const archers& other) : unit(other), miss_chance{other.miss_chance}{}
    ~archers() = default;
};
class cavalry : public unit{
    int charge_bonus;
public:
    cavalry();
    cavalry(const int health_, const int dmg_, const int defence_, const int range_, const int movement_pts_,const int charge_bonus_)
            : unit(health_,dmg_,defence_,range_,movement_pts_), charge_bonus{charge_bonus_}{}
    friend std::ostream& operator<<(std::ostream& os,cavalry& cav);
    cavalry(const cavalry& other) : unit(other), charge_bonus{other.charge_bonus}{}
    ~cavalry() = default;

};
class game{
    std::vector<infantry> infv;
    std::vector<archers> archv;
    std::vector<cavalry> cavv;
public:
    game(){}
    game( int inf_nr, int arch_nr, int cav_nr);
    friend std::ostream& operator<<(std::ostream& os,const game& gme);
    ~game(){}

};
int main() {
    std::cout << "Hello, World!" << std::endl;
    cavalry test1(100,50,50,1,5,19);
    cavalry test2;
    std::cout<<"------"<<"\n";
    std::cout << test1 <<"\n";
    std::cout << test2 <<"\n";
    std::cout<<"------"<<"\n";
    game A(2,1,1);
    std::cout<<A;


    return 0;
}
std::ostream& operator<<(std::ostream& os, const unit& un){
    os <<"Health: " << un.health << " Damage: " << un.dmg << " Defence: " << un.defence << " Range: " << un.range <<" Movement Points: " << un.movement_pts
       << " ";
    return  os;
}
infantry::infantry(){
    health = 100;
    dmg = 50;
    defence = 50;
    range = 1;
    movement_pts = 5;
    block_chance = 10;

}
std::ostream& operator<<(std::ostream& os,infantry& inf){
    os << "Health: " << inf.health << "; Damage: " << inf.dmg << "; Defence: " << inf.defence << "; Range: " << inf.range <<"; Movement Points: " << inf.movement_pts
       << "; Block chance: " << inf.block_chance;
    return os;
}
archers::archers() {
    health = 30;
    dmg = 30;
    defence = 5;
    range = 5;
    movement_pts = 7;
    miss_chance = 10;
}
std::ostream& operator<<(std::ostream& os,archers& arch){
    os << "Health: " << arch.health << "; Damage: " << arch.dmg << "; Defence: " << arch.defence << "; Range: " << arch.range <<"; Movement Points: "
       << arch.movement_pts << "; Miss chance: " << arch.miss_chance;
    return os;
}
cavalry::cavalry() {
    health = 75;
    dmg = 40;
    defence = 40;
    range = 1;
    movement_pts = 10;
    charge_bonus = 10;
}
std::ostream& operator<<(std::ostream& os,cavalry& cav){
    os << "Health: " << cav.health << "; Damage: " << cav.dmg << "; Defence: " << cav.defence << "; Range: " << cav.range <<"; Movement Points: "
       << cav.movement_pts << "; Charge bonus: " << cav.charge_bonus;
    return os;
}
game::game(int inf_nr,int arch_nr,int cav_nr){
    for (int itr = 0; itr< inf_nr;itr++){
        infv.push_back(infantry());
    }
    for (int itr = 0; itr< arch_nr;itr++){
        archv.push_back(archers());
    }
    for (int itr = 0; itr< cav_nr;itr++){
        cavv.push_back(cavalry());
    }

}
std::ostream& operator<<(std::ostream& os,const game& gme){
    for (auto itr: gme.infv) {//iteratori
        os << itr <<"\n";
    }
    for (auto itr: gme.archv) {//iteratori
        os << itr <<"\n";
    }
    for (auto itr: gme.cavv) {//iteratori
        os << itr <<"\n";
    }
    return os;
}