/*Shannon Keola
CS300 - Team C
January 22, 2018*/

struct Tile{
	/*Char defines the type of Tile
	M = Mountain
	W = Water
	T = Tree
	etc*/
	char type;
	/*Maybe have an Obstruction object
	Can check if there is an obstruction or not if null
	Can use this object to define what tools work on it
	Obstruction* obs;*/
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

	//Draws the map to the screen
	void display();

private:
	Tile** map;		//2d array of Tile objects
	Player* p1;		//Pointer to the Player
};
