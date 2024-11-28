#include "GameMechs.h"

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

void GameMechs::incrementScore()
{
    ++score;
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
// void GameMechs::generateFood(const objPosArrayList& snakeBody) {
//     bool valid = false;

//     while (!valid) {
//         int x = rand() % boardSizeX;
//         int y = rand() % boardSizeY;

//         valid = true;  // Assume the position is valid until proven otherwise

//         // Check if food overlaps with any part of the snake's body
//         for (int i = 0; i < snakeBody.getSize(); ++i) {
//             if (snakeBody.getElement(i).getX() == x && snakeBody.getElement(i).getY() == y) {
//                 valid = false; // If overlap, find a new position
//                 break;
//             }
//         }

//         if (valid) {
//             food.setX(x);
//             food.setY(y);
//             food.setSymbol('@'); // Set food symbol to '@'
//         }
//     }
// }
