#include <iostream>

int data = 9;
static int bss;
char* rodata = "Hello World!";

int main() {
	int* code = (int*) &main;
	int* heap = new int[1];
	int stack = 1;

	std::cout << "code\t" << (void*) code <<std::endl;
	std::cout << "Rodata\t" << (void*) rodata << std::endl;
	std::cout << "data\t" << &data << std::endl;
	std::cout << "BSS\t" << &bss << std::endl;
	std::cout << "HEAP\t" << heap << std::endl;
	std::cout << "Stack\t" << &stack << std::endl;
}
