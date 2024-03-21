#include <iostream> 
#include <cstdlib> 

class TestClass 
{
	public: 
		// Default constructor 
		TestClass () : i_num (0), c_ans ('\0'), d_num (0.0) {} 
		
		// Explicit initialization 
		TestClass (int i_num, char c_ans, double d_num) 
		{
			this->i_num = i_num; 
			this->c_ans = c_ans; 
			this->d_num = d_num; 
		}

	/* Copy constructor in explicit manner 
	   TestClass(const TestClass &ref_testclass_obj)
		{
			this->i_num = ref_testclass_obj.i_num; 
			this->c_ans = ref_testclass_obj.c_ans; 
			this->d_num = ref_testclass_obj.d_num; 
		}
	*/ 

		// Copy constructor : constructor initializer list 
		// approach  
		TestClass (const TestClass &ref_testclass_obj) : 
			   i_num (ref_testclass_obj.i_num), 
			   c_ans (ref_testclass_obj.c_ans), 
			   d_num (ref_testclass_obj.d_num) 
		{
			std::cout << "Inside copy constructor" << std::endl; 
		}

		int get_int (void) const; 
		char get_char (void) const;
		double get_double (void) const; 
		void set_int (int new_int); 
		void set_char (char new_char); 
		void set_double (double new_double); 
		void display (void) const; 

	private: 
		int i_num; 
		char c_ans; 
		double d_num; 
}; 

int TestClass::get_int (void) const 
{
	return (this->i_num); 
}

char TestClass::get_char (void) const 
{
	return (this->c_ans); 
}

double TestClass::get_double (void) const 
{
	return (this->d_num); 
}

void TestClass::set_int (int new_num) 
{
	this->i_num = new_num; 
}

void TestClass::set_char (char new_char) 
{
	this->c_ans = new_char; 
}

void TestClass::set_double (double new_double) 
{
	this->d_num = new_double; 
}

void TestClass::display (void) const 
{
	std::cout << "i_num:" << i_num << std::endl 
		  << "c_ans:" << c_ans << std::endl 
		  << "d_num:" << d_num << std::endl; 
}

int main (void) 
{
	TestClass t1 (10, 'A', 3.14); 
	TestClass t2 = t1; 
	TestClass t3 (t1); 
	std::cout << "Displaying t2:" << std::endl;
	t2.display (); 
	std::cout << "Displaying t3:" << std::endl; 
	t3.display (); 

	std::cout << "Address(t1):" << std::hex << &t1 << std::endl 
			  << "Address(t2):" << std::hex << &t2 << std::endl 
			  << "Address(t3):" << std::hex << &t3 << std::endl; 

	return (0); 
}
