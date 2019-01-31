#include "Inventory.h"

class Player{
public:
	Player();

	void buy_items();

private: 
	Inventory* bag;
	int energy;
	int money;
	bool hasBinoculars;
	bool hasBoat;
}
