#include <iostream>

int data = 9; //0이 아닌 값으로 초기화된 변수를 data 영역에 저장
static int bss; //초기화되지 않은 변수, 정적 변수를 저장
char* rodata = "Hello World!"; //변경되지 않는 상수(문자, 숫자) 발생지

int main() {
	int* code = (int*) &main; //코드가 있는 영역(함수도 포인터가 있음)
	int* heap = new int[1]; //동적 할당 되는 변수들이 저장되는 공간
	int stack = 1; //함수 호출 시(인스턴스) 사용되는 영역

	std::cout << "code\t" << (void*) code <<std::endl;
	std::cout << "Rodata\t" << (void*) rodata << std::endl;
	std::cout << "data\t" << &data << std::endl;
	std::cout << "BSS\t" << &bss << std::endl;
	std::cout << "HEAP\t" << heap << std::endl;
	std::cout << "Stack\t" << &stack << std::endl;
}
