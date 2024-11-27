#include "Player.h"

Player::Player(GameMechs* thisGMRef)
{
    mainGameMechsRef = thisGMRef;
    myDir = STOP;

    // more actions to be included
    playerPos.pos-> x = 10;
    playerPos.pos->y = 5;
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
            playerPos.pos->x -= 1;
            if(playerPos.pos->x == 0)
            {
                playerPos.pos->x = 18;
            }
            break;
        case RIGHT:
            playerPos.pos->x += 1;
            if(playerPos.pos->x == 19)
            {
                playerPos.pos->x = 1;
            }
            break;
        case UP:
            playerPos.pos->y -= 1;
            if(playerPos.pos->y == 0)
            {
                playerPos.pos->y = 8;
            }
            break;
        case DOWN:
            playerPos.pos->y += 1;
            if(playerPos.pos->y == 9)
            {
                playerPos.pos->y = 1;
            }
            break;
        default:
            break;
    }
}

// More methods to be added