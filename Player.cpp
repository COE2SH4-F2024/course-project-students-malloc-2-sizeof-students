#include "Player.h"

Player::Player(GameMechs* thisGMRef)
{
    mainGameMechsRef = thisGMRef;
    myDir = STOP;

    // more actions to be included
    playerPos.pos-> x = (mainGameMechsRef->getBoardSizeX())/2;
    playerPos.pos->y = (mainGameMechsRef->getBoardSizeY())/2;
    playerPos.symbol = '@';
}


Player::~Player()
{
    // delete any heap members here
}

objPos Player::getPlayerPos() const
{
    // return the reference to the playerPos arrray list
    return playerPos;
}

void Player::updatePlayerDir()
{
        // PPA3 input processing logic
        switch(mainGameMechsRef->getInput())
        {                      
            case 'w':
                if(myDir != DOWN)
                {
                    myDir = UP;
                }
                break;
           
            case 'a':
                if(myDir != RIGHT)
                {
                    myDir = LEFT;
                }
                break;
            
            case 's':
                if(myDir != UP)
                {
                    myDir = DOWN;
                }
                break;

            case 'd':
                if(myDir != LEFT)
                {
                    myDir = RIGHT;
                }
                break;
            default:
                break;
        }        
}

void Player::movePlayer()
{
    // PPA3 Finite State Machine logic
    switch(myDir)
    {
        case LEFT:
            playerPos.pos->x--;
            if(playerPos.pos->x == 0)
            {
                playerPos.pos->x = 28;
            }
            break;
        case RIGHT:
            playerPos.pos->x++;
            if(playerPos.pos->x == 29)
            {
                playerPos.pos->x = 1;
            }
            break;
        case UP:
            playerPos.pos->y--;
            if(playerPos.pos->y == 0)
            {
                playerPos.pos->y = 13;
            }
            break;
        case DOWN:
            playerPos.pos->y++;
            if(playerPos.pos->y == 14)
            {
                playerPos.pos->y = 1;
            }
            break;
        default:
            break;
    }
}

// More methods to be added