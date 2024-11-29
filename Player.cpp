#include "Player.h"
#include "objPos.h"


Player::Player(GameMechs* thisGMRef)
{
    mainGameMechsRef = thisGMRef;
    myDir = STOP;

    // more actions to be included
    // playerPos.pos-> x = mainGameMechsRef ->getBoardSizeX() / 2;
    // playerPos.pos->y = mainGameMechsRef ->getBoardSizeY() / 2;;
    // playerPos.symbol = '@';

    playerPosList = new objPosArrayList();
    objPos initialPos(mainGameMechsRef->getBoardSizeX() / 2, mainGameMechsRef->getBoardSizeY() / 2, '@');
    playerPosList->insertHead(initialPos);
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
    // where do i get input from? 
    char input = mainGameMechsRef -> getInput();
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
    // Check for food consumption
    if (playerPos.pos->x == mainGameMechsRef->getFoodPos().pos->x && playerPos.pos->y == mainGameMechsRef->getFoodPos().pos->y)
    {
        mainGameMechsRef->incrementScore();            // Increment score
        Player player(mainGameMechsRef); //declared
        //mainGameMechsRef->generateFood(objPos()); // WHYYYYYYYYYYY
        mainGameMechsRef->generateFood(player.getPlayerPos());



    }
}

// More methods to be added