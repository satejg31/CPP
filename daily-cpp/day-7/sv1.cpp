#include <iostream> 
#include <cstdlib> 

int x=10; 

int main(void) 
{
	int x=100; 

	for(int i=0; i < 5; i++){
		int x = 1000; 
		for(int j=0; j < 5; j++){
			int x = 10000; 
			std::cout << x << std::endl; 
			std::cout << ::x << std::endl; 
		}
	}

	return EXIT_SUCCESS; 
}
