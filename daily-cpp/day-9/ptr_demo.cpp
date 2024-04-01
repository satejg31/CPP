#include <iostream>

struct A {
	int a; 
	char b; 
	float c; 
}; 

struct A inA; 

int main(void)
{
	struct A *pA = &inA; 
	float *pF = &inA.c; 
	std::cout << "DIFF:" << reinterpret_cast<unsigned long int>(&inA.c) - reinterpret_cast<unsigned long int>(&inA) 
			<< std::endl; 

	return 0; 
}