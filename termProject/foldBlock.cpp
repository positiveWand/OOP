#include "foldBlock.h"
#include "gameTable.h"
#include <utility>

FoldBlock::FoldBlock(int a, int b, int c) {
    this->_componentBlocks.push_back(new Block(1, 1, static_cast<shared::color>(a)));
    this->_componentBlocks.push_back(new Block(2, 1, static_cast<shared::color>(b)));
    this->_componentBlocks.push_back(new Block(2, 0, static_cast<shared::color>(c)));

    this->_state = 0;
}

bool FoldBlock::rotate() {
    bool rotateControl = true;
    std::pair<int, int> locationArray[3];

    switch (this->_state)
    {
    case 0:
        for(int blockNum = 0; blockNum < 3; blockNum++) {
            int nextX;
            int nextY;
            switch (blockNum)
            {
            case 0:
                nextX = this->_componentBlocks[blockNum]->getXcor();
                nextY = this->_componentBlocks[blockNum]->getYcor() - 1;
                break;
            case 1:
                nextX = this->_componentBlocks[blockNum]->getXcor() - 1;
                nextY = this->_componentBlocks[blockNum]->getYcor();
                break;
            case 2:
                nextX = this->_componentBlocks[blockNum]->getXcor();
                nextY = this->_componentBlocks[blockNum]->getYcor() + 1;
                break;
            }

            if(nextX < 0 || 4 < nextX || nextY < 0 || 11 < nextY) {
                rotateControl = false;
                break;
            }
            else if(blockNum == 0 && GameTable::blockColor(nextX, nextY) != shared::NONE) {
                rotateControl = false;
                break;
            }
            else {
                locationArray[blockNum] = std::make_pair(nextX, nextY);
            }
        }
        break;
    case 1:
        for(int blockNum = 0; blockNum < 3; blockNum++) {
            int nextX;
            int nextY;
            switch (blockNum)
            {
            case 0:
                nextX = this->_componentBlocks[blockNum]->getXcor() + 1;
                nextY = this->_componentBlocks[blockNum]->getYcor();
                break;
            case 1:
                nextX = this->_componentBlocks[blockNum]->getXcor();
                nextY = this->_componentBlocks[blockNum]->getYcor() - 1;
                break;
            case 2:
                nextX = this->_componentBlocks[blockNum]->getXcor() - 1;
                nextY = this->_componentBlocks[blockNum]->getYcor();
                break;
            }

            if(nextX < 0 || 4 < nextX || nextY < 0 || 11 < nextY) {
                rotateControl = false;
                break;
            }
            else if(blockNum == 0 && GameTable::blockColor(nextX, nextY) != shared::NONE) {
                rotateControl = false;
                break;
            }
            else {
                locationArray[blockNum] = std::make_pair(nextX, nextY);
            }
        }
        break;
    case 2:
        for(int blockNum = 0; blockNum < 3; blockNum++) {
            int nextX;
            int nextY;
            switch (blockNum)
            {
            case 0:
                nextX = this->_componentBlocks[blockNum]->getXcor();
                nextY = this->_componentBlocks[blockNum]->getYcor() + 1;
                break;
            case 1:
                nextX = this->_componentBlocks[blockNum]->getXcor() + 1;
                nextY = this->_componentBlocks[blockNum]->getYcor();
                break;
            case 2:
                nextX = this->_componentBlocks[blockNum]->getXcor();
                nextY = this->_componentBlocks[blockNum]->getYcor() - 1;
                break;
            }

            if(nextX < 0 || 4 < nextX || nextY < 0 || 11 < nextY) {
                rotateControl = false;
                break;
            }
            else if(blockNum == 0 && GameTable::blockColor(nextX, nextY) != shared::NONE) {
                rotateControl = false;
                break;
            }
            else {
                locationArray[blockNum] = std::make_pair(nextX, nextY);
            }
        }
        break;
    case 3:
        for(int blockNum = 0; blockNum < 3; blockNum++) {
            int nextX;
            int nextY;
            switch (blockNum)
            {
            case 0:
                nextX = this->_componentBlocks[blockNum]->getXcor() - 1;
                nextY = this->_componentBlocks[blockNum]->getYcor();
                break;
            case 1:
                nextX = this->_componentBlocks[blockNum]->getXcor();
                nextY = this->_componentBlocks[blockNum]->getYcor() + 1;
                break;
            case 2:
                nextX = this->_componentBlocks[blockNum]->getXcor() + 1;
                nextY = this->_componentBlocks[blockNum]->getYcor();
                break;
            }

            if(nextX < 0 || 4 < nextX || nextY < 0 || 11 < nextY) {
                rotateControl = false;
                break;
            }
            else if(blockNum == 0 && GameTable::blockColor(nextX, nextY) != shared::NONE) {
                rotateControl = false;
                break;
            }
            else {
                locationArray[blockNum] = std::make_pair(nextX, nextY);
            }
        }
        break;
    }

    if(rotateControl) {
        for(int blockNum = 0; blockNum < 3; blockNum++) {
            GameTable::empty(_componentBlocks[blockNum]->getXcor(), _componentBlocks[blockNum]->getYcor());
            _componentBlocks[blockNum]->setCordinate(locationArray[blockNum].first, locationArray[blockNum].second);
        }
        GameTable::insert(this);
        _state = (_state+1)%4;
        return true;
    }
    else {
        return false;
    }
}