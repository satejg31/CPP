#include <iostream> 
#include <cstdio> 
#include <cstdlib> 

class HasPtr 
{
public:
	// Default constructor 
	HasPtr () {} 
	// Explicit constructor with initializer list approach 
	HasPtr (int new_val, int *new_ptr) : val (new_val), ptr (new_ptr) {} 
	// Copy constructor 
	HasPtr (const HasPtr &ref) 
	{
		val = ref.val; 
		ptr = new int (ref.get_ptr_val ()); 
	}
	// Overloaded assignment operator definition 
	HasPtr &operator=(HasPtr &other)
	{
		val = other.val; 
		if(other.ptr && ptr)
			*ptr = *(other.ptr); 
	}
	// Destructor 
	~HasPtr ()
	{
		printf ("In destructor : address of this : %p\n", this); 
		delete ptr; 
	}
	int get_val (void) const 
	{
		return val; 
	}
	void set_val (int new_val) 
	{
		val = new_val; 
	}
	int *get_ptr (void) const 
	{
		return (ptr); 
	}
	void set_ptr (int *new_ptr) 
	{
		ptr = new_ptr; 
	}
	int get_ptr_val (void) const 
	{
		return (*ptr); 
	}
	void set_ptr_val (int new_val) 
	{
		*ptr = new_val; 
	}
private:
	int val; 
	int *ptr; 
}; 

HasPtr *test_function (void); 

int main (void)
{
	HasPtr *p = test_function (); 
	std::cout << "Back to main" << std::endl; 
	delete p;
	return (EXIT_SUCCESS);
}

HasPtr *test_function (void)
{
	int *pint = new int (10); 
	HasPtr p1 (100, pint); 
	// Constructing p2 from p1 but as we've implemented value like 
	// behaviour in copy constructor value of get_ptr should be 
	// different for p1 and p2
	HasPtr p2 (p1);
	HasPtr *p = new HasPtr (p2); 
	printf ("Address of p1:%p, Address of p2:%p, Address of p:%p\n", &p1, &p2, p);

	// Should get same value for p1.val and p2.val 
	std::cout << "p1.val:" << p1.get_val () << std::endl 
			  << "p2.val:" << p2.get_val () << std::endl; 
	// Should get same values for p1.get_ptr_val and 
	// p2.get_ptr_val 
	std::cout << "p1.get_ptr_val:" << p1.get_ptr_val () << std::endl
			  << "p2.get_ptr_val:" << p2.get_ptr_val () << std::endl; 
	// Should get different values for p1.ptr and p2.ptr 
	printf ("p1.ptr:%p p2.ptr:%p\n", p1.get_ptr (), p2.get_ptr ());

	return (p); 
}
