// ************ Player definitions *****************    

// Jordan L Co 
// Frupal 
// CS300
// Jan 28, 2018

#include"player.h"

player::player()
{
  energy = 0;
  money = 0;
}

player::~player()
{}

int player::movement(/*add obstacle and terrain args*/)
{
  if(energy <= 0)
    return -1;
  else
    // add large table dependent on obstacle/terrain
    --energy;

  return 0;
}

void player::test()
{
  std::cout << "FUCK\n";
}
