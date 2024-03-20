#include <iostream> 

namespace X{
	int i_num = 10; 
	int my_add(int n1, int n2){
		return n1 + n2;
	}
}; 

namespace Y{
	int n = 100; 
	int my_sub(int n1, int n2){
		return (n1-n2); 
	}
}; 

namespace Z{
	int k = 200; 
	int my_mul(int n1, int n2){
		return (n1 * n2); 
	}
}; 

int main(void)
{
	int result; 
	using namespace Y; 

	std::cout << "X::i_num:" << X::i_num << std::endl; 
	result = X::my_add(100, 200); 
	std::cout << "result:" << result << std::endl; 
	
	std::cout << "n:" << n << std::endl; 
	result = my_sub(200, 100); 
	std::cout << "result:" << result << std::endl; 

	using Z::k; 
	
	std::cout << "k:" << k << std::endl; 
	result = Z::my_mul(100, 5); 
	std::cout << "result:" << result << std::endl; 

	return (0); 
}
