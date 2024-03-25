#include <iostream> 
#include "complex.h" 

int main (void) 
{
	Complex *c1, *c2, *sum, *sub; 

	c1 = new Complex (10.10, 20.20); 
	c2 = new Complex (30.30, 40.40); 

	sum = c1->add (c2); 
	sub = c1->subtract (c2); 

	std::cout << "c1:"; 
	c1->display (); 

	std::cout << "c2:"; 
	c2->display (); 

	std::cout << "sum:"; 
	sum->display (); 

	std::cout << "sub:"; 
	sub->display (); 

	return 0; 
}
