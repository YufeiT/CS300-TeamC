#include "Map.h"

Map::Map(){
dimensions = 20;
map = generateMap();
ploc.x = dimensions/2;
ploc.y = dimensions/2;
}

Map::Map(int size){
	dimensions = size;
	map = generateMap();
	ploc.x = rand()%dimensions;
	ploc.y = rand()%dimensions;

	jewel.x = rand()%dimensions;
	jewel.y = rand()%dimensions;

}

Map::~Map(){
//	delete p;
	for(int i=0;i<dimensions;++i){
		delete map[i];
	}
	delete map;
}

void Map::display(){
	for(int i=0;i<dimensions;++i)
  {
		for(int j=0;j<dimensions;++j)
    {
			if(ploc.y == i && ploc.x == j) //If this Tile is the player
				std::cout << cyan << "O " << reset;
      // FOR TESTING JEWEL
			else if(jewel.y == i && jewel.x == j) //If this Tile is the jewel
				std::cout << magenta << "J " << reset;
			else{
				if(map[i][j].beenSeen)
					std::cout<<map[i][j].type<<' ';
				else
					std::cout<<"X ";
			}
		}
		std::cout<<'\n';
	}
}

void Map::update(const bool binos)
{
  int view = 1; 
  if(binos)
    view = 2;

	for(int i=ploc.y-view;i<=ploc.y+view;++i)
  {
		for(int j=ploc.x-view;j<=ploc.x+view;++j)
    {
			if(i>=0 && j>=0 && j<dimensions && i<dimensions)
				map[i][j].beenSeen = true;
		}
	}
}

bool Map::gotJewel()
{
  if(ploc.x == jewel.x && ploc.y == jewel.y)
    return true;
  else
    return false;
}

// CHECKS BOUNDS OF MAP AND UPDATES PLAYER
// Return table key
// 0: successful move
// -1: Northern bound breached
// -2: Western bound breached
// -3: Southern bound breached
// -4: Eastern bound breached
// -5: Invalid Command, not w,a,s,d
// -6: Player energy is less than or equal to zero 
int Map::validMove(char cmd)
{
  int result = 0;
  switch(cmd)
  {
    // Check if player is at edge of map
    // else update their position
    case's':
    case'S':
      if(ploc.y == dimensions-1)
      {
        result = -1;
        break;
      }
      else
      {
        ploc.y += 1;
        break;
      }
    case'a':
    case'A':
      if(ploc.x == 0)
      {
        result = -2;
        break;
      }
      else
      {
        ploc.x -= 1;
        break;
      }
    case'w':
    case'W':
      if(ploc.y == 0)
      {
        result = -3;
        break;
      }
      else
      {
        ploc.y -= 1;
        break;
      }
    case'd':
    case'D':
      if(ploc.x == dimensions-1)
      {
        result = -4;
        break;
      }
      else
      {
        ploc.x += 1;
        break;
      }
    // Invalid command 
    default:
        result = -5; 
  }
  return result;
}

int Map::passTile()
{ 
  char type = map[ploc.x][ploc.y].type;  
  /// ****************** CHECK FOR INVALID TYPE TILES ******
  //  if(type != 'T')...

  return type;
}

Tile** Map::generateMap(){
	//Create the 2D array
	Tile** newMap = new Tile*[dimensions];
	for(int i=0;i<dimensions;++i){
		newMap[i] = new Tile[dimensions];
	}
	//Test population from file (size 50)
	std::ifstream inFile;
	inFile.open("Map.dat");
	for(int j=0;j<dimensions;++j){
		for(int k=0;k<dimensions;++k){
			newMap[j][k].type = inFile.get();
			newMap[j][k].beenSeen = false;
		}
		inFile.ignore(1);
	}
	inFile.close();
	return newMap;
}
