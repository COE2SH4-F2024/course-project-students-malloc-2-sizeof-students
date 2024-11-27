#include <iostream>
#include "MacUILib.h"
#include "objPos.h"
#include "Player.h"

using namespace std;

#define DELAY_CONST 100000

GameMechs *mainGameMechsRef;
Player *myPlayer;

bool exitFlag;

void Initialize(void);
void GetInput(void);
void RunLogic(void);
void DrawScreen(void);
void LoopDelay(void);
void CleanUp(void);



int main(void)
{

    Initialize();

    while(exitFlag == false)  
    {
        GetInput();
        RunLogic();
        DrawScreen();
        LoopDelay();
    }

    CleanUp();

}


void Initialize(void)
{
    MacUILib_init();
    MacUILib_clearScreen();

    myPlayer = new Player(mainGameMechsRef);

    exitFlag = false;
}

void GetInput(void)
{
  
}

void RunLogic(void)
{
    myPlayer->updatePlayerDir();
    myPlayer->movePlayer();
}

void DrawScreen(void)
{
    MacUILib_clearScreen();
    
    objPos gameboard;
    objPos player_pos = myPlayer->getPlayerPos();
    
    int i,j;
    for(i = 0; i < 10; i++)
    {
        for(j = 0; j < 20; j++)
        {
            if(i == 0 || i == 9 || j == 0 || j == 19)
            {
                gameboard.symbol = '#';
                gameboard.pos->x = j;
                gameboard.pos->y = i;
                MacUILib_printf("%c", gameboard.symbol);
            }
            else if(player_pos.pos->x == j && player_pos.pos->y == i)
            {
                MacUILib_printf("%c", player_pos.symbol);
            }
            else
            {
                gameboard.symbol = ' ';
                gameboard.pos->x = j;
                gameboard.pos->y = i;
                MacUILib_printf("%c", gameboard.symbol);
            }
        }

        MacUILib_printf("\n");
    }  


}

void LoopDelay(void)
{
    MacUILib_Delay(DELAY_CONST); // 0.1s delay
}


void CleanUp(void)
{
    MacUILib_clearScreen();  

    delete myPlayer;  

    MacUILib_uninit();
}
