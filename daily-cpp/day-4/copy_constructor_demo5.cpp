#include <iostream> 
#include <cstdlib> 

class TestClass 
{
	public: 
		// Default constructor 
		TestClass () : i_num(0), c_ans('\0'), p_num(0) {} 
		// Explicit constructor
		TestClass (int i_num, char c_ans, int ptr_val) 
		{
			this->i_num = i_num; 
			this->c_ans = c_ans; 
			this->p_num = new int (ptr_val); 
		}
		// Copy constructor 
		TestClass (const TestClass &t_ptr) 
		{
			this->i_num = t_ptr.i_num; 
			this->c_ans = t_ptr.c_ans; 
			this->p_num = t_ptr.p_num; 
		}
		// Default destructor 
		~TestClass () {} 
		int get_int (void) const; 
		char get_char (void) const; 
		int get_ptr_val (void) const; 
		int *get_ptr (void) const; 
		void set_int (int new_int);  
		void set_char (char new_char); 
		void set_ptr_val (int new_ptr_val); 
		void set_ptr (int *new_ptr); 
		void free_ptr (void); 
		void display (void) const; 			
	private:
		int i_num; 
		char c_ans; 
		int *p_num; 
}; 

int TestClass::get_int (void) const 
{
	return (i_num); 
}

char TestClass::get_char (void) const 
{
	return (c_ans); 
}

int TestClass::get_ptr_val (void) const 
{
	return (*p_num); 
}

int *TestClass::get_ptr (void) const 
{
	return (this->p_num); 
}

void TestClass::set_int (int new_int) 
{
	this->i_num = new_int; 
}

void TestClass::set_char (char new_char) 
{
	this->c_ans = new_char; 
}

void TestClass::set_ptr_val (int new_ptr_val) 
{
	*p_num = new_ptr_val; 
}

void TestClass::set_ptr (int *new_ptr) 
{
	this->p_num = new_ptr; 
}

void TestClass::free_ptr (void) 
{
	free (p_num); 
}

void TestClass::display (void) const 
{
	std::cout << "i_num:" << i_num << std::endl 
		  << "c_ans:" << c_ans << std::endl 
		  << "ptr_val:" << *p_num << std::endl
		  << "ptr:" << p_num << std::endl;  
}

int main (void) 
{
	int *ptr; 
	TestClass t1 (100, 'A', 1000); 
	TestClass t2 (t1); 

	std::cout << "Displaying t1:" << std::endl; 
	t1.display (); 
	
	std::cout << "Displaying t2:" << std::endl; 
	t2.display (); 

/*	TestClass *t3 = new TestClass (100, 'A', 1000); 
	std::cout << "Displaying t3:" << std::endl; 
	t3->display (); 
	ptr = t3->get_ptr (); 
	delete t3; */ 

	// Pointer pitfall 
	t1.free_ptr (); 
	t2.set_ptr_val (10000); 

	return (EXIT_SUCCESS); 
}
