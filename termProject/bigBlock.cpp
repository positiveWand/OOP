#include "bigBlock.h"
#include "gameTable.h"

#include <algorithm>

std::vector<Block*> BigBlock::getList() {
    return _componentBlocks;
}


bool BigBlock::canLeft() {
    bool allClear = true;

    for(int i = 0; i < _componentBlocks.size(); i++) {
        Block* targetBlock = _componentBlocks[i];
        int nextX = targetBlock->getXcor() - 1;
        int nextY = targetBlock->getYcor();

        bool noSameGroup = true;
        for(int j = 0; j < _componentBlocks.size(); j++) {
            if(nextX == _componentBlocks[j]->getXcor() && nextY == _componentBlocks[j]->getYcor()) {
                noSameGroup = false;
                break;
            }
        }

        if(noSameGroup) {
            if(!targetBlock->canLeft()) {
                allClear = false;
                return allClear;
            }
        }
    }

    return allClear;
}
bool BigBlock::canRight() {
    bool allClear = true;

    for(int i = 0; i < _componentBlocks.size(); i++) {
        Block* targetBlock = _componentBlocks[i];
        int nextX = targetBlock->getXcor() + 1;
        int nextY = targetBlock->getYcor();

        bool noSameGroup = true;
        for(int j = 0; j < _componentBlocks.size(); j++) {
            if(i != j) {
                if(nextX == _componentBlocks[j]->getXcor() && nextY == _componentBlocks[j]->getYcor()) {
                    noSameGroup = false;
                    break;
                }
            }
        }

        if(noSameGroup) {
            if(!targetBlock->canRight()) {
                allClear = false;
                return allClear;
            }
        }
    }

    return allClear;
}
bool BigBlock::canDown() {
    bool allClear = true;

    for(int i = 0; i < _componentBlocks.size(); i++) {
        Block* targetBlock = _componentBlocks[i];
        int nextX = targetBlock->getXcor();
        int nextY = targetBlock->getYcor() + 1;

        bool noSameGroup = true;
        for(int j = 0; j < _componentBlocks.size(); j++) {
            if(i != j) {
                if(nextX == _componentBlocks[j]->getXcor() && nextY == _componentBlocks[j]->getYcor()) {
                    noSameGroup = false;
                    break;
                }
            }
        }

        if(noSameGroup) {
            if(!targetBlock->canDown()) {
                allClear = false;
                return allClear;
            }
        }
    }

    return allClear;
}

void BigBlock::left() {
    //bool alive = true;
    if(this->canLeft()) {
        for(std::vector<Block*>::iterator itr = BigBlock::_componentBlocks.begin(); itr != BigBlock::_componentBlocks.end(); itr++) {
            Block* targetBlock = *itr;
            int currentX = targetBlock->getXcor();
            int currentY = targetBlock->getYcor();

            GameTable::empty(currentX, currentY);
            targetBlock->setCordinate(currentX - 1, currentY);
        }
        GameTable::insert(this);
    }
    else {
        //std::cout << "something wrong\n"; 
        this->downAll();
        //alive = false;
    }
    //return alive;
}
void BigBlock::right() {
    //bool alive = true;
    if(this->canRight()) {
        for(std::vector<Block*>::iterator itr = BigBlock::_componentBlocks.begin(); itr != BigBlock::_componentBlocks.end(); itr++) {
            Block* targetBlock = *itr;
            int currentX = targetBlock->getXcor();
            int currentY = targetBlock->getYcor();

            GameTable::empty(currentX, currentY);
            targetBlock->setCordinate(currentX + 1, currentY);
        }
        GameTable::insert(this);
    }
    else {
        this->downAll();
        //alive = false;
    }
    //return alive;
}
void BigBlock::down() {
    //bool alive = true;
    if(this->canDown()) {
        for(std::vector<Block*>::iterator itr = BigBlock::_componentBlocks.begin(); itr != BigBlock::_componentBlocks.end(); itr++) {
            Block* targetBlock = *itr;
            int currentX = targetBlock->getXcor();
            int currentY = targetBlock->getYcor();

            GameTable::empty(currentX, currentY);
            targetBlock->setCordinate(currentX, currentY + 1);
        }
        GameTable::insert(this);
    }
    else {
        this->downAll();
        //alive = false;
    }
    //return alive;
}
bool compareY(Block* a, Block* b) {
    return a->getYcor() > b->getYcor();
}
void BigBlock::downAll() {
    Block* anArray[_componentBlocks.size()];

    for(int i = 0; i < _componentBlocks.size(); i++) {
        anArray[i] = _componentBlocks[i];
    } 

    std::sort(anArray, anArray+_componentBlocks.size(), compareY);

    //std::cout << anArray[0]->getYcor() << anArray[1]->getYcor() << anArray[2]->getYcor() << "\n"; 

    for(int i = 0; i < _componentBlocks.size(); i++) {
        anArray[i]->downAll();
        //std::cout << "something wrong\n"; 
    }
}