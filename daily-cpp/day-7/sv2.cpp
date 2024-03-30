#include <iostream> 
#include <cstdlib> 

class A{
	
	public:
		A(int new_n) : n(new_n) {} 
		A() {} 
		~A() {std::cout << "In A's destructor" << std::endl;} 

	private:
			int n; 
}; 

int main(void) 
{
	for(int i=0; i < 10; i++){
		A inA(500); 
		std::cout << "In loop for " << i << "th time" << std::endl; 
	}

	return EXIT_SUCCESS; 
}
