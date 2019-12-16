#ifndef TREEBLOCK_H
#define TREEBLOCK_H

#include <string>
#include <iostream>

#include "shared.h"
#include "bigBlock.h"

class TreeBlock : public BigBlock{
    public:
        //생성자
        TreeBlock(int a, int b, int c);
        bool rotate();

    private:
        int _state; // 0, 1, 2, 3
};

#endif // TREEBLOCK_H
