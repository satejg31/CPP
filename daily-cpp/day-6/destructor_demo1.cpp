#include <iostream> 
#include <string> 
#include <cstdlib> 


class TestClass 
{
	public: 
		// Default constructor 
		TestClass () : i_num(0), c_ans('\0'), d_num(0.0) {} 
		// Explicit constructor 
		TestClass (int i_num, char c_ans, double d_num, std::string str) 
		{
			this->i_num = i_num; 
			this->c_ans = c_ans; 
			this->d_num = d_num; 
			this->s_str = str; 
		}
		// Copy constructor 
		TestClass (const TestClass &ref_testclass_obj) 
		{
			this->i_num = ref_testclass_obj.i_num; 
			this->c_ans = ref_testclass_obj.c_ans; 
			this->d_num = ref_testclass_obj.d_num; 
			this->s_str = ref_testclass_obj.s_str; 
		}
		// Destructor
		~TestClass ()
		{
			std::cout << "destructor:In a destructor" << std::endl;
		}
		// Display method 
		void display (void) const 
		{
			std::cout << "display:i_num:" << i_num << std::endl 
				  << "display:c_ans:" << c_ans << std::endl 
				  << "display:d_num:" << d_num << std::endl 
				  << "display:s_str:" << s_str << std::endl; 
		}

	private: 
		int i_num; 
		char c_ans;
		double d_num; 
		std::string s_str; 
}; 

void test_function_one (void); 
void test_function_two (TestClass *ptr_testclass); 
void test_function_three (TestClass &ref_testclass); 

int main (void) 
{
	TestClass t2 (10, 'A', 3.14, std::string ("Hello"));  
	TestClass t3 (20, 'B', 6.28, std::string ("World")); 

	test_function_one (); 
	std::cout << "main:Returned from test_function_one" << std::endl; 

	test_function_two (&t2); 
	std::cout << "main:Returned from test_function_two" << std::endl; 

	test_function_three (t3); 
	std::cout << "main:Returned from test_function_three" << std::endl; 

	std::cout << "main:Last message from main" << std::endl; 

	return (EXIT_SUCCESS); 
}

void test_function_one (void) 
{
	TestClass t1; 

	std::cout << "1:In test_function_one:created TestClass t1" << std::endl; 

	t1.display (); 
	std::cout << "1:Last message from test_function_one" << std::endl; 

	return; 
}

void test_function_two (TestClass *ptr)
{
	std::cout << "2:In test_function_two:receved testclass t2" << std::endl; 
	ptr->display (); 
	std::cout << "2:Last message from test_function_two" << std::endl; 
}

void test_function_three (TestClass &ref) 
{
	std::cout << "3:In test_function_three:received testclass t3" << std::endl; 
	ref.display (); 
	std::cout << "3:Last message from test_function_three" << std::endl; 
}
