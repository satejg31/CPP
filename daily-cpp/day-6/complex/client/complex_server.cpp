#include <iostream> 
#include "complex.h" 

double sqrt (double); 

Complex::Complex (double re, double im)
{
	this->re = re; 
	this->im = im; 
}

double Complex::get_real (void) 
{
	return (this->re); 
}

double Complex::get_imaginary (void) 
{	
	return (this->im); 
}

void Complex::set_real (double new_real)
{
	this->re = new_real; 
}

void Complex::set_imaginary (double new_imaginary)
{
	this->im = new_imaginary; 
}

Complex* Complex::add (Complex *other) 
{
	return (new Complex (this->re + other->re, this->im + other->im)); 
}

Complex* Complex::subtract (Complex *other) 
{
	return (new Complex (this->re - other->re, this->im - other->im)); 
}

/*double Complex::magnitude (void) 
{
	return (sqrt (this->re * this->re + this->im * this->im)); 
}*/ 

void Complex::display (void) 
{
	std::cout << "(" << this->re << ")+i(" << this->im << ")" << std::endl; 
}
