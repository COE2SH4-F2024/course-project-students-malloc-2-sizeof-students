#include "Player.h"
#include "objPos.h"
#include "objPosArrayList.h"
#include "Food.h"


Player::Player(GameMechs* thisGMRef, Food* thisFoodRef)
{
    mainGameMechsRef = thisGMRef;
    foodRef = thisFoodRef;
    myDir = STOP;

    playerPosList = new objPosArrayList();  // Instantiating playerPosList on heap
    objPos headPos((mainGameMechsRef->getBoardSizeX())/2, (mainGameMechsRef->getBoardSizeY())/2, '@');  // Starting position of player
    
    playerPosList->insertHead(headPos);
}


Player::~Player()
{
    // deleting playerPosList from heap
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

    // make tmpPos equal to the head element
    objPos tmpPos(playerPosList->getHeadElement().pos->x, playerPosList->getHeadElement().pos->y, playerPosList->getHeadElement().symbol);

    // Update tmpPos to where the snake is moving based on myDir status
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
    
    playerPosList->insertHead(tmpPos); // make tmpPos the new head

    increasePlayerLength();
    checkSelfCollision();
    
}

// More methods to be added

bool Player::checkFoodConsumption()  // check if player has consumed the food
{
    int foodSize = foodRef->getFoodPos()->getSize();
    int playerSize = playerPosList->getSize(); //get player size

    //for loop to iterate through elements within food bucket
    for(int i = 0; i < foodSize; i++)
    {
        objPos my_player = playerPosList->getHeadElement();
        char foodSymbol = foodRef->getFoodPos()->getElement(i).getSymbolIfPosEqual(&my_player);  // gets food symbol based on collision.  
        
        if(foodSymbol == 0)
        {
            continue;
        }
        if(foodSymbol == 'o') 
        {
            mainGameMechsRef->incrementScore(1); // normal food, increments score by 1
            foodRef->generateFood(playerPosList); // add to tail by 1
            return true;
        }
        else if(foodSymbol == '+')
        {
            mainGameMechsRef->incrementScore(playerSize - 1);                       // Increment score by the size of the snake body
            while (playerPosList->getSize() > 1)
            {
                playerPosList->removeTail();
            }
            foodRef->generateFood(playerPosList);                                   // Set snake body size to 1
            return true;
        }
        else if(foodSymbol == '-')                                                  // This food symbol causes SNAKE DEATH and exits
        {
            playerPosList->removeTail(); 
            mainGameMechsRef->setLoseFlag();
            mainGameMechsRef->setExitTrue();
            return true;
        }
    }

    return false;
}

void Player::increasePlayerLength()
{
    if(!checkFoodConsumption())  // if food isnt consumed, player length does not increase 
    {
        playerPosList->removeTail();
    }
}


void Player::checkSelfCollision()
{
    // Check for Self collision
    int listSize = playerPosList->getSize();
    //for loop iterates through size of snake
    for(int i = 1; i < listSize; i++)
    {
        objPos my_player = playerPosList->getHeadElement(); 
        if(playerPosList->getElement(i).isPosEqual(&my_player))   // if player collides with their tail, exit
        {
            mainGameMechsRef->setLoseFlag();
            mainGameMechsRef->setExitTrue();
        }
    }

}