#include <iostream>
#include "MacUILib.h"
#include "objPos.h"

#include "Player.h"
#include "GameMechs.h"
using namespace std;

#define DELAY_CONST 100000

GameMechs *mainGameMechsRef;
Player *myPlayer;

GameMechs *myGM;


void Initialize(void);
void GetInput(void);
void RunLogic(void);
void DrawScreen(void);
void LoopDelay(void);
void CleanUp(void);



int main(void)
{

    Initialize();

    while(myGM ->getExitFlagStatus() == false)  
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

    myPlayer = new Player(myGM);
    myGM = new GameMechs();


}

void GetInput(void)
{
  
}

void RunLogic(void)
{
    myPlayer->updatePlayerDir();
    myPlayer->movePlayer();

    // Exit flag handling
    if (myGM->getInput() == ' ')
    {
        myGM->setExitTrue();
    }

}

void DrawScreen(void)
{
    MacUILib_clearScreen();
    // objPos playerPos = myPlayer->getPlayerPos();
    // MacUILib_printf("Player[x,y] = [%d, %d], %c",
    //                 playerPos.pos->x, playerPos.pos->y,  /// come back to this
    
    objPos gameboard;
    objPos player_pos = myPlayer->getPlayerPos();
    objPos foodPos = myGM->getFoodPos();/// not a member yet..?

    int i,j;
    for(i = 0; i < myGM->getBoardSizeY(); i++)
    {
        for(j = 0; j < myGM->getBoardSizeX(); j++)
        {
            if(i == 0 || i == myGM->getBoardSizeY() - 1 || j == 0 || j == myGM->getBoardSizeX()-1)
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
    delete myGM;

    MacUILib_uninit();
}
