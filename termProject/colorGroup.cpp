#include "colorGroup.h"
#include "block.h"
#include "gameTable.h"

// 생성자
ColorGroup::ColorGroup() {
    this->_groupColor = shared::NONE;
    std::set<Block*> _blocks;
}
ColorGroup::ColorGroup(shared::color aColor) {
    this->_groupColor = aColor;
    std::set<Block*> _blocks;
}
ColorGroup::ColorGroup(Block* aBlock) {
    this->_groupColor = aBlock->getColor();
    _blocks.insert(aBlock);
}
// 소멸자
ColorGroup::~ColorGroup() {

}

// getter
shared::color ColorGroup::getColor() { return this->_groupColor; }
std::set<Block*> ColorGroup::getSet() { return this->_blocks; }
int ColorGroup::getSetSize() { return this->_blocks.size(); }

// setter
void ColorGroup::setColor(shared::color aColor) { this->_groupColor = aColor; }

void ColorGroup::insert(std::set<Block*> aSet) {
    for(std::set<Block*>::iterator itr = aSet.begin(); itr != aSet.end(); itr++) {
        this->_blocks.insert(*itr);
    }
}
void ColorGroup::explode() {
    for(std::set<Block*>::iterator itr = _blocks.begin(); itr != _blocks.end(); itr++) {
        Block* currentBlock = *itr;
        currentBlock->explode();
    }
    GameTable::scoreUp(1);
}