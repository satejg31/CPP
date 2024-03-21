#include <iostream> 
#include <string> 

class TestClass 
{
	public: 
		TestClass () : i_num(0), c_ans('\0'), f_num (0.0) {}
		
		TestClass() {} 

		TestClass(int init_num, char init_char, float init_float): 
		i_num(init_num), c_ans(init_char), f_num(init_float) {} 

		TestClass (int i_num, char c_ans, float f_num) 
		{
			this->i_num = i_num; 
			this->c_ans = c_ans; 
			this->f_num = f_num; 
		}

		void display (void) const
		{
			std::cout << "integer:" << this->i_num << std::endl 
				  << "character:" << this->c_ans << std::endl 
				  << "floating:" << this->f_num << std::endl; 
		}

		void set (int i_num, char c_ans, float f_num) 
		{
			this->i_num = i_num; 
			this->c_ans = c_ans; 
			this->f_num = f_num; 
		}

	private:
		int i_num; 
		char c_ans;
		float f_num; 
		std::string s; 
}; 

TestClass t1 (10, 'A', 3.14); 
TestClass t2; 

int main (void) 
{
	TestClass *ptr1_t = new TestClass (); 
	TestClass *ptr2_t = new TestClass (100, 'Z', 56.43); 
	TestClass t3; 
	
	std::cout << "Displaying t1:" << std::endl; 
	t1.display (); 
	
	std::cout << "Displaying t2:" << std::endl; 
	t2.display (); 
	
	std::cout << "Displaying ptr1_t:" << std::endl; 
	ptr1_t->display (); 

	std::cout << "Displaying ptr2_t:" << std::endl; 
	ptr2_t->display (); 

	std::cout << "Displaying t3:" << std::endl; 
	t3.set (6000, 'G', 324.5); 

	t2.set (3000, 'B', 43.32); 
	ptr1_t->set (4000, 'C', 324.3); 
	t3.set (5000, 'D', 34.4); 

	std::cout << "Displaying t1:" << std::endl; 
	t1.display (); 
	
	std::cout << "Displaying t2:" << std::endl; 
	t2.display (); 
	
	std::cout << "Displaying ptr1_t:" << std::endl; 
	ptr1_t->display (); 

	std::cout << "Displaying ptr2_t:" << std::endl; 
	ptr2_t->display (); 
	
	std::cout << "Displaying t3:" << std::endl; 
	t3.display (); 

	delete ptr1_t; 
	delete ptr2_t; 

	return 0; 
}


struct A {

}; 

main()
{
	struct A *p = (struct A*)malloc(sizeof(struct A)); 
	memset((void*)p, 0, sizeof(struct A)); 

	// Use p 

	free(p); 
	p = NULL; 
}
