#ifndef FOOD_H
#define FOOD_H

#include "objPos.h"
#include "objPosArrayList.h"
#include "GameMechs.h"

using namespace std;

// Custom class for food item generation 
class Food
{
    private:
        int boardSizeX;
        int boardSizeY;
        GameMechs* mainGameMechsRef;
        objPosArrayList* foodBucket;

    
    public:
        Food(GameMechs* thisGMRef);
        ~Food();
        objPosArrayList* getFoodPos() const;
        void generateFood(const objPosArrayList* blockOffList);
        void clearFood();
};

#endif