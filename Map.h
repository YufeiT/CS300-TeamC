/*Shannon Keola
CS300 - Team C
January 22, 2018*/

#include <iostream>
#include <fstream>
#include<stdlib.h>
#include<time.h>
#include"player.h"



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
	Map(int size);
	~Map();

	//Draws the map to the screen
	void display();
	void update();
  int validMove(char cmd);
  int passTile();
  bool gotJewel();

private:
	Tile** map;		//2d array of Tile objects
  position ploc; // Hero's location
  position jewel; // Jewel location
  
	int dimensions; //Max dimensions of the map

	//Generates map of size s
	Tile** generateMap();
};
