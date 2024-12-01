#include "Player.h"
#include "objPos.h"
#include "objPosArrayList.h"
#include "Food.h"


Player::Player(GameMechs* thisGMRef, Food* thisFoodRef)
{
    mainGameMechsRef = thisGMRef;
    foodRef = thisFoodRef;
    myDir = STOP;

    // more actions to be included

    playerPosList = new objPosArrayList();
    objPos headPos((mainGameMechsRef->getBoardSizeX())/2, (mainGameMechsRef->getBoardSizeY())/2, '@');
    
    playerPosList->insertHead(headPos);
}


Player::~Player()
{
    // delete any heap members here
    delete playerPosList;
}

objPosArrayList* Player::getPlayerPos() const
{
    // return the reference to the playerPos arrray list
    return playerPosList;
}

void Player::updatePlayerDir()
{
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
    updatePlayerDir();

    objPos tmpPos(playerPosList->getHeadElement().pos->x, playerPosList->getHeadElement().pos->y, playerPosList->getHeadElement().symbol);

    switch(myDir)
    {
        case LEFT:
            tmpPos.pos->x--;
            if(tmpPos.pos->x == 0)
            {
                tmpPos.pos->x = mainGameMechsRef->getBoardSizeX() - 2;
            }
            break;
        case RIGHT:
            tmpPos.pos->x++;
            if(tmpPos.pos->x == mainGameMechsRef->getBoardSizeX() - 1)
            {
                tmpPos.pos->x = 1;
            }
            break;
        case UP:
            tmpPos.pos->y--;
            if(tmpPos.pos->y == 0)
            {
                tmpPos.pos->y = mainGameMechsRef->getBoardSizeY() - 2;
            }
            break;
        case DOWN:
            tmpPos.pos->y++;
            if(tmpPos.pos->y == mainGameMechsRef->getBoardSizeY() - 1)
            {
                tmpPos.pos->y = 1;
            }
            break;
        default:
            break;
    }
    
    playerPosList->insertHead(tmpPos);

    increasePlayerLength();
    checkSelfCollision();
    
}

// More methods to be added

bool Player::checkFoodConsumption()
{
    int foodSize = foodRef->getFoodPos()->getSize();
    int playerSize = playerPosList->getSize();


    
    for(int i = 0; i < foodSize; i++) 

        if(playerPosList->getHeadElement().pos->x == foodRef->getFoodPos()->getElement(i).pos->x && playerPosList->getHeadElement().pos->y == foodRef->getFoodPos()->getElement(i).pos->y)
        {
            char foodSymbol = foodRef->getFoodPos()->getElement(i).symbol;

            if(foodSymbol == '+')
            {
                mainGameMechsRef->incrementScore(playerSize - 1);            // Increment score by the size of the snake body
                playerPosList->setSizeto1();                             // Set snake body size to 1
            }
            else if(foodSymbol == '-')
            {
                while(playerPosList->getSize() < 2 * (playerSize - 1))                       // double size of the snake body
                {
                    playerPosList->insertTail(playerPosList->getTailElement());
                }

            }
            else 
            {
                mainGameMechsRef->incrementScore(1);                     // for normal food symbol 'o', increment score by 1
            }
            
            foodRef->generateFood(playerPosList);
            return true;
        }

    return false;
}

void Player::increasePlayerLength()
{
    if(!checkFoodConsumption())
    {
        playerPosList->removeTail();
    }
}


void Player::checkSelfCollision() // changed from bool - check if okay
{
    // Check for Self collision
    int listSize = playerPosList->getSize();
    for(int i = 1; i < listSize; i++)
    {
        if(playerPosList->getHeadElement().pos->x == playerPosList->getElement(i).pos->x && playerPosList->getHeadElement().pos->y == playerPosList->getElement(i).pos->y)
        {
            mainGameMechsRef->setLoseFlag();
            mainGameMechsRef->setExitTrue();
        }
    }

}