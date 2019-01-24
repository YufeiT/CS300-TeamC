#include "Map.h"

Map::Map(){
	dimensions = 50;
	map = generateMap();
	p1 = new Player();
	p1->x = 0;
	p1->y = 0;
}

Map::Map(int size,Player* p){
	dimensions = size;
	map = generateMap();
	p1 = p;
}

Map::~Map(){
	delete p1;
	for(int i=0;i<dimensions;++i){
		delete map[i];
	}
	delete map;
}

void Map::display(){
	for(int i=0;i<dimensions;++i){
		for(int j=0;j<dimensions;++j){
			if(p1->x == i && p1->y == j) //If this Tile is the player
				std::cout<<'O';
			else{
				if(map[i][j].beenSeen)
					std::cout<<map[i][j].type;
				else
					std::cout<<'X';
			}
		}
		std::cout<<'\n';
	}
}

Tile** Map::generateMap(){
	//Create the 2D array
	Tile** newMap = new Tile*[dimensions];
	for(int i=0;i<dimensions;++i){
		newMap[i] = new Tile[dimensions];
	}
	//Test population from file (size 50)
	std::ifstream inFile;
	inFile.open("Map.dat");
	for(int j=0;j<dimensions;++j){
		for(int k=0;k<dimensions;++k){
			newMap[j][k].type = inFile.get();
			newMap[j][k].beenSeen = false;
		}
		inFile.ignore(1);
	}
	inFile.close();
	return newMap;
}
