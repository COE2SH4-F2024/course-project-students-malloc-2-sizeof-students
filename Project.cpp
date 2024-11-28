#include <iostream>
#include "MacUILib.h"
#include "objPos.h"
#include "Player.h"

using namespace std;

#define DELAY_CONST 100000

GameMechs *mainGameMechsRef;
Player *myPlayer;

void Initialize(void);
void GetInput(void);
void RunLogic(void);
void DrawScreen(void);
void LoopDelay(void);
void CleanUp(void);



int main(void)
{

    Initialize();

    while(mainGameMechsRef->getExitFlagStatus() == false)  
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

    mainGameMechsRef = new GameMechs();
    myPlayer = new Player(mainGameMechsRef);
}

void GetInput(void)
{
    if(MacUILib_hasChar())
    {
        mainGameMechsRef->setInput(MacUILib_getChar());
    }
    
}

void RunLogic(void)
{
    if(mainGameMechsRef->getInput() == ' ')
    {
        mainGameMechsRef->setExitTrue();
    }
    myPlayer->updatePlayerDir();
    myPlayer->movePlayer();
    mainGameMechsRef->clearInput();
}

void DrawScreen(void)
{
    MacUILib_clearScreen();
    
    // objPos gameboard;
    objPos player_pos = myPlayer->getPlayerPos();
    
    int i,j;
    for(i = 0; i < mainGameMechsRef->getBoardSizeY(); i++)
    {
        for(j = 0; j < mainGameMechsRef->getBoardSizeX(); j++)
        {
            if(i == 0 || i == 14 || j == 0 || j == 29)
            {
                // gameboard.symbol = '#';
                // gameboard.pos->x = j;
                // gameboard.pos->y = i;
                MacUILib_printf("#");
            }
            else if(player_pos.pos->x == j && player_pos.pos->y == i)
            {
                MacUILib_printf("%c", player_pos.symbol);
            }
            else
            {
                // gameboard.symbol = ' ';
                // gameboard.pos->x = j;
                // gameboard.pos->y = i;
                MacUILib_printf(" ");
            }
        }

        MacUILib_printf("\n");
    }  

    MacUILib_printf("Player[x,y] = [%d, %d], %c", player_pos.pos->x, player_pos.pos->y, player_pos.symbol);
}

void LoopDelay(void)
{
    MacUILib_Delay(DELAY_CONST); // 0.1s delay
}


void CleanUp(void)
{
    MacUILib_clearScreen();  

    delete myPlayer;
    
    if(mainGameMechsRef->getLoseFlagStatus())
    {
        MacUILib_printf("You lost the game.\n");
    }
    else
    {
        MacUILib_printf("You won!\n");
    }

    MacUILib_printf("Score: %d", mainGameMechsRef->getScore());

    delete mainGameMechsRef;

    MacUILib_uninit();
}
