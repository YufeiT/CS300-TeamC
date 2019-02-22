// ************ Player definitions *****************    

// Jordan L Co 
// Frupal 
// CS300
// Jan 28, 2018

#include"player.h"

using namespace std;

const char item_names[6][15]= {
"Boat",
"Weedwacker",
"Chainsaw",
"Jackhammer",
"Energy Bar",
"Binoculars",
};

player::player()
{
  energy = 20;
  money = 50;

  for(int i=BOAT; i<=BINOS; ++i)
  {
    inventory[i] = false;
  }
}

player::player(int m, int e)
{
  energy = e;
  money = m;

  for(int i=BOAT; i<=BINOS; ++i)
  {
    inventory[i] = false;
  }
}

player::~player()
{}

int player::movement(char type)
{
  if(energy <= 0)
    return -1;
  else
  {
    --energy;
  }

  return 0;
}

void player::add_item(int item, int price)
{

  inventory[item] = true;
  money -= price;
}

void player::display_inv()
{ 
  bool empty = true;
  int i = 0;
  cout << magenta << "______________\n";
  cout << "|  INVENTORY  |\n";

  for(i=BOAT; i<=BINOS; ++i)
  {
    if(inventory[i])
    {
      cout << "| -" << item_names[i] << " |\n";
      empty = false;
    }
  }
  if(empty)
    cout << "|  NO ITEMS   |\n";
  
  cout << "|_____________|\n" << reset;
}

bool player::hasItem(char playerTile)
{
    if(playerTile == 'W' && inventory[0] == true)
        return true;
    if(playerTile == 'T' && inventory[2] == true)
        return true;
    if(playerTile == 'M' && inventory[1] == true)
        return true;
    return false;
}

int player::getEnergy()const
{
  return energy;
}

int player::getMoney()const
{
  return money;
}
