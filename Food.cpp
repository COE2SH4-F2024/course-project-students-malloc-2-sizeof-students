#include "Food.h"
#include "time.h"

Food::Food(GameMechs* thisGMRef) // Accepts reference to GameMechs class to access its methods
{
    mainGameMechsRef = thisGMRef;

    boardSizeX = mainGameMechsRef->getBoardSizeX();
    boardSizeY = mainGameMechsRef->getBoardSizeY();

    foodBucket = new objPosArrayList();  // Instantiating foodBucket on heap

}

Food::~Food()
{
    delete foodBucket;  // clearing foodBucket from heap
}

void Food::generateFood(const objPosArrayList* blockOffList) {

    clearFood();

    int x_vector[boardSizeX]; // bit vector for x-coordinates
    int y_vector[boardSizeY]; // bit vector for y-coordinates

    // Initializing the elements to 0
    int i;
    for(i = 0; i < boardSizeX; i++)
    {x_vector[i] = 0;}

    for(i = 0; i < boardSizeY; i++)
    {y_vector[i] = 0;}

    objPos random; // new objPos instance to hold the randomly generated x,y positions

    bool flag = true;   // flag to check for whether a random generation is valid

    while(foodBucket->getSize() < 5)
    {
        flag = true; 

        random.pos->x = rand() % (boardSizeX - 1);
        random.pos->y = rand() % (boardSizeY - 1);

        for(int i = 0; i < blockOffList->getSize(); i++)
        {
            // Checking if random overlaps with snakebody, was previously used, or lies on the game border
            if(blockOffList->getElement(i).isPosEqual(&random) || x_vector[random.pos->x] != 0 || random.pos->x == 0 || y_vector[random.pos->y] != 0 || random.pos->y == 0) 
            {
                flag = false; // random generation is invalid
                break;
            }
        }

        if(!flag)  // If invalid, continue to next iteration
        {
            continue;
        }
        else if(flag && foodBucket->getSize() < 3)  // First 3 elements of foodBucket will have 'o' symbol
        {
            random.symbol = 'o'; // Regular Food
            foodBucket->insertTail(random);

            // Marking x & y as "used" in the bit vector
            x_vector[random.pos->x]++; 
            y_vector[random.pos->y]++;
        }
        else if(flag && foodBucket->getSize() < 4)  // Fourth element of foodBucket with have '+' symbol 
        {
            random.symbol = '+'; // Special Food ('good' one)
            foodBucket->insertTail(random);

            x_vector[random.pos->x]++;
            y_vector[random.pos->y]++;
        }
        else if(flag && foodBucket->getSize() < 5)   // Fifth element of foodBucket with have '-' symbol 
        {
            random.symbol = '-'; // Special Food ('bad' one)
            foodBucket->insertTail(random);

            x_vector[random.pos->x]++;
            y_vector[random.pos->y]++;
        }
    }

}

objPosArrayList* Food::getFoodPos() const 
{
    return foodBucket;
}

void Food::clearFood()
{
    // Setting size of foodBucket to 0 
    while(foodBucket->getSize() > 0)  
    {
        foodBucket->removeTail();
    }
}