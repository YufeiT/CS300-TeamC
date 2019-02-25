// ************ MAIN HEADER FILE *****************    

// Jordan L Co 
// Frupal 
// CS300
// Jan 28, 2018

#include "Map.h"
#include<cctype>

using namespace std;

void clear();
void shopdisplay();
int bought();

//bool commandCheck(char userCommand);

int main()
{
    srand(time(NULL));
    player myHero(15, 30);
    Map gameMap(20);

    char userCommand = ' ';
    char playerTile = 'P';
    bool noEnergy = false;
    bool jewel = false;
    int moveCode = 0;
    int selected = 0;;
    bool check_input = false;



    do{   
        clear();
        gameMap.clues();
        gameMap.display();
        myHero.display_inv(); 
        cout << yellow << "|ENERGY: " << myHero.getEnergy() << "| " << reset;
        cout << green  << "|MONEY: " << "$" << myHero.getMoney() << "|" << reset << endl;
        cout << cyan << "\n To enter the shop (i)\n" << reset;
        cout << red << " To move enter direction (w,a,s,d)\n\n" << reset;

        // Add try catch block for user input 
        cout << "User command: ";
        cin >> userCommand; 
        cin.ignore(100,'\n');

        //input error checking
        check_input = gameMap.checkInput(userCommand);
        while(check_input == false){
            cin >> userCommand; 
            cin.clear();
            cin.ignore(100,'\n');
            check_input = gameMap.checkInput(userCommand);
        }


        if(userCommand == 'i')
        {
            shopdisplay(); 
            selected = bought();
            if(myHero.buy_item(selected) < 0)
                cout << green <<"INSUFFICIENT FUNDS or INVALID NUMBER INPUT\n\n" << reset;


            cout << "item: " << selected << endl;

        }
        //Cheat to end the game, it'll reveal the whole map and display the
        //winning message and terminate the game
        else if(userCommand == 'P'){
            jewel = true;
            cout << string(100, '\n');
            gameMap.reveal_map();
            cout << magenta << "~~~~~ YOU WIN ~~~~~" << reset << endl;
        }

        else
        {
            //instead of letting player directly move to the target position,
            //the programm will pass the command to the check obstacle function;
            //let it decide if player can move to that position.
            //gameMap.check_obst(userCommand);
            moveCode = gameMap.validMove(userCommand);
            playerTile = gameMap.passTile();
            myHero.movement(playerTile);  
            // Move Code legend: 
            // 0: successful move
            // -1: Northern bound breached
            // -2: Western bound breached
            // -3: Southern bound breached
            // -4: Eastern bound breached
            // -5: Invalid Command, not w,a,s,d
            // -6: Player energy is less than or equal to zero 
            cout << "moveCode: " << moveCode << endl;
        }

        if(myHero.getEnergy() <= 0)
        {
            noEnergy = true;
            cout << yellow << "|ENERGY: " << myHero.getEnergy() << "| " << reset;
            cout << green  << "|MONEY: " << "$" << myHero.getMoney() << "|" << reset << "\n\n\n\n";
            cout << red << "~~~~~GAME OVER~~~~~" << reset << endl;
        }
        else if(gameMap.gotJewel())
        {
            jewel = true;
            cout << magenta << "~~~~~ YOU WIN ~~~~~" << reset << endl;
        }

        gameMap.update();
    }while(!noEnergy && !jewel);

    return 0;

}

void clear()
{
    for(int i=0; i<50; ++i)
    {
        cout << endl;
    }
}

void shopdisplay()
{
    cout << "***********************************************" << endl;
    cout << "*************** " << cyan << "SHOP " << reset << "***************";
    cout << "\n Please enter the number of the item you wish to purchase \n";
    cout << " 1. Boat                  $20\n";
    cout << " 2. Weedwacker            $10\n";
    cout << " 3. Chainsaw              $10\n";;
    cout << " 4. Jackhammer            $10\n";
    cout << " 5. Energy Bar            $5\n";
    cout << " 6. Binoculars            $5\n\n";
}

int bought()
{
    int item;
    cout << "Item #: ";
    cin >> item; cin.ignore(100,'\n');
    if(item < 1 || item > 6)
        return -1;
    return item;
}
