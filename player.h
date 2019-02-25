// ************ Player HEADER FILE *****************    

// Jordan L Co 
// Frupal 
// CS300
// Jan 28, 2018

#include <iostream>
#include<stdlib.h>

//Colors
const std::string red("\033[0;31m");
const std::string green("\033[1;32m");
const std::string yellow("\033[1;33m");
const std::string cyan("\033[0;36m");
const std::string magenta("\033[0;35m");
const std::string reset("\033[0m");

struct inventory
{
    bool boat;
    bool weedwacker;
    bool chainsaw;
    bool jackhammer;
    bool ebar;
    bool binos;
    bool empty;
};

class player 
{
    public:
        player();
        player(int m, int e);
        ~player();
        // Takes obstacles/terrrain arg, checks player's items then subtracts energy
        int movement(char type);
        int getEnergy()const;
        int getMoney()const;
        // bool hasBinos(); ?
        int buy_item(int item);
        void display_inv();

    protected:
        int energy;
        int money;
        inventory inv;
};
