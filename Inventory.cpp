#include "Inventory.h"

Inventory::Inventory(){
	head = NULL:
}

Inventory::~Inventory(){
	remove_all(head);
}

bool Inventory::add_item(char* name,int count){
	add_item(name,count,head);	
}

//Adds count Item(s) to the Inventory
bool Inventory::add_item(char* name,int count,Item* head){
	//Inventory was empty
	if(!head){
		head = new Item;
		head->name = new char[strlen(name)];
		head->count = count;
		head->next = NULL;
		return true;
	}
	//The name matches, so we already have one in our inventory
	if(strcmp(head->name,name)==0){
		head->count += count;
		return true;
	}
	//Go next if there is one
	if(head->next){
		return add_item(name,count,head->next);
	}
	//The new Item is added to the end of the LL
	else{
		head->next = new Item;
		head->name = new char[strlen(name)];
		head->count = count;
		head->next->next = NULL;
	}
}

void Inventory::display(){
	std::cout<<"Current Inventory:\n";
	display(head);
}

void Inventory::display(Item* head){
	if(head){
		std::cout<<head->name<<": "<<head->count<<'\n';
		display(head->next);
	}
}

//Destructor helper
void Inventory::remove_all(Item* head){
	if(head){
		remove_all(head->next);
	}
	delete head;
}
