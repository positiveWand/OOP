#include <stdio.h>
#include <iostream>
#include <ctime>

int main() {
    char ch = getchar();
    srand((unsigned int) time(0));
    int nRandom0 = rand() % 8;

    printf("%c\n%d\n", ch, nRandom0);
}