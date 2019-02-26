#include "Map.h"

Map::Map(){
    dimensions = 20;
    map = generateMap();
    ploc.x = dimensions/2;
    ploc.y = dimensions/2;
}

Map::Map(int size){
    dimensions = size;
    map = generateMap();
    ploc.x = rand()%dimensions;
    ploc.y = rand()%dimensions;

    jewel.x = rand()%dimensions;
    jewel.y = rand()%dimensions;
}

Map::~Map(){
    //	delete p;
    for(int i=0;i<dimensions;++i){
        delete map[i];
    }
    delete map;
}


void Map::display(){
    for(int i=0;i<dimensions;++i)
    {
        for(int j=0;j<dimensions;++j)
        {
            if(ploc.y == i && ploc.x == j) //If this Tile is the player
                std::cout << cyan << "O " << reset;
            // FOR TESTING JEWEL
            else if(jewel.y == i && jewel.x == j) //If this Tile is the jewel
                std::cout << magenta << "J " << reset;
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

void Map::reveal_map(){
    for(int i = 0; i < dimensions; ++i)
        for(int j = 0; j < dimensions; ++j){
            map[i][j].beenSeen = true;
        }

    ploc.x = jewel.x;
    ploc.y = jewel.y;

    display();
    std::cout <<'\n';
}

void Map::update()
{
    for(int i=ploc.y-1;i<=ploc.y+1;++i)
    {
        for(int j=ploc.x-1;j<=ploc.x+1;++j)
        {
            if(i>=0 && j>=0 && j<dimensions && i<dimensions)
                map[i][j].beenSeen = true;
        }
    }
    // display();
}

bool Map::gotJewel()
{
    if(ploc.x == jewel.x && ploc.y == jewel.y)
        return true;
    else
        return false;
}

bool Map::checkInput(char cmd){
    int position = 100;

    //check if the cmd are in the moves array
    for(int i = 0; i < strlen(moves); ++i){
        if(cmd == moves[i])
            position = i;
    }   
    //if not return false, we can loop it in main.cpp
    if(position > strlen(moves)-1){
        std::cout << "Invalid move! Please re-enter: ";
        return false;
    }   

    return true;

}

//check if the target position has normal tile or obstacles
//if it's an obstacle, then it will call the check_move
//function to see if the player can go the target place
/*void Map::check_obst(char cmd){
    if(tolower(cmd) == 's' && ploc.y + 1 != 'P')
        check_move(map[ploc.x][ploc.y + 1]);
    else if(tolower(cmd) == 'w' && ploc.y - 1 != 'P')
        check_move(map[ploc.x][ploc.y - 1]);
    else if(tolower(cmd) == 'a' && ploc.x - 1 != 'P')
        check_move(map[ploc.x - 1][ploc.y]);
    else if(tolower(cmd) == 'd' && ploc.x + 1 != 'P')
        check_move(map[ploc.x + 1][ploc.y]);
    else validMove(cmd);

}

bool Map::check_move(Tile** map){

}
*/

//display clues when player at certain coordinates
void Map::clues(){
    if(ploc.x == 0 && ploc.y == 0){
        std::cout << " ----------------------------" << std::endl;
        std::cout << "|****************************|" << std::endl;
        std::cout << "|    You found a clue!       |" << std::endl;
        std::cout << "|   The jewel is at (14, 7). |" << std::endl;
        std::cout << " ----------------------------" << std::endl;
    }
    if(ploc.x == 16 && ploc.y == 10){
        std::cout << " ----------------------------" << std::endl;
        std::cout << "|****************************|" << std::endl;
        std::cout << "|    You found a clue!       |" << std::endl;
        std::cout << "|   The jewel is at (4, 13). |" << std::endl;
        std::cout << " ----------------------------" << std::endl;
    }
    if(ploc.x * 3 == jewel.x && ploc.y * 3 == jewel.y){
        std::cout << " ----------------------------" << std::endl;
        std::cout << "|****************************|" << std::endl;
        std::cout << "|    You found a clue!       |" << std::endl;
        std::cout << "|   The jewel is at (" << jewel.x << ", " << jewel.y << "). |" << std::endl;
        std::cout << " ----------------------------" << std::endl;
    }
    if(ploc.x / 3 == jewel.x && ploc.y / 3 == jewel.y){
        std::cout << " ----------------------------" << std::endl;
        std::cout << "|****************************|" << std::endl;
        std::cout << "|    You found a clue!       |" << std::endl;
        std::cout << "|   The jewel is at (" << jewel.x << ", " << jewel.y << "). |" << std::endl;
        std::cout << " ----------------------------" << std::endl;
    }
}


// CHECKS BOUNDS OF MAP AND UPDATES PLAYER
// Return table key
// 0: successful move
// -1: Northern bound breached
// -2: Western bound breached
// -3: Southern bound breached
// -4: Eastern bound breached
// -5: Invalid Command, not w,a,s,d
// -6: Player energy is less than or equal to zero 
int Map::validMove(char cmd)
{
    int result = 0;
    switch(cmd)
    {
        // Check if player is at edge of map
        // else update their position
        case's':
        case'S':
            if(ploc.y == dimensions-1)
            {
                result = -1;
                break;
            }
            else
            {
                ploc.y += 1;
                break;
            }
        case'a':
        case'A':
            if(ploc.x == 0)
            {
                result = -2;
                break;
            }
            else
            {
                ploc.x -= 1;
                break;
            }
        case'w':
        case'W':
            if(ploc.y == 0)
            {
                result = -3;
                break;
            }
            else
            {
                ploc.y -= 1;
                break;
            }
        case'd':
        case'D':
            if(ploc.x == dimensions-1)
            {
                result = -4;
                break;
            }
            else
            {
                ploc.x += 1;
                break;
            }
            // Invalid command 
        default:
            result = -5; 
    }
    return result;
}

int Map::passTile()
{ 
    char type = map[ploc.x][ploc.y].type;  
    /// ****************** CHECK FOR INVALID TYPE TILES ******
    //  if(type != 'T')...

    return type;
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
