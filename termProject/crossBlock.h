#ifndef CROSSBLOCK_H
#define CROSSBLOCK_H

#include <string>
#include <iostream>

#include "shared.h"
#include "bigBlock.h"

class CrossBlock : public BigBlock{
    public:
        //생성자
        CrossBlock(int a, int b, int c, int d, int e);
        bool rotate();

    private:
        int _state; // 0, 1, 2, 3
};

#endif // CROSSBLOCK_H
