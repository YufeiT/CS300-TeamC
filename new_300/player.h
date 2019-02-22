// ************ Player HEADER FILE *****************    

// Jordan L Co 
// Frupal 
// CS300
// Jan 28, 2018

#include <iostream>
#include<stdlib.h>
#include<cstring>

//Colors
const std::string red("\033[0;31m");
const std::string green("\033[1;32m");
const std::string yellow("\033[1;33m");
const std::string cyan("\033[0;36m");
const std::string magenta("\033[0;35m");
const std::string reset("\033[0m");

enum item{BOAT,WEED,CHAINSAW,JACK,EBAR,BINOS};
/*
struct inventory
{
  inventory();
  bool boat;
  bool weedwacker;
  bool chainsaw;
  bool jackhammer;
  bool ebar;
  bool binos;
  bool empty;
};
*/
class player 
{
  public:
    player();
    player(int m, int e);
    ~player();
    void set_price();
    // Takes obstacles/terrrain arg, checks player's items then subtracts energy
    int movement(char type);
    int getEnergy()const;
    int getMoney()const;
   // bool hasBinos(); ?
    void add_item(int item, int price);
    void display_inv();

    bool hasItem(char playerTile);
    
  private:
    int energy;
    int money;
    bool inventory[6];
};

class shop
{
  public:
    shop();
    ~shop();
    void set_price();
    void display()const;
    int purchase(player*);
  private:
    /*
     1. Boat 
     2. Weedwacker
     3. Chainsaw  
     4. Jackhammer 
     5. Energy Bar  
     6. Binoculars
    */
    int price[6]; 
    
};
