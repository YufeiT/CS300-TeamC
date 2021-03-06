/*Shannon Keola
CS300 - Team C
January 22, 2018*/

#include <iostream>
#include <fstream>

struct Obstruction{
	char* type;		//eg Boulder, Log, etc
	char* tool;		//The tool to remove it
};

struct Tile{
	/*Char defines the type of Tile
	M = Mountain
	W = Water
	T = Tree
	etc*/
	char type;
	bool beenSeen;
	Obstruction* obstacle;
};

class Map{
public:
	// Constructors
	Map();
	Map(int size);
	~Map();

	//Player movement
	bool move_north();
	bool move_west();
	bool move_east();
	bool move_south();

	//Draws the Map and Player to the screen
	void display();

	//Flips Tiles' beenSeen to true if adjacent to Player
	void update();

private:
	Tile** map;		//2d array of Tile objects
	int playerLoc[2];	//Location of the Player
	int dimensions; //Max dimensions of the map

	//Generates map of size sxs
	Tile** generateMap();
};
