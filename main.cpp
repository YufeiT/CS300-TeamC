// ************ MAIN HEADER FILE *****************    

// Jordan L Co 
// Frupal 
// CS300
// Jan 28, 2018

#include "Map.h"

using namespace std;

int main()
{
  srand(time(NULL));
  player myHero;
  Map gameMap(20,&myHero);

  
  do{   
    gameMap.display();
    cout << red << "\n Enter direction: W,A,S,D \n" 
  }
  while( 



  
  return 0;

}

