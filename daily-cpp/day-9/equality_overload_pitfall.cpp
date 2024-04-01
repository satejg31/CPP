#include <iostream> 
#include <cstdlib> 

class Complex
{
private: 
	double re, im; 
public: 
	Complex() : re(0.0), im(0.0) {} 
	Complex(double in_re, double in_im) : re(in_re), im(in_im) {} 

	bool operator==(Complex *other) 
	{
		return ((this->re == other->re) && (this->im == other->im)); 
	}

	bool operator!=(Complex &other)
	{
		return ((this->re != other.re) || (this->im != other.im));
	}

	Complex &operator*()
	{
		return (*this); 
	}

	void dump(void)const 
	{
		std::cout << "(" << re << ")+i(" << im << ")" << std::endl; 
	}
}; 

int main(void)
{
	Complex *c1 = new Complex(10.5, 20.5); 
	Complex c2(*c1); 
	Complex &ref = c2; 
	c1->dump(); 
	c2.dump();
	//std::cout << c2 << std::endl; 
	Complex c3(1.1,2.2); 
	Complex c4(c3); 
/*
	if(*c1 == ref)
	{
		std::cout << "c1 IS EQUAL TO c2" << std::endl; 
	}
	else if(*c1 != ref)
	{
		std::cout << "c1 IS NOT EQUAL TO c2" << std::endl; 
	}

	if(c3 == c4)
	{
		std::cout << "c3 and c4 are equal" << std::endl; 
	}

	delete c1; 
	delete c2; 
*/ 
	Complex *c5 = new Complex(100.5, 200.5); 
   	Complex *c6 = new Complex(*c5); 	
	
	std::cout << "c5->dump():" << std::endl; 
	c5->dump(); 
	std::cout << "c6->dump():" << std::endl; 
	c6->dump(); 

	if(c5 == c6){
		std::cout << "c5 and c6 are equal" << std::endl; 
	}
	else{
		std::cout << "c5 and c6 are not equal" << std::endl; 
	}

	return (EXIT_SUCCESS); 
}
