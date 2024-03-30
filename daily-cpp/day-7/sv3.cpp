#include <iostream> 
#include <cstdlib> 

namespace X 
{
	namespace Y
	{
		int n = 100; 
	}; 
}; 

int main(void) 
{
	//std::cout << "n:" << n << std::endl; // compile time error 
	//std::cout << "Y::n:" << Y::n << std::endl; // compile time error 
	std::cout << "X::Y::n:" << X::Y::n << std::endl; // will work 
	std::cout << "::X::Y::n:" << ::X::Y::n << std::endl; // will save lookup for X

	return EXIT_SUCCESS; 
}
