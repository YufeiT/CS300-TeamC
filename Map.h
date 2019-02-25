/*Shannon Keola
  CS300 - Team C
  January 22, 2018*/

#include <iostream>
#include <fstream>
#include<stdlib.h>
#include<time.h>
#include"player.h"


static char moves[7] = {'w', 'a', 's', 'd', 'i', 'P', '\0'};

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

class Map:public player{
    public:
        // Constructors
        Map();
        Map(int size);
        ~Map();

        //Draws the map to the screen
        void display();
        void update();
        //reveal map when player enters 'P'
        void reveal_map();
        int validMove(char cmd);
        int passTile();

        //dispplay clues 
        void clues();

        //check if user wants to use binocular and
        //maybe use them.
        bool hasBinos(int, int);
        
        //check if there's an obstacle on tagest
        //place before updating player position
        void check_obst(char cmd);
        bool gotJewel();
        bool checkInput(char cmd);
        bool check_move(Tile**  map);

    private:
        Tile** map;		//2d array of Tile objects
        position ploc; // Hero's location
        position jewel; // Jewel location

        int dimensions; //Max dimensions of the map

        //Generates map of size s
        Tile** generateMap();
};
