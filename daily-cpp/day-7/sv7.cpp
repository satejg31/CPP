#include <iostream> 
#include <cstdlib> 

namespace X 
{
	namespace Y
	{
		int n = 100; 
		int m = 500; 
	}; 
}; 

int main(void) 
{
	using namespace X::Y; 

	std::cout << "m:" << m << "n:" << n << std::endl; 

	return EXIT_SUCCESS; 
}
