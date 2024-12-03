#include "GameMechs.h"
#include "MacUILib.h"
#include "time.h"

GameMechs *myGM;

GameMechs::GameMechs()
{
    // Default constructor: initialize all members
    boardSizeX = 30;
    boardSizeY = 15;
    score = 0;
    exitFlag = false;
    loseFlag = false;
    input = '\0';

}

GameMechs::GameMechs(int boardX, int boardY)
{
    // Parameterized constructor: initialize with custom board size
    boardSizeX = boardX;
    boardSizeY = boardY;
    exitFlag = false;
    loseFlag = false;
    score = 0;
    input = '\0';
}

// do you need a destructor?
GameMechs::~GameMechs()
{
    // no dynamic memory to clean up
}

bool GameMechs::getExitFlagStatus() const
{
    return exitFlag; 
}

bool GameMechs::getLoseFlagStatus() const
{ 
    return loseFlag;
}
    

char GameMechs::getInput() const
{
    return input;
}

int GameMechs::getScore() const
{
    return score; 
}

void GameMechs::incrementScore(int val)
{
    score += val;  // increments score by the value inputted
}

int GameMechs::getBoardSizeX() const
{
    return boardSizeX;
}

int GameMechs::getBoardSizeY() const
{
    return boardSizeY;
}


void GameMechs::setExitTrue()
{
    exitFlag = true;
}

void GameMechs::setLoseFlag()
{
    loseFlag = true;
}

void GameMechs::setInput(char this_input)
{
    input = this_input;
}

void GameMechs::clearInput()
{
    input = '\0';
}

// More methods should be added here

void GameMechs::collectAsynchInput()
{
    // Checks if there is an input. If yes, stores it in variable input
    if(MacUILib_hasChar())
    {
        input = MacUILib_getChar();
    }

    // Exit key is space bar
    if(input == ' ')
    {
        exitFlag = true;
    }

}
