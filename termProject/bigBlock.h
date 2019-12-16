#ifndef BIGBLOCK_H
#define BIGBLOCK_H

#include <string>
#include <iostream>
#include <vector>

#include "block.h"

class BigBlock {
    public:
        //생성자, 소멸자

        std::vector<Block*> getList();

        virtual bool rotate() = 0;

        bool canLeft();
        bool canRight();
        bool canDown();

        void left();
        void right();
        void down();
        void downAll();

    protected:
        std::vector<Block*> _componentBlocks; 
};

#endif // BIGBLOCK_H
