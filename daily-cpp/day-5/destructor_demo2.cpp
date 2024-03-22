#include <iostream> 
#include <string> 
#include <cstdio> 
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
			printf ("In the destructor:this:%p\n", this); 
		}
		// Display method 
		void display (void) const 
		{
			printf ("display:this:%p\n", this); 
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

void test_function_one (TestClass *ptr_testclass); 

int main (void) 
{
	TestClass *ptr_t1  = new TestClass(10, 'A', 3.14, std::string ("Hello"));  
	test_function_one (ptr_t1); 
	std::cout << "main:Returned from test_function_one" << std::endl; 
	delete ptr_t1; 
	std::cout << "main:Last message from main" << std::endl; 
	return (EXIT_SUCCESS); 
}

void test_function_one (TestClass *ptr)
{
	std::cout << "1:In test_function_two:receved testclass t1" << std::endl; 
	ptr->display (); 
	std::cout << "1:Last message from test_function_one" << std::endl; 
}
