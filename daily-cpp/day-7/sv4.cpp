#include <iostream> 
#include <cstdlib> 

int n1 = 5000; 

namespace test
{
	class X
	{
		private: 
			int i_num; 
		public: 
			X(int new_num) : i_num (new_num) {} 
			X() {} 
		static int n; 
	}; 

	int X::n = 500; 
}; 

int main(void) 
{
	std::cout << "test::X::n:" << test::X::n << std::endl; 
	std::cout << "::test::X:n:" << test::X::n << std::endl; 
	std::cout << "X::n" << X::n << std::endl; 
//	std::cout << "::test::X::n1:" << ::test::X::n1 << std::endl; 
	return (EXIT_SUCCESS); 	
}
