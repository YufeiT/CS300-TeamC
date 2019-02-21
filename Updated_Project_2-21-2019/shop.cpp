// ************ shop definitions *****************    
// 
// Jordan L Co 
// shop.cpp
// Frupal 
// CS300
// Jan 28, 2018

#include"player.h"

using namespace std;


const char items[6][15]= {
"Boat",
"Weedwacker",
"Chainsaw",
"Jackhammer",
"Energy Bar",
"Binoculars",
};

shop::shop()
{
  price[BOAT] = 20;
  price[WEED] = 10;
  price[CHAINSAW] = 10;
  price[JACK] = 10;
  price[EBAR] = 5;
  price[BINOS] = 5;
}

shop::~shop()
{
}

void shop::set_price()
{
  int i=0;
  
  for(i=BOAT; i<=BINOS; ++i)
  {
    cout << items[i] << " price: ";
    cin >> price[i]; cin.ignore(100,'\n');
  }
}

void shop::display()const
{ 
  int i=0;

  cout << cyan << "**********************************************************" << reset << endl;
  cout << "************************** " << cyan << "SHOP " << reset << "************************";
  cout << "\n Please enter the number of the item you wish to purchase \n";

  for(i=BOAT; i<=BINOS; ++i)
  {
     cout << i+1 << ". " << items[i];
     if(strlen(items[i]) > 5)
       cout << "\t\t";
     else
       cout << "\t\t\t";
     cout << price[i] << endl;
  }
}

int shop::purchase(player* p)
{
  int money = p->getMoney();
  int item = 0;

  if(money <= 0){
    return -1;
  }

  // Make sure item entered is in bounds
  do{ 
    cout << "Item #: ";
    cin >> item; cin.ignore(100,'\n');
    --item; // Array is zero indexed, menu selection is not
  }while(item < BOAT || item > BINOS);

  if(price[item] > money)
    return -2;
  else
    p->add_item(item, price[item]);

  return 0;
}

