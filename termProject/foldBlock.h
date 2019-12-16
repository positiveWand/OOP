#ifndef FOLDBLOCK_H
#define FOLDBLOCK_H

#include <string>
#include <iostream>

#include "shared.h"
#include "bigBlock.h"

class FoldBlock : public BigBlock{
    public:
        //생성자
        FoldBlock(int a, int b, int c);
        bool rotate();
    
    private:
        int _state; // 0, 1, 2, 3
};

#endif // FOLDBLOCK_H
