#include <iostream>
#include <vector>
/// {infantry, archers, cavalry};
class unit{
protected:
    int health = 0;
    int dmg = 0;
    int defence = 0;
    int range = 0;
    int movement_pts = 0;
    int x = 0;
    int y = 0;
public:
    unit() = default;
    unit(const int health_, const int dmg_,const int defence_, const int range_, const int movement_pts_, const int x_, const int y_) :
            health{health_},dmg{dmg_},defence{defence_},range{range_}, movement_pts{movement_pts_}, x{x_},y{y_}{}
    unit(const unit& other) :health(other.health),dmg(other.dmg),defence(other.defence),
                             range(other.range), movement_pts(other.movement_pts), x{other.x}, y{other.y}{}
    unit& operator=(const unit& other){
        health = other.health;
        dmg = other.dmg;
        defence = other.defence;
        range = other.range;
        movement_pts = other.movement_pts;
        x = other.x;
        y = other.y;
        return  *this;
    }
    friend std::ostream& operator<<(std::ostream& os, const unit& un);
    ~unit() = default;
};
class infantry : public unit{
    int block_chance;
public:
    infantry();
    infantry(const int health_, const int dmg_, const int defence_, const int range_, const int movement_pts_, const int block_chance_, const int x_, const int y_)
            : unit(health_,dmg_,defence_,range_,movement_pts_,x_,y_), block_chance{block_chance_}{}
    friend std::ostream& operator<<(std::ostream& os,const infantry& inf);
    infantry(const infantry& other) : unit(other), block_chance{other.block_chance}{}
    ~infantry() = default;
};
class archers : public unit{
    int miss_chance;
public:
    archers();
    archers(const int health_, const int dmg_, const int defence_, const int range_, const int movement_pts_,const int miss_chance_, const int x_, const int y_)
            : unit(health_,dmg_,defence_,range_,movement_pts_,x_,y_), miss_chance{miss_chance_}{}
    friend std::ostream& operator<<(std::ostream& os,const archers& arch);
    archers(const archers& other) : unit(other), miss_chance{other.miss_chance}{}
    ~archers() = default;
};
class cavalry : public unit{
    int charge_bonus;
public:
    cavalry();
    cavalry(const int health_, const int dmg_, const int defence_, const int range_, const int movement_pts_,const int charge_bonus_,const int x_, const int y_)
            : unit(health_,dmg_,defence_,range_,movement_pts_,x_,y_), charge_bonus{charge_bonus_}{}
    friend std::ostream& operator<<(std::ostream& os,const cavalry& cav);
    cavalry(const cavalry& other) : unit(other), charge_bonus{other.charge_bonus}{}
    ~cavalry() = default;

};
class player{
    std::vector<infantry> infv;
    std::vector<archers> archv;
    std::vector<cavalry> cavv;
public:
    player() = default;
    void init( int inf_nr, int arch_nr, int cav_nr);
    friend std::ostream& operator<<(std::ostream& os,const player& ply);
    ~player() = default;

};
class game{
    player p1,p2;
    std::vector<std::vector<int> > board;
public:
    game() = default;
    void config();
    void start_game(const game& gme);
    friend std::ostream& operator<<(std::ostream& os,const game& gme);
    ~game() = default;
};
int main() {
    game g1;
    g1.start_game(g1);
    return 0;
}
std::ostream& operator<<(std::ostream& os, const unit& un){
    os <<"Health: " << un.health << ";Damage: " << un.dmg << "; Defence: " << un.defence << "; Range: " << un.range <<"; Movement Points: " << un.movement_pts
    <<"; X Location: " << un.x << "; Y Location: "<< un.y;
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
std::ostream& operator<<(std::ostream& os,const infantry& inf){
    os << "Health: " << inf.health << "; Damage: " << inf.dmg << "; Defence: " << inf.defence << "; Range: " << inf.range <<"; Movement Points: " << inf.movement_pts
       <<"; X Location: "<< inf.x<<"; Y Location: "<<inf.y<< "; Block chance: " << inf.block_chance;
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
std::ostream& operator<<(std::ostream& os,const archers& arch){
    os << "Health: " << arch.health << "; Damage: " << arch.dmg << "; Defence: " << arch.defence << "; Range: " << arch.range <<"; Movement Points: "
       << arch.movement_pts <<"; X Location: "<<arch.x<<"; Y Location: "<<arch.y<< "; Miss chance: " << arch.miss_chance;
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
std::ostream& operator<<(std::ostream& os,const cavalry& cav){
    os << "Health: " << cav.health << "; Damage: " << cav.dmg << "; Defence: " << cav.defence << "; Range: " << cav.range <<"; Movement Points: "
       << cav.movement_pts <<"; X Location: "<<cav.x<<"; Y Location: "<<cav.y<< "; Charge bonus: " << cav.charge_bonus;
    return os;
}
void player::init(int inf_nr,int arch_nr,int cav_nr){
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
std::ostream& operator<<(std::ostream& os,const player& ply){
    for (auto itr: ply.infv) {//iteratori
        os << itr <<"\n";
    }
    for (auto itr: ply.archv) {//iteratori
        os << itr <<"\n";
    }
    for (auto itr: ply.cavv) {//iteratori
        os << itr <<"\n";
    }
    return os;
}
std::ostream& operator<<(std::ostream& os,const game& gme){
    os <<"   [PLAYER 1]\n"<< gme.p1 <<"   [PLAYER 2]\n"<< gme.p2;
    return os;
}

void game::config(){
    int inf_nr,arch_nr,cav_nr;
    std::cout<<"   [FOR PLAYER 1] \n";
    std::cout<<"The number of infantry units will be:";
    std::cin>>inf_nr;
    std::cout<<"The number of archers units will be:";
    std::cin>>arch_nr;
    std::cout<<"The number of cavalry units will be:";
    std::cin>>cav_nr;
    p1.init(inf_nr,arch_nr,cav_nr);
    std::cout<<"\n   [FOR PLAYER 2] \n";
    std::cout<<"The number of infantry units will be:";
    std::cin>>inf_nr;
    std::cout<<"The number of archers units will be:";
    std::cin>>arch_nr;
    std::cout<<"The number of cavalry units will be:";
    std::cin>>cav_nr;
    p2.init(inf_nr,arch_nr,cav_nr);
}
void game::start_game(const game& gme) {
    config();
    std::cout<<"\n/| EACH PLAYER'S ARMY /|\n";
    std::cout<<gme;
}
