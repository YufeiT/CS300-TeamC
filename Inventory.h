#include <iostream>

struct Item{
	char* name;
	int count;
	Item* next;
}

class Inventory{
public:
	Inventory();
	~Inventory();

	//Adds item with name and count to the Inventory
	bool add_item(char* name,int count);

	//Mostly for testing
	void display();

private:
	Item* head;

	//Helpers
	bool add_item(char* name,int count,Item* head);
	void remove_all(Item* head);
}
