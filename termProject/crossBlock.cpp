#include "crossBlock.h"
#include "gameTable.h"
#include <utility>

CrossBlock::CrossBlock(int a, int b, int c, int d, int e) {
    this->_componentBlocks.push_back(new Block(2, 1, static_cast<shared::color>(a)));
    this->_componentBlocks.push_back(new Block(3, 1, static_cast<shared::color>(b)));
    this->_componentBlocks.push_back(new Block(2, 2, static_cast<shared::color>(c)));
    this->_componentBlocks.push_back(new Block(1, 1, static_cast<shared::color>(d)));
    this->_componentBlocks.push_back(new Block(2, 0, static_cast<shared::color>(e)));

    this->_state = 0;
}

bool CrossBlock::rotate() {
    bool rotateControl = true;
    std::pair<int, int> locationArray[5];

    switch (this->_state)
    {
        case 0:
            for(int blockNum = 0; blockNum < 5; blockNum++) {
                int nextX;
                int nextY;
                switch (blockNum)
                {
                case 0:
                    nextX = this->_componentBlocks[blockNum]->getXcor();
                    nextY = this->_componentBlocks[blockNum]->getYcor();
                    break;
                case 1:
                    nextX = this->_componentBlocks[blockNum]->getXcor() - 1;
                    nextY = this->_componentBlocks[blockNum]->getYcor() + 1;
                    break;
                case 2:
                    nextX = this->_componentBlocks[blockNum]->getXcor() - 1;
                    nextY = this->_componentBlocks[blockNum]->getYcor() - 1;
                    break;
                case 3:
                    nextX = this->_componentBlocks[blockNum]->getXcor() + 1;
                    nextY = this->_componentBlocks[blockNum]->getYcor() - 1;
                    break;
                case 4:
                    nextX = this->_componentBlocks[blockNum]->getXcor() + 1;
                    nextY = this->_componentBlocks[blockNum]->getYcor() + 1;
                    break;
                }

                if(nextX < 0 || 4 < nextX || nextY < 0 || 11 < nextY) {
                    rotateControl = false;
                    break;
                }
                else {
                    locationArray[blockNum] = std::make_pair(nextX, nextY);
                }
            }
            break;
        case 1:
            for(int blockNum = 0; blockNum < 5; blockNum++) {
                int nextX;
                int nextY;
                switch (blockNum)
                {
                case 0:
                    nextX = this->_componentBlocks[blockNum]->getXcor();
                    nextY = this->_componentBlocks[blockNum]->getYcor();
                    break;
                case 1:
                    nextX = this->_componentBlocks[blockNum]->getXcor() - 1;
                    nextY = this->_componentBlocks[blockNum]->getYcor() - 1;
                    break;
                case 2:
                    nextX = this->_componentBlocks[blockNum]->getXcor() + 1;
                    nextY = this->_componentBlocks[blockNum]->getYcor() - 1;
                    break;
                case 3:
                    nextX = this->_componentBlocks[blockNum]->getXcor() + 1;
                    nextY = this->_componentBlocks[blockNum]->getYcor() + 1;
                    break;
                case 4:
                    nextX = this->_componentBlocks[blockNum]->getXcor() - 1;
                    nextY = this->_componentBlocks[blockNum]->getYcor() + 1;
                    break;
                }

                if(nextX < 0 || 4 < nextX || nextY < 0 || 11 < nextY) {
                    rotateControl = false;
                    break;
                }
                else {
                    locationArray[blockNum] = std::make_pair(nextX, nextY);
                }
            }
            break;
        case 2:
            for(int blockNum = 0; blockNum < 5; blockNum++) {
                int nextX;
                int nextY;
                switch (blockNum)
                {
                case 0:
                    nextX = this->_componentBlocks[blockNum]->getXcor();
                    nextY = this->_componentBlocks[blockNum]->getYcor();
                    break;
                case 1:
                    nextX = this->_componentBlocks[blockNum]->getXcor() + 1;
                    nextY = this->_componentBlocks[blockNum]->getYcor() - 1;
                    break;
                case 2:
                    nextX = this->_componentBlocks[blockNum]->getXcor() + 1;
                    nextY = this->_componentBlocks[blockNum]->getYcor() + 1;
                    break;
                case 3:
                    nextX = this->_componentBlocks[blockNum]->getXcor() - 1;
                    nextY = this->_componentBlocks[blockNum]->getYcor() + 1;
                    break;
                case 4:
                    nextX = this->_componentBlocks[blockNum]->getXcor() - 1;
                    nextY = this->_componentBlocks[blockNum]->getYcor() - 1;
                    break;
                }

                if(nextX < 0 || 4 < nextX || nextY < 0 || 11 < nextY) {
                    rotateControl = false;
                    break;
                }
                else {
                    locationArray[blockNum] = std::make_pair(nextX, nextY);
                }
            }
            break;
        case 3:
            for(int blockNum = 0; blockNum < 5; blockNum++) {
                int nextX;
                int nextY;
                switch (blockNum)
                {
                case 0:
                    nextX = this->_componentBlocks[blockNum]->getXcor();
                    nextY = this->_componentBlocks[blockNum]->getYcor();
                    break;
                case 1:
                    nextX = this->_componentBlocks[blockNum]->getXcor() + 1;
                    nextY = this->_componentBlocks[blockNum]->getYcor() + 1;
                    break;
                case 2:
                    nextX = this->_componentBlocks[blockNum]->getXcor() - 1;
                    nextY = this->_componentBlocks[blockNum]->getYcor() + 1;
                    break;
                case 3:
                    nextX = this->_componentBlocks[blockNum]->getXcor() - 1;
                    nextY = this->_componentBlocks[blockNum]->getYcor() - 1;
                    break;
                case 4:
                    nextX = this->_componentBlocks[blockNum]->getXcor() + 1;
                    nextY = this->_componentBlocks[blockNum]->getYcor() - 1;
                    break;
                }

                if(nextX < 0 || 4 < nextX || nextY < 0 || 11 < nextY) {
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
        for(int blockNum = 0; blockNum < 5; blockNum++) {
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