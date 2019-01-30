#include "Map.h"

Map::Map(){
	dimensions = 20;
	map = generateMap();
	playerLoc[0] = 0;	//Player starts at 0,0
	playerLoc[1] = 0;
}

Map::Map(int size){
	dimensions = size;
	map = generateMap();
	playerLoc[0] = 0;	//Player starts at 0,0
	playerLoc[1] = 0;
}

Map::~Map(){
	for(int i=0;i<dimensions;++i){
		delete map[i];
	}
	delete map;
}

//MOVEMENT
bool Map::move_north(){
	if(playerLoc[0]>0){
		--playerLoc[0];
		return true;
	}
	else return false;
}

bool Map::move_west(){
	if(playerLoc[1]>0){
		--playerLoc[1];
		return true;
	}
	else return false;
}

bool Map::move_east(){
	if(playerLoc[1]<dimensions-2){
		++playerLoc[1];
		return true;
	}
	else return false;
}

bool Map::move_south(){
	if(playerLoc[0]<dimensions-2){
		++playerLoc[0];
		return true;
	}
	else return false;
}

void Map::display(){
	for(int i=0;i<dimensions;++i){
		for(int j=0;j<dimensions;++j){
			if(playerLoc[0]==i && playerLoc[1]==j) //If this Tile is the player
				std::cout<<"O ";
			else{
				if(map[i][j].beenSeen)
					std::cout<<map[i][j].type<<' ';
				else
					std::cout<<"X ";
			}
		}
		std::cout<<" "<<i;
		std::cout<<'\n';
	}
}

void Map::update(){
	for(int i=playerLoc[0]-1;i<=playerLoc[0]+1;++i){
		for(int j=playerLoc[1]-1;j<=playerLoc[1]+1;++j){
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
			newMap[j][k].obstacle = NULL;
		}
		inFile.ignore(1);
	}
	inFile.close();
	return newMap;
}
