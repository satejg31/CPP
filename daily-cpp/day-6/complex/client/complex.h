#ifndef _COMPLEX_H 
#define _COMPLEX_H 

class Complex 
{
	public: 
		Complex (); 
		Complex (double, double); 
		double get_real (void); 
		double get_imaginary (void); 
		void set_real (double); 
		void set_imaginary (double); 
		Complex *add (Complex*); 
		Complex *subtract (Complex*); 
		double magnitude (void); 
		void display (void); 
	private:
		double re, im; 
}; 

#endif /* _COMPLEX_H */ 
