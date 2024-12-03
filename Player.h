#ifndef PLAYER_H
#define PLAYER_H

#include "GameMechs.h"
#include "objPos.h"
#include "objPosArrayList.h"
#include "Food.h"

class Player
{
    public:
        enum Dir {UP, DOWN, LEFT, RIGHT, STOP};  // This is the direction state

        Player(GameMechs* thisGMRef, Food* thisFoodRef);
        ~Player();

        objPosArrayList* getPlayerPos() const;       
        void updatePlayerDir();
        void movePlayer();

        // More methods to be added here
        bool checkFoodConsumption();
        void increasePlayerLength();
        void checkSelfCollision();


    private:
        objPosArrayList* playerPosList;
        enum Dir myDir;

        // Need references to the Main Game Mechanisms and the Food class
        GameMechs* mainGameMechsRef;
        Food* foodRef;
};

#endif