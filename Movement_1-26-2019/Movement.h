#include <iostream>

class Movement{
    public:
        Movement(); //initializes vars to 0;
        Movement(int column, int row); //TODO: main needs to get map size and initialize Movement object with this constructor

        //Checks if the move is valid. If so, returns that coordinate. Else return 0
        //TODO:I think the Player class should wrap these function calls in a do-while(0) loop.
        //      Doing this would not allow the player to continue until a valid input is provided.
        int north(int y);
        int south(int y);
        int east(int x);
        int west(int x);
        
        //Checks if the incremented/decremented coordinate is in bounds and returns t/f
        bool checkXBounds(int location);
        bool checkYBounds(int location);

    protected:
        //TODO:This could just be an array size 2. [0] = x [1] = y
        int mapColumnSize; //Max y coordinate of the map
        int mapRowSize; //Max x coordinate of the map
};
