/*Shannon Keola
CS300 - Team C
January 22, 2018*/

#include <iostream>
#include <fstream>

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

struct Player{
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
	Map(int size,Player* p);
	~Map();

	//Draws the map to the screen
	void display();
	void update();

private:
	Tile** map;		//2d array of Tile objects
	Player* p1;		//Pointer to the Player
	int dimensions; //Max dimensions of the map

	//Generates map of size s
	Tile** generateMap();
};
