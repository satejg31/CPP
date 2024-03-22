#include <iostream>
#include <cstdio>  
#include <cstdlib> 

class IntPtr 
{
private: 
	friend class HasPtr; 
	int *ptr; 
	int usage_count; 
	IntPtr (int *p) : ptr (p), usage_count (1) {} 
	~IntPtr () 
	{	
		std::cout << "In destructor of IntPtr" << std::endl; 
		delete ptr; 
	}
}; 

class HasPtr 
{
public:
	HasPtr (int *p, int i) : iptr (new IntPtr (p)), val (i) {} 
	
	HasPtr (const HasPtr &ref) : val (ref.val), iptr (ref.iptr) 
	{
		std::cout << "In copy constructor of HasPtr" << std::endl; 
		++iptr->usage_count; 
	}

	~HasPtr () 
	{
		std::cout << "In destructor of HasPtr" << std::endl; 
		std::cout << "Reference count just before decrement " << iptr->usage_count << std::endl; 
		if (--iptr->usage_count == 0)
			delete iptr; 
	}

	HasPtr &operator= (const HasPtr &ref)
	{
		++ref.iptr->usage_count;
		if (--(this->iptr->usage_count) == 0)
		{
			delete this->iptr; 
		}
		this->val = ref.val; 
		this->iptr = ref.iptr; 

		return *this; 
	}

	int get_usage_count (void) const 
	{
		return (this->iptr->usage_count);
	}
	
private: 
	int val; 
	IntPtr *iptr; 
}; 

int main (void)
{
	int *pint1 = new int (10000); 
	int *pint2 = new int (20000); 
	HasPtr p1 (pint1, 10);
	std::cout << "p1.get_usage_count ():" << p1.get_usage_count () << std::endl; 
	HasPtr p2 (p1);
	std::cout << "p2.get_usage_count ():" << p2.get_usage_count () << std::endl; 
	HasPtr p3 (p1);
	std::cout << "p3.get_usage_count ():" << p3.get_usage_count () << std::endl; 
	HasPtr p4 (pint2, 20);
	std::cout << "p4.get_usage_count():" << p4.get_usage_count() << std::endl;
	p4 = p3; 
	std::cout << "p4.get_usage_count ():" << p4.get_usage_count () << std::endl; 
	return (EXIT_SUCCESS); 
}
