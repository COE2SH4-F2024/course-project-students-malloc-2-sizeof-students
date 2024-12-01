#include "GameMechs.h"
#include "MacUILib.h"
#include "time.h"

GameMechs *myGM;

GameMechs::GameMechs()
{
    // : input('\0'), exitFlag(false), loseFlag(false), score(0), boardSizeX(30), boardSizeY(15), food() {
    // Default constructor: initialize all members
    // No need for additional code in the constructor body unless needed

    boardSizeX = 30;
    boardSizeY = 15;
    score = 0;
    exitFlag = false;
    loseFlag = false;
    input = '\0';

    //food.setObjPos(-10, -10, 'o');
}

GameMechs::GameMechs(int boardX, int boardY)
{
    // : input('\0'), exitFlag(false), loseFlag(false), score(0), boardSizeX(boardX), boardSizeY(boardY), food() {
    // Parameterized constructor: initialize with custom board size
    // No need for additional code in the constructor body unless needed

    boardSizeX = boardX;
    boardSizeY = boardY;
    exitFlag = false;
    loseFlag = false;
    score = 0;
    input = '\0';

    //food.setObjPos(-10, -10, 'o');
}

// do you need a destructor?
GameMechs::~GameMechs()
{
    // no dynamic memory to clean up right now...
}

bool GameMechs::getExitFlagStatus() const
{
    return exitFlag; 
}

bool GameMechs::getLoseFlagStatus() const
{ 
    return loseFlag;
}
    

char GameMechs::getInput() 
{
    return input;
}

int GameMechs::getScore() const
{
    return score; 
}

void GameMechs::incrementScore(int val)
{
    score += val;
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
    if(MacUILib_hasChar())
    {
        input = MacUILib_getChar();
    }

    if(input == ' ')
    {
        exitFlag = true;
    }

}
