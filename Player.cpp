#include "Player.h"
#include "objPos.h"


Player::Player(GameMechs* thisGMRef)
{
    mainGameMechsRef = thisGMRef;
    myDir = STOP;

    // more actions to be included

    playerPosList = new objPosArrayList();
    objPos initialPos((mainGameMechsRef->getBoardSizeX())/2, (mainGameMechsRef->getBoardSizeY())/2, '@');
    
    playerPos.pos-> x = initialPos.pos->x;
    playerPos.pos->y = initialPos.pos->y;
    playerPos.symbol = initialPos.symbol;
    
    playerPosList->insertHead(initialPos);
}


Player::~Player()
{
    // delete any heap members here
    delete[] playerPosList;
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
        char input = mainGameMechsRef->getInput();

        switch(input)
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
                playerPos.pos->x = mainGameMechsRef->getBoardSizeX() - 2;
            }
            break;
        case RIGHT:
            playerPos.pos->x++;
            if(playerPos.pos->x == mainGameMechsRef->getBoardSizeX() - 1)
            {
                playerPos.pos->x = 1;
            }
            break;
        case UP:
            playerPos.pos->y--;
            if(playerPos.pos->y == 0)
            {
                playerPos.pos->y = mainGameMechsRef->getBoardSizeY() - 2;
            }
            break;
        case DOWN:
            playerPos.pos->y++;
            if(playerPos.pos->y == mainGameMechsRef->getBoardSizeY() - 1)
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
// void Player::checkFoodConsumption()
// {
//     if(playerPos.pos->x == mainGameMechsRef->getFoodPos().pos->x && playerPos.pos->y == mainGameMechsRef->getFoodPos().pos->y)
//     {
//         mainGameMechsRef->incrementScore();
//         mainGameMechsRef->generateFood();
//     }
// }