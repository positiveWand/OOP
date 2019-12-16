#ifndef BLOCK_H
#define BLOCK_H

#include <string>
#include <iostream>

#include "shared.h"

class ColorGroup;

class Block {
    public:
        // 생성자와 소멸자
        Block();
        Block(int x, int y, shared::color aColor);
        ~Block();

        // getter
        shared::color getColor();
        int getXcor();
        int getYcor();
        ColorGroup* getColorGroup();

        // setter
        void setColor(shared::color aColor);
        void setCordinate(int xCor, int yCor);
        void setColorGroup(ColorGroup* aGroup);


        bool canLeft();
        bool canRight();
        bool canDown();

        void left();
        void right();
        void down();
        void downAll();

        void findAndMerge();
        void merge(Block* aBlock);

        void explode();

    private:
        shared::color _blockColor;
        int _xCor, _yCor;
        ColorGroup* _colorGroup;
};

#endif // BLOCK_H
