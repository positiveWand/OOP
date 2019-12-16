#ifndef GAMEMAP_H
#define GAMEMAP_H

#include <string>
#include <iostream>
#include <set>

#include "shared.h"
#include "block.h"
#include "colorGroup.h"

class BigBlock;

class GameTable {
    public:
        static const int WIDTH = 5;
        static const int HEIGHT = 12;

        // getter
        static int getScore();
        static bool getWorking();
        static Block* getBlock(int x, int y);

        static shared::color blockColor(int x, int y);

        static void insert(Block* aBlock);
        static void insert(BigBlock* aGroup);
        static void empty(int x, int y);

        static void startGame();
        static void showTable();
        static bool summonBlock(int type);
        static bool execute(char aInput);

        static void insertExplosion(ColorGroup* aGroup);
        static void removeExplosion(ColorGroup* aGroup);
        static void canExplode();
        static void explosion();

        static void scoreUp(int up);

    private:
        static int _score;
        static int _combo;
        static bool _working;
        static Block* _blockArray[WIDTH][HEIGHT];
        static std::set<ColorGroup *> _explodeGroup;
        static BigBlock* _currentBigBlock;

};

#endif // GAMEMAP_H
