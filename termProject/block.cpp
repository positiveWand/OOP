#include "block.h"
#include "colorGroup.h"
#include "gameTable.h"

#include <set>

//생성자
Block::Block() {
    this->_blockColor = shared::NONE;
    this->_xCor = -1;
    this->_yCor = -1;
    this->_colorGroup = new ColorGroup(shared::NONE);
    this->_colorGroup->getSet().insert(this);
}
Block::Block(int x, int y, shared::color aColor) {
    this->_blockColor = aColor;
    this->_xCor = x;
    this->_yCor = y;
    this->_colorGroup = new ColorGroup(this);
}

//소멸자
Block::~Block() {

}

//getter
shared::color Block::getColor() { return this->_blockColor; }
int Block::getXcor() { return this->_xCor; }
int Block::getYcor() { return this->_yCor; }
ColorGroup* Block::getColorGroup() { return this->_colorGroup; }

//setter
void Block::setColor(shared::color aColor) { this->_blockColor =  aColor; }
void Block::setCordinate(int xCor, int yCor) { this->_xCor = xCor; this->_yCor = yCor; }
void Block::setColorGroup(ColorGroup* aGroup) { this->_colorGroup = aGroup; }


bool Block::canLeft() {
    int nextXcor = this->_xCor - 1;

    if(0 <= nextXcor && nextXcor <= GameTable::WIDTH-1) {
        if(GameTable::blockColor(nextXcor, this->_yCor) == shared::NONE)
            return true;
    }

    return false;
}
bool Block::canRight() {
    int nextXcor = this->_xCor + 1;

    if(0 <= nextXcor && nextXcor <= GameTable::WIDTH-1) {
        if(GameTable::blockColor(nextXcor, this->_yCor) == shared::NONE)
            return true;
    }

    return false;
}
bool Block::canDown() {
    int nextYcor = this->_yCor + 1;

    if(0 <= nextYcor && nextYcor <= GameTable::HEIGHT-1) {
        if(GameTable::blockColor(this->_xCor, nextYcor) == shared::NONE)
            return true;
    }

    return false;
}

void Block::left() {
    if(this->canLeft()) {
        GameTable::empty(_xCor, _yCor);

        this->_xCor = this->_xCor - 1;
        GameTable::insert(this);
    }
}
void Block::right() {
    if(this->canRight()) {
        GameTable::empty(_xCor, _yCor);

        this->_xCor = this->_xCor + 1;
        GameTable::insert(this);
    }
}
void Block::down() {
    if(this->canDown()) {
        //std::cout << "how many?\n";
        GameTable::empty(_xCor, _yCor);

        this->_yCor = this->_yCor + 1;
        GameTable::insert(this);
    }
}
void Block::downAll() {
    // 끝까지 아래로
    while(canDown()) {
        down();
    }

    // 합칠 수 있는 Block있는지 확인 후 있다면 합체
    findAndMerge();
}

void Block::findAndMerge() {
    int surroundX;
    int surroundY;
    Block* aSurroundBlock;

    for(int i = 0; i < 4; i++) {
        switch (i)
        {
        case 0:
            surroundX = _xCor + 1;
            surroundY = _yCor;
            break;
        case 1:
            surroundX = _xCor;
            surroundY = _yCor + 1;
            break;
        case 2:
            surroundX = _xCor - 1;
            surroundY = _yCor;
            break;
        case 3:
            surroundX = _xCor;
            surroundY = _yCor - 1;
            break;
        }

        if(0 <= surroundX && surroundX <= 4 && 0 <= surroundY && surroundY <= 11){
            aSurroundBlock = GameTable::getBlock(surroundX, surroundY);
            if(aSurroundBlock->getColor() != shared::NONE && aSurroundBlock->getColor() == this->_blockColor) {
                this->merge(aSurroundBlock);
            }
        }
    }
}

void Block::merge(Block* aBlock) {
    //std::cout << aBlock->getXcor() << "xy" << aBlock->getYcor() << std::endl;
    this->_colorGroup->insert(aBlock->getColorGroup()->getSet());
    aBlock->setColorGroup(this->_colorGroup);
}

void Block::explode() {
    int surroundX;
    int surroundY;
    Block* aSurroundBlock;

    for(int i = 0; i < 4; i++) {
        switch (i)
        {
        case 0:
            surroundX = _xCor + 1;
            surroundY = _yCor;
            break;
        case 1:
            surroundX = _xCor;
            surroundY = _yCor + 1;
            break;
        case 2:
            surroundX = _xCor - 1;
            surroundY = _yCor;
            break;
        case 3:
            surroundX = _xCor;
            surroundY = _yCor - 1;
            break;
        }
        if(0 <= surroundX && surroundX <= 4 && 0 <= surroundY && surroundY <= 11){
            aSurroundBlock = GameTable::getBlock(surroundX, surroundY);
            if(aSurroundBlock->getColor() == shared::GRAY) {
                aSurroundBlock->explode();
            }
        }
    }

    GameTable::empty(_xCor, _yCor);
    //GameTable::showTable();
}