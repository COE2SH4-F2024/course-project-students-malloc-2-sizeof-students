#include <iostream>
#include "MacUILib.h"
#include "objPos.h"

#include "Player.h"
#include "GameMechs.h"
#include "Food.h"
#include "time.h"
using namespace std;

#define DELAY_CONST 100000

GameMechs *mainGameMechsRef;
Player *myPlayer;
Food *myFood;

void Initialize(void);
void GetInput(void);
void RunLogic(void);
void DrawScreen(void);
void LoopDelay(void);
void CleanUp(void);



int main(void)
{
    printf("I am before init");
    Initialize();
    printf("I am at init");

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

    srand(time(NULL));
    mainGameMechsRef = new GameMechs();
    myFood = new Food(mainGameMechsRef);
    myPlayer = new Player(mainGameMechsRef, myFood);
    
    myFood->generateFood(myPlayer->getPlayerPos()); 
}

void GetInput(void)
{
    mainGameMechsRef->collectAsynchInput();
}

void RunLogic(void)
{
    myPlayer->movePlayer();
    mainGameMechsRef->clearInput();
}

void DrawScreen(void)
{
    MacUILib_clearScreen();
    objPosArrayList* playerPos = myPlayer->getPlayerPos();
    objPosArrayList* foodPos = myFood->getFoodPos();
    int playerSize = playerPos->getSize();
    int foodSize = myFood->getFoodPos()->getSize();
    
    int boardX = mainGameMechsRef->getBoardSizeX();
    int boardY = mainGameMechsRef->getBoardSizeY();
    // objPos player_pos = myPlayer->getPlayerPos()->getHeadElement(); // ALSO FIX
    //objPos foodPos = myFood->getFoodPos()->;
    bool playerFlag = false;
    bool foodFlag = false;
    
    int i,j;
    for(i = 0; i < boardY; i++)
    {
        for(j = 0; j < boardX; j++)
        {
            playerFlag = false;
            foodFlag = false;
            
            for(int k = 0; k < playerSize; k++)
            {
                if(playerPos->getElement(k).pos->x == j && playerPos->getElement(k).pos->y == i)
                {
                    MacUILib_printf("%c", playerPos->getElement(k).symbol);
                    playerFlag = true;
                    break;
                }
            }

            if(playerFlag)
            {
                continue;
            }

            for(int x = 0; x < foodSize; x++)
            {
                if(foodPos->getElement(x).pos->x == j && foodPos->getElement(x).pos->y == i)
                {
                    MacUILib_printf("%c", foodPos->getElement(x).symbol);
                    foodFlag = true;
                    break;
                }
            }

            if(foodFlag)
            {
                continue;
            }

            if(i == 0 || i == boardY - 1 || j == 0 || j == boardX - 1)
            {
                MacUILib_printf("#");
            }
            else
            {
                MacUILib_printf(" ");
            }

        }

        MacUILib_printf("\n");
    }  

    MacUILib_printf("\nScore: %d\n", mainGameMechsRef->getScore());
    MacUILib_printf("Snake Size: %d\n", myPlayer->getPlayerPos()->getSize());
    MacUILib_printf("\nThe 'o' symbol is normal food\n");
    MacUILib_printf("The '+' symbol is GOOD: it increases your score by however long your snake is, then reduces your snake size to 1\n");
    MacUILib_printf("The '-' symbol is BAD: it doubles the size of your snake and gives you no points\n");
}

void LoopDelay(void)
{
    MacUILib_Delay(DELAY_CONST); // 0.1s delay
}


void CleanUp(void)
{
    //MacUILib_clearScreen();  
    
    if(mainGameMechsRef->getLoseFlagStatus())
    {
        MacUILib_printf("\nYou lost the game :(\n");
    }
    else if(!(mainGameMechsRef->getLoseFlagStatus()))
    {
        MacUILib_printf("\nGame ended by Player.\n");
    }

    //MacUILib_printf("Score: %d", mainGameMechsRef->getScore());

    MacUILib_uninit();

    delete myPlayer;
    delete mainGameMechsRef;
    delete myFood;
}
