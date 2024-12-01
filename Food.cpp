#include "Food.h"
#include "time.h"

Food::Food(GameMechs* thisGMRef)
{
    mainGameMechsRef = thisGMRef;

    boardSizeX = mainGameMechsRef->getBoardSizeX();
    boardSizeY = mainGameMechsRef->getBoardSizeY();

    foodBucket = new objPosArrayList();

    //food.setObjPos(-10, -10, 'o');

}

Food::~Food()
{
    delete foodBucket;
}

void Food::generateFood(const objPosArrayList* blockOffList) {
    // bool valid = false;

    // srand(time(NULL));
    // while (!valid) 
    // {
    //     // Generate random coordinates for the food
    //     int x = rand() % boardSizeX;
    //     int y = rand() % boardSizeY;
    //     int listSize = blockOffList->getSize();

    //     valid = true;

    //     for(int i = 0; i < listSize; i++)
    //     {
    //         if(x == blockOffList->getElement(i).pos->x || y == blockOffList->getElement(i).pos->y || x == 0 || y == 0 || x == (boardSizeX - 1) || y == (boardSizeY - 1)) 
    //         {
    //             valid = false;
    //         }
    //     }

    //     food.setObjPos(x, y, 'o'); // 'o' is the food symbol
    // }

    clearFood();

    int x_vector[boardSizeX]; // bit vector for x-coordinates
    int y_vector[boardSizeY]; // bit vector for y-coordinates

    int i;
    for(i = 0; i < boardSizeX; i++)
    {x_vector[i] = 0;}

    for(i = 0; i < boardSizeY; i++)
    {y_vector[i] = 0;}

    objPos random;

    bool flag = true;

    while(foodBucket->getSize() < 5)
    {
        flag = true; 

        random.pos->x = rand() % (boardSizeX - 1);
        random.pos->y = rand() % (boardSizeY - 1);

        for(int i = 0; i < blockOffList->getSize(); i++)
        {
            if(random.pos->x == blockOffList->getElement(i).pos->x || x_vector[random.pos->x] != 0 || random.pos->x == 0 || random.pos->y == blockOffList->getElement(i).pos->y || y_vector[random.pos->y] != 0 || random.pos->y == 0)
            {
                flag = false;
                break;
            }
        }

        if(!flag)
        {
            continue;
        }
        else if(flag && foodBucket->getSize() < 3)
        {
            random.symbol = 'o'; // Regular Food
            foodBucket->insertTail(random);

            x_vector[random.pos->x]++;
            y_vector[random.pos->y]++;
        }
        else if(flag && foodBucket->getSize() < 4)
        {
            random.symbol = '+'; // Special Food ('good' one)
            foodBucket->insertTail(random);

            x_vector[random.pos->x]++;
            y_vector[random.pos->y]++;
        }
        else if(flag && foodBucket->getSize() < 5)
        {
            random.symbol = '-'; // Special Food ('bad' one)
            foodBucket->insertTail(random);

            x_vector[random.pos->x]++;
            y_vector[random.pos->y]++;
        }
    }

    // flag = true;
     
    // while(listSize < 4)
    // {
        
    //     random.pos->x = rand() % (boardSizeX - 1);
    //     random.pos->y = rand() % (boardSizeY - 1);
        
    //     for(int i = 0; i < blockOffList->getSize(); i++)
    //     {
    //         if(random.pos->x == blockOffList->getElement(i).pos->x || x_vector[random.pos->x] != 0 || random.pos->x == 0 || random.pos->y == blockOffList->getElement(i).pos->y || y_vector[random.pos->y] != 0 || random.pos->y == 0)
    //         {
    //             flag = false;
    //         }
    //     }

    //     if(flag)
    //     {
    //         random.symbol = '-'; // Bad Food
    //         foodBucket->insertTail(random);
    //         x_vector[random.pos->x]++;
    //         y_vector[random.pos->y]++;
    //         listSize++;
    //     }

    // }

    // flag = true;

    // while(listSize < 5)
    // {
        
    //     random.pos->x = rand() % (boardSizeX - 1);
    //     random.pos->y = rand() % (boardSizeY - 1);
        
    //     for(int i = 0; i < blockOffList->getSize(); i++)
    //     {
    //         if(random.pos->x == blockOffList->getElement(i).pos->x || x_vector[random.pos->x] != 0 || random.pos->x == 0 || random.pos->y == blockOffList->getElement(i).pos->y || y_vector[random.pos->y] != 0 || random.pos->y == 0)
    //         {
    //             flag = false;
    //         }
    //     }

    //     if(flag)
    //     {
    //         random.symbol = '+'; // Special Food
    //         foodBucket->insertTail(random);
    //         x_vector[random.pos->x]++;
    //         y_vector[random.pos->y]++;
    //         listSize++;
    //     }

    // }

}

objPosArrayList* Food::getFoodPos() const 
{
    return foodBucket;
}

// objPos Food::getFoodPosElement(int index) const
// {
//     return foodBucket->getElement(index);
// }

void Food::clearFood()
{
    for(int i = 1; i < foodBucket->getSize(); i++)
    {
        foodBucket->removeTail();
    }
}