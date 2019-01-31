/*Frupal Game Team C
January 22, 2018*/

//Includes
#include <fstream>
#include <iostream>
#include "Map.h"

//Function Declarations
void print_intro();
void print_controls();
void clear_screen();

int main(){
	//Initialize variables
	Map* theMap = new Map();
	Settings* theSettings = new Settings("settings.txt");
	char userResp;

	//Print initial stuff
	print_intro();

	do{
		std::cout<<"(P)lay or edit (s)ettings?\n>";
		std::cin>>userResp;
		std::cin.ignore();
		if(userResp == 's' || userResp == 'S'){
			theSettings->edit();
		}
	}while(userResp != 'p' || userResp != 'P');

	print_controls();

	//Main program loop
	do{
		//Update and display the Map
		clear_screen();
		theMap->update();
		print_controls();
		theMap->display();

		//Get user choice
		std::cout<<">";
		std::cin>>userResp;
		std::cin.ignore();
		switch(userResp){
			case 'w': 	theMap->move_north();
						break;
			case 'a':	theMap->move_west();
						break;
			case 's':	theMap->move_south();
						break;
			case 'd':	theMap->move_east();
						break;
			case 'q':	break;
			case 'e':	//Shop stuff here
						break;
		}
	}while(userResp != 'q');
}

void print_intro(){
	std::cout<<"Welcome to the game of Frupal!\n";
	std::cout<<"Blah blah blah...description\n";
}

void print_controls(){
	std::cout<<"Use w,a,s,d to move\n";
	std::cout<<"Use e to open the shop\n";
	std::cout<<"Use k to reprint the commands\n";
	std::cout<<"Use q to quit\n";
}

void clear_screen(){
	for(int i=0;i<5;++i){
		std::cout<<"\n\n\n\n\n";
	}
}
