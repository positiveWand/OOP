#include <stdio.h>
#include <iostream>
#include <ctime>

#include "gameTable.h"

int main() {
    //맵 객체 생성

    bool wantGame;
    bool gameOver;
    bool working;
    bool exit;
    char gameInput;
    char restartReply;
    int nRandom;

    wantGame = true;
    gameOver = false;
    exit = false;

    std::cout << "<<누군가의 뿌요 뿌요>>\n" << std::endl;

    while(wantGame) {
        //"뿌요뿌요" 게임 루프 시작
        std::cout << "게임 시작 !!\n" << std::endl;
        GameTable::startGame(); // 게임 테이블 초기화
        // 블럭 생성
        srand((unsigned int) time(0));
        nRandom = rand() % 3;
        gameOver = !GameTable::summonBlock(nRandom);
        working = GameTable::getWorking();
        
        while(!gameOver) {
            while(working) {
                // 게임 보드 show
                GameTable::showTable();
                // 유저 입력
                while(1) {
                    gameInput = getchar();
                    if(gameInput != '\n')
                        break;
                }
                GameTable::execute(gameInput);
                working = GameTable::getWorking();
            }
            GameTable::explosion();
            // 블럭 생성
            nRandom = rand() % 3;
            gameOver = !GameTable::summonBlock(nRandom);
            working = GameTable::getWorking();
        }
        //(게임)루프 종료

        //재도전 여부 묻기
        std::cout << "게임 오버 !!\n" << std::endl;
        std::cout << "다시 도전? [y/n] : ";
        while(1) {
            restartReply = getchar();
            if(restartReply != '\n')
                break;
        }
        if(restartReply == 'y' || restartReply == 'Y') { //재도전
            wantGame = true;
            gameOver = false;
            continue;
        }
        else{ //그만두기
            wantGame = false;
        }
    }

    //프로그램 종료
    std::cout << "게임을 종료하겠습니다. 다음에 또 오세요 ~\n" << std::endl;
    return 0;
}