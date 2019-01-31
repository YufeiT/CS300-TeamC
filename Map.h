/*Shannon Keola
CS300 - Team C
January 22, 2018*/

#include <iostream>
#include <fstream>
#include<stdlib.h>
#include<time.h>
#include"player.h"

//Colors
const std::string red("\033[0;31m");
const std::string green("\033[1;32m");
const std::string yellow("\033[1;33m");
const std::string cyan("\033[0;36m");
const std::string magenta("\033[0;35m");
const std::string reset("\033[0m");


struct Tile{
	/*Char defines the type of Tile
	M = Mountain
	W = Water
	T = Tree
	etc*/
	char type;
	bool beenSeen;
	/*Maybe have an Obstruction object
	Can check if there is an obstruction or not if null
	Can use this object to define what tools work on it
	Obstruction* obs;*/
};

struct position{
	int x;
	int y;
};

/*
struct Obstruction{
	char* type;		//eg Boulder, Log, etc
};
*/

class Map{
public:
	// Constructors
	Map();
	Map(int size,player* p);
	~Map();

	//Draws the map to the screen
	void display();
	void update();

private:
	Tile** map;		//2d array of Tile objects
	player *p;		//Pointer to the hero, need to pass player obstacles/terrain
  position ploc; // Hero's location
  
	int dimensions; //Max dimensions of the map

	//Generates map of size s
	Tile** generateMap();
};
