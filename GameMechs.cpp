#include "GameMechs.h"
#include "MacUILib.h"
#include "time.h"
GameMechs *myGM;

GameMechs::GameMechs()
{
    input= 0;
    exitFlag = false;
    loseFlag = false;
    score = 0;

    boardSizeX = 30;
    boardSizeY = 15;

}

GameMechs::GameMechs(int boardX, int boardY)
{
    input= 0;
    exitFlag = false;
    loseFlag = false;
    score = 0;

    boardSizeX = boardX;
    boardSizeY = boardY;
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
    if(MacUILib_hasChar()){
        input = MacUILib_getChar();
        myGM -> setInput (input);

    }
    return input;
}

int GameMechs::getScore() const
{
    return score; 
}

void GameMechs::incrementScore()
{
    score++;
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
void GameMechs::generateFood(const objPos& blockOff) {
    bool valid = false;

    while (!valid) {
        // Generate random coordinates for the food
        int x = rand() % boardSizeX;
        int y = rand() % boardSizeY;

        // Check if the generated position is valid
        valid = !(x == blockOff.pos->x && y == blockOff.pos->y);

        if (valid) {
            // Set the food position and symbol
            food.setObjPos(x, y, '@'); // '@' is the food symbol
        }
    }
}
objPos GameMechs::getFoodPos() const {
    return food;
}




