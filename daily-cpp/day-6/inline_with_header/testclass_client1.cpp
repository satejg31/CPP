#include <iostream> 
#include "testclass.h" 

TestClass t1(10, 'A', 40.50); 
TestClass t2; 

int main (void) 
{
	TestClass t3(20, 'B', 54.3); 

	std::cout << "Before:t1:" << std::endl; 
	t1.display (); 

	std::cout << "Before:t3:" << std::endl; 
	t3.display (); 

	std::cout << "Before:t2:" << std::endl; 
	t2.display (); 

	t2.set_integer (1000); 
	t2.set_char ('Z'); 
	t2.set_float (5.654); 

	std::cout << "Display:t1:" << std::endl; 
	std::cout << "Integer:" << t1.get_integer () << std::endl 
		  << "Character:" << t1.get_char () << std::endl 
		  << "Floating:" << t1.get_float () << std::endl; 

	std::cout << "Display:t2:" << std::endl; 
	t2.display (); 

	std::cout << "Display:t3:" << std::endl; 
	t3.display (); 

	return 0; 	
}
