#include <iostream> 
#include <cstdlib> 

class X 
{
	private:
		int num; 
	public: 
		X(int new_num) : num (new_num) {} 
		X() {} 
		~X() {} 
		static int s_num; 
}; 

int X::s_num = 400; 

class Y 
{
	private:
		double d_num; 
	public: 
		Y (double new_double) : d_num (new_double) {} 
		double get_num(void) const
		{
			std::cout << "d_num:" << d_num << std::endl; 
			std::cout << "::X::s_num:" << ::X::s_num << std::endl; 
		}

		static void test_static_Y(void) 
		{
			std::cout << "::X::s_num:" << ::X::s_num << std::endl; 
		}
}; 

int main(void) 
{
	Y inY(2.14); 

	inY.get_num(); 
	Y::test_static_Y(); 
}
