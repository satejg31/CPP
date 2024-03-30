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
	using ::X::Y::n; 

	std::cout << "n:" << n << std::endl; 

	return EXIT_SUCCESS; 
}
