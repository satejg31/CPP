#include <iostream> 
#include <cstdlib> 

class TestClass 
{
	public: 
		TestClass () : i_num (0), c_ans ('\0'), d_num (0.0) {} 
		
		TestClass (std::string &str, int i_num, char c_ans, double d_num) 
		{
			std::cout << "Here" << std::endl; 
			this->i_num = i_num; 
			this->c_ans = c_ans; 
			this->d_num = d_num; 
			this->str   = str; 
		}

		TestClass& operator=(const TestClass &ref_testclass_obj) 
		{
			this->str   = ref_testclass_obj.str; 
			this->i_num = ref_testclass_obj.i_num; 
			this->c_ans = ref_testclass_obj.c_ans; 
			this->d_num = ref_testclass_obj.d_num; 
			return *this; 
		}
		  		  
		std::string get_string (void) const; 
		int get_int (void) const; 
		char get_char (void) const; 
		double get_double (void) const; 
		void set_string (std::string &new_string); 
		void set_int (int new_int); 
		void set_char (char new_char); 
		void set_double (double new_double); 
		void display (void) const; 

	private:
		std::string str; 
		int i_num; 
		char c_ans; 
		double d_num; 
}; 

std::string TestClass::get_string (void) const 
{
	return (this->str); 
}

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

void TestClass::set_string (std::string &new_string) 
{
	this->str = new_string; 
}

void TestClass::set_int (int new_int) 
{
	this->i_num = new_int; 
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
	std::cout << "str:" << this->str << std::endl
	 	  << "i_num:" << this->i_num << std::endl 
		  << "c_ans:" << this->c_ans << std::endl 
		  << "d_num:" << this->d_num << std::endl; 
}

int main (void) 
{
	std::string s1 ("Hello");
	TestClass t1 (s1, 10, 'A', 3.14); 
	TestClass t2 = t1; 
	TestClass t3 (t1); 
	TestClass t4; 

	std::cout << "Displaying t2:" << std::endl; 
	t2.display (); 

	std::cout << "Displaying t3:" << std::endl; 
	t3.display (); 
	 
	std::cout << "Displaying t4:" << std::endl; 
	t4.display (); 

	t4 = t2; 

	std::cout << "Displaying t4:" << std::endl; 
	t4.display (); 

	exit (EXIT_SUCCESS); 
}
