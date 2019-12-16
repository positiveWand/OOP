#include "gameTable.h"
#include "bigBlock.h"
#include "foldBlock.h"
#include "treeBlock.h"
#include "crossBlock.h"

#include <ctime>

int GameTable::_score = 0;
int GameTable::_combo = 0;
bool GameTable::_working = false;
Block* GameTable::_blockArray[WIDTH][HEIGHT];
std::set<ColorGroup*> GameTable::_explodeGroup;
BigBlock* GameTable::_currentBigBlock = nullptr;


// getter
int GameTable::getScore() { return GameTable::_score; }
bool GameTable::getWorking() { return GameTable::_working; }
Block* GameTable::getBlock(int x, int y) { return GameTable::_blockArray[x][y]; }

shared::color GameTable::blockColor(int x, int y) {
    return GameTable::_blockArray[x][y]->getColor();
}

void GameTable::insert(Block* aBlock) {
    GameTable::_blockArray[aBlock->getXcor()][aBlock->getYcor()] = aBlock;
    GameTable::insertExplosion(aBlock->getColorGroup());
}
void GameTable::insert(BigBlock* aGroup) {
    std::vector<Block*> theList = aGroup->getList();

    for(std::vector<Block*>::iterator itr = theList.begin(); itr != theList.end(); itr++) {
        insert(*itr);
    }
}
void GameTable::empty(int x, int y) {
    GameTable::_blockArray[x][y] = new Block(x, y, shared::NONE);
}

void GameTable::startGame() {
    // 게임 테이블 초기화
    for(int x = 0; x < WIDTH; x++) {
        for(int y = 0; y < HEIGHT; y++) {
            GameTable::_blockArray[x][y] = new Block(x, y, shared::NONE);
        }
    }

    // 점수와 콤보 점수 초기화
    GameTable::_score = 0;
    GameTable::_combo = 0;
    GameTable::_working = false;
    GameTable::_currentBigBlock = nullptr;
}

void GameTable::showTable() {
    /*
    for(std::set<ColorGroup*>::iterator itr = _explodeGroup.begin(); itr != _explodeGroup.end(); itr++) {
        ColorGroup* aGroup = *itr;
        std::cout << aGroup->getSetSize() << " ";
        for(std::set<Block*>::iterator iter = aGroup->getSet().begin(); iter != aGroup->getSet().end(); iter++) {
            Block* aBlock = *iter;
            std::cout << "x좌표:" <<aBlock->getXcor() << " y좌표:" << aBlock->getYcor() << " ";
        }
        std::cout << "\n";
    }
    */
    // 점수 출력
    std::cout << "Score : " << _score << std::endl;
    // 게임 보드 출력
    Block* currentBlock;
    for(int y = 0; y < HEIGHT; y++) {
        for(int x = 0; x < WIDTH; x++) {
            currentBlock = GameTable::_blockArray[x][y];

            std::cout << currentBlock->getColor() << "    ";
        }
        std::cout << '\n';
    }
    
    std::cout << "\n";
}

bool GameTable::summonBlock(int type) {
    _combo = 0;
    BigBlock* newBigBlock;
    srand((unsigned int) time(0));

    if(type == 0) {
        if(blockColor(2,0) != shared::NONE || blockColor(2,1) != shared::NONE || blockColor(1,1) != shared::NONE ) {
            return false;
        }
        else {
            int random[3] = {0,0,0};
            for(int i = 0; i < 3; i++) {
                while(random[i] == 0) {
                    random[i] = rand() % 5;
                }
            }
            newBigBlock = new FoldBlock(random[0], random[1], random[2]);
        }
    }
    else if(type == 1) {
        if(blockColor(2,0) != shared::NONE || blockColor(2,1) != shared::NONE || blockColor(2,2) != shared::NONE ) {
            return false;
        }
        else {
            int random[3] = {0,0,0};
            for(int i = 0; i < 3; i++) {
                while(random[i] == 0) {
                    random[i] = rand() % 5;
                }
            }
            newBigBlock = new TreeBlock(random[0], random[1], random[2]);
        }
    }
    else {
        if(blockColor(2,0) != shared::NONE || blockColor(2,1) != shared::NONE || blockColor(1,1) != shared::NONE || blockColor(2,2) != shared::NONE || blockColor(3,1) != shared::NONE) {
            return false;
        }
        else {
            int random[5] = {0,0,0,0,0};
            for(int i = 0; i < 5; i++) {
                while(random[i] == 0) {
                    random[i] = rand() % 5;
                }
            }
            newBigBlock = new CrossBlock(random[0], random[1], random[2], random[3], random[4]);
        }
    }

    insert(newBigBlock);
    GameTable::_currentBigBlock = newBigBlock;
    GameTable::_working = true;
    return true;
}

bool GameTable::execute(char aInput) {
    if(aInput == 'a') { // 좌측 한 칸 "이동"
        _currentBigBlock->left();
        return true;
    }
    else if(aInput == 'd') { // 우측 한 칸 "이동"
        _currentBigBlock->right();
        return true;
    }
    else if(aInput == 's') { // 아래측 한 칸 "이동"
        _currentBigBlock->down();
        return true;
    }
    else if(aInput == 'x') { // 아래측으로 끝까지 "이동"
        _currentBigBlock->downAll();
        GameTable::_working = false;
        return true;
    }
    else if(aInput == 'e') { // "회전"
        if(!_currentBigBlock->rotate())
            std::cout << "회전 불가!!\n";
        return true;
    }
    else if(aInput == 'p') { // 긴급 종료
        return false;
    }

    // 그 외의 입력은 무시(아무 변화없이 다음 입력으로 넘어감)
    return true; 
}

void GameTable::insertExplosion(ColorGroup* aGroup) {
    _explodeGroup.insert(aGroup);
}
void GameTable::removeExplosion(ColorGroup* aGroup) {
    _explodeGroup.erase(aGroup);
}
void GameTable::explosion() {
    for(std::set<ColorGroup*>::iterator itr = _explodeGroup.begin(); itr != _explodeGroup.end(); itr++) {
        ColorGroup* aGroup = *itr;
        //std::cout << "bomb\n";
        if(aGroup->getSetSize() >= 4) {
            //std::cout << "bomb!!\n";
            aGroup->explode();
            removeExplosion(aGroup);
            _combo++;
        }
    }
}

void GameTable::scoreUp(int up) {
    _score += _combo * up;
}