// Code with subtle memory leak! 
#include <iostream> 
#include <cstdio> 
#include <cstdlib> 

class IntClass 
{
public:
	// Explicit constructor 1 
	IntClass () : iptr (new int (0)) 
	{
		std::cout << "In explicit constructor one" << std::endl; 
	}
	// Explicit constructor 2 
	IntClass (int new_val) : iptr (new int (new_val)) {} 
	// Copy constructor 
	IntClass (const IntClass &ref) 
	{
		this->iptr = new int (*(ref.iptr));
	}
	// Destructor
	~IntClass ()
	{
		printf ("In destructor:Address (this):%p\n", this);
		printf ("In destructor:Address (iptr):%p\n", iptr);
		delete iptr; 
	}
	// Overloaded assignment 
	IntClass &operator= (const IntClass &ref)
	{
		std::cout << "In overloaded assignment operator" << std::endl; 
		*(this->iptr) = *(ref.iptr);
		return (*this);
	}
	// Overloaded addition
	IntClass &operator+ (const IntClass &ref)
	{
		std::cout << "In overloaded addition operator" << std::endl; 
		IntClass *ptr = new IntClass (*(this->iptr) + *(ref.iptr));
		std::cout << "ptr:" << ptr << "ptr->iptr:" << ptr->iptr << std::endl; 
		return (*ptr);
	}
	// Overloaded subtraction 
	IntClass &operator- (const IntClass &ref)
	{
		std::cout << "In overloaded subtraction operator" << std::endl; 
		IntClass *ptr = new IntClass (*(this->iptr) - *(ref.iptr)); 
		return (*ptr); 
	}
	// Overloaded multiplication 
	IntClass &operator* (const IntClass &ref)
	{
		std::cout << "In overloaded multiplication operator" << std::endl; 
		return *(new IntClass (*(this->iptr) * *(ref.iptr))); 
	}
	// Overloaded integer division 
	IntClass &operator/ (const IntClass &ref)
	{
		std::cout << "In overloaded division operator" << std::endl; 
		if (*(ref.iptr) != 0)
		{
			return *(new IntClass (*(this->iptr) / *(ref.iptr))); 
		}
	}
	// Overloaded modulus operator 
	IntClass &operator% (const IntClass &ref)
	{
		std::cout << "In overloaded modulus operator" << std::endl; 
		if (*(ref.iptr) != 0)
		{
			return *(new IntClass (*(this->iptr) % *(ref.iptr))); 
		}
	}

	inline int *addr (void) const {return (iptr);}
	inline int get_val (void) const {return (*iptr);}
private:
	int *iptr; 
}; 

int main (void)
{
	IntClass n1(10), n2(20); 
	IntClass *pint1 = new IntClass ();
	std::cout << "pint1->get_val ():" << pint1->get_val () << std::endl; 
	printf ("Address(n1.iptr):%p Address(n2.iptr):%p Address(pint1->iptr):%p\n", 
			n1.addr (), n2.addr (), pint1->addr ()); 
	delete pint1; 
	IntClass sum = n1 + n2; 
	std::cout << "sum.addr ():" << sum.addr () << " sum.get_val ():" << sum.get_val () << std::endl; 
	IntClass sub = n1 - n2; 
	std::cout << "sub.addr ():" << sub.addr () << " sub.get_val ():" << sub.get_val () << std::endl; 
	IntClass mul = n1 * n2; 
	std::cout << "mul.addr ():" << mul.addr () << " mul.get_val ():" << mul.get_val () << std::endl; 
	IntClass division, modulus; 
	std::cout << "division.addr ():" << division.addr () << " division.get_val ():" 
			  << division.get_val () << std::endl; 
	division = n1 + n2;  
	std::cout << "division.addr ():" << division.addr () << " division.get_val ():" 
			  << division.get_val () << std::endl; 

	return (EXIT_SUCCESS); 
}