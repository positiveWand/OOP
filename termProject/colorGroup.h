#ifndef COLORBLOCK_H
#define COLORBLOCK_H

#include <string>
#include <iostream>
#include <set>

#include "shared.h"

class Block;

class ColorGroup {
    public:
        // 생성자와 소멸자
        ColorGroup();
        ColorGroup(shared::color aColor);
        ColorGroup(Block* aBlock);
        ~ColorGroup();

        // getter
        shared::color getColor();
        std::set<Block*> getSet();
        int getSetSize();

        // setter
        void setColor(shared::color aColor);

        void insert(std::set<Block*> aSet);
        void explode();

    private:
        shared::color _groupColor;
        std::set<Block*> _blocks;
};

#endif // COLORBLOCK_H
