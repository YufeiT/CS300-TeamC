#include "Map.h"

Map::Map(){
dimensions = 20;
map = generateMap();
p = new player();
ploc.x = dimensions/2;
ploc.y = dimensions/2;
}

Map::Map(int size,player* p){
	dimensions = size;
	map = generateMap();
	ploc.x = rand()%dimensions;
	ploc.y = rand()%dimensions;
}

Map::~Map(){
//	delete p;
	for(int i=0;i<dimensions;++i){
		delete map[i];
	}
	delete map;
}

void Map::display(){
	for(int i=0;i<dimensions;++i){
		for(int j=0;j<dimensions;++j){
			if(ploc.x == i && ploc.y == j) //If this Tile is the player
				std::cout << cyan << "O " << reset;
			else{
				if(map[i][j].beenSeen)
					std::cout<<map[i][j].type<<' ';
				else
					std::cout<<"X ";
			}
		}
		std::cout<<'\n';
	}
}

void Map::update(){
	for(int i=ploc.x-1;i<=ploc.x+1;++i){
		for(int j=ploc.y-1;j<=ploc.y+1;++j){
			if(i>=0 && j>=0 && j<dimensions && i<dimensions)
				map[i][j].beenSeen = true;
		}
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
