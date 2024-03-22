#include <iostream> 
#include <cstdlib> 

class HasPtr 
{
	public:
		HasPtr (int v, int *p) : val (v), ptr (p) {} 

		int get_val (void) const 
		{
			return (val);

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

		void set_ptr_val (int new_ptr_val)
		{
			*ptr = new_ptr_val; 
		}
	private: 
		int val; 
		int *ptr; 
}; 

int main (void) 
{
	int *p = new int (10); 
	HasPtr p1 (42, p); 
	HasPtr p2 (p1); 

	std::cout << "p1.val:" << p1.get_val () << std::endl; 
	p1.set_val (4200); 
	std::cout << "p1.val:" << p1.get_val () << std::endl; 

	//delete p; // Ideally segfault is expected, but may not get 
	//because the page may still be mapped in virtual address space
	// but will not get value 10 as expected. 

	std::cout << "p1.get_ptr_val:" << p1.get_ptr_val () << std::endl; 
	std::cout << "p2.get_ptr_val:" << p2.get_ptr_val () << std::endl; 
	// Change ptr_val through p1 and read through p2. 
	p1.set_ptr_val (100); 
	std::cout << "p2.get_ptr_val:" << p2.get_ptr_val () << std::endl; 

	return (0); 
}
