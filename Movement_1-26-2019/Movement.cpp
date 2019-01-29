#include "Movement.h"

Movement::Movement(){
    mapColumnSize = 0;
    mapRowSize = 0;
}

Movement::Movement(int column, int row){
    mapColumnSize = column;
    mapRowSize = row;
}

int Movement::north(int y){
    if(checkYBounds(y++))
        return y++;
    else
        return -1;
}

int Movement::south(int y){
    if(checkYBounds(y--))
        return y--;
    else
        return -1;
}

int Movement::east(int x){
    if(checkXBounds(x++))
        return x++;
    else
        return -1;
}

int Movement::west(int x){
    if(checkXBounds(x--))
        return x--;
    else
        return -1;
}

bool Movement::checkXBounds(int location){
    if((location >= this->mapRowSize) || (location < 0))
        return false;
    else
        return true;
}

bool Movement::checkYBounds(int location){
    if((location >= this->mapColumnSize) || (location < 0))
        return false;
    else
        return true;
}
