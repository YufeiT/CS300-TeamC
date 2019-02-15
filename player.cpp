// ************ Player definitions *****************    

// Jordan L Co 
// Frupal 
// CS300
// Jan 28, 2018

#include"player.h"

using namespace std;

player::player()
{
  energy = 0;
  money = 0;

  inv.boat = false;
  inv.weedwacker = false;
  inv.chainsaw = false;
  inv.jackhammer = false;
  inv.ebar = false;
  inv.binos = false;
  inv.empty = true;
}

player::player(int m, int e)
{
  energy = e;
  money = m;

  inv.boat = false;
  inv.weedwacker = false;
  inv.chainsaw = false;
  inv.jackhammer = false;
  inv.ebar = false;
  inv.binos = false;
  inv.empty = true;
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

int player::buy_item(int item)
{
  /*
  USE ENUMERATED TYPES??
  " 1. Boat                  $20\n";
  " 2. Weedwacker            $10\n";
  " 3. Chainsaw              $10\n";;
  " 4. Jackhammer            $10\n";
  " 5. Energy Bar            $5\n";
  " 6. Binoculars            $5\n\n";
  */

  int money_start = money;

  switch(item)
  {
    case 1: 
      if(20 <= money)
      {
        money -= 20; 
        inv.boat = true;
      }
      break;
    case 2:
    case 3:
    case 4:
      if(10 <= money){
        money -= 10; 
        if(item == 2)
          inv.weedwacker = true;
        if(item == 3)
          inv.chainsaw = true;
        if(item == 4)
          inv.jackhammer = true;
      }
      break;
    case 5:
    case 6:
      if(5<= money){
        money -= 5; 
        if(item == 5)
          inv.ebar = true;
        if(item == 6)
          inv.binos = true;
      }
      break;
  }
  // We didn't buy anything
  if(money_start == money)
    return -1;
  else
  {
    inv.empty = false;
    return 0;
  }
}

void player::display_inv()
{ 
  cout << magenta << "______________\n";
  cout << "|  INVENTORY  |\n";
  if(!inv.empty){ 
    if(inv.boat)
      cout << "| -Boat       |\n";

    if(inv.weedwacker)
      cout << "| -Weedwacker |\n";

    if(inv.chainsaw)
      cout << "| -Chainsaw   |\n";

    if(inv.jackhammer)
      cout << "| -Jackhammer |\n";

    if(inv.ebar)
      cout << "| -Energy Bar |\n";

    if(inv.binos)
      cout << "| -Binoculars |\n";
  }
  else
    cout << "|  NO ITEMS   |\n";
  
  cout << "|_____________|\n" << reset;
 }

int player::getEnergy()const
{
  return energy;
}

int player::getMoney()const
{
  return money;
}
