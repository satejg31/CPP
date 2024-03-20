#include <iostream> 

namespace X1 
{
	int my_add (int, int); 
}; 

namespace X2
{
	float my_add (float, float); 
}; 

namespace X3
{
	int my_add (int, int); 
}; 

int main (void) 
{
	//using X1::my_add; 
	//.using X2::my_add; 
	//using X3::my_add; 
	// Remove above comments to import my_add from 
	// X1, X2 and X3, and observer ambiguity error 
	// from compiler 
	std::cout << X1::my_add (10, 20) << std::endl; 
	std::cout << X2::my_add (10.10f, 20.20f) << std::endl; 
	std::cout << X3::my_add (100, 200) << std::endl; 
	return 0; 
}


int X1::my_add (int n1, int n2) 
{
	std::cout << "in X1::my_add" << std::endl; 
	return (n1+n2); 
}

float X2::my_add (float f1, float f2) 
{
	std::cout << "in X2::my_add" << std::endl; 
	return (f1+f2); 
}

int X3::my_add (int n1, int n2) 
{
	std::cout << "in X3::my_add" << std::endl; 
	return (n1 + n2); 
}
