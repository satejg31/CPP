#include <iostream> 

class TestClass 
{
	public:
		TestClass () : i_num(0), c_ans('\0'), f_num(0.0) {} 
	
		TestClass (int i_num, char c_ans, float f_num) 
		{
			this->i_num = i_num; 
			this->c_ans = c_ans; 
			this->f_num = f_num; 
		}

		inline int get_int (void) const
		{
			return this->i_num; 
		}

		inline char get_char (void) const
		{
			return this->c_ans; 
		}

		inline float get_float (void) const 
		{
			return this->f_num; 
		}

		void set_int (int new_int) 
		{
			this->i_num = new_int; 
		}

		void set_char (char new_char)
		{
			this->c_ans = new_char; 
		}

		void set_float (float new_float) 
		{	
			this->f_num = new_float; 
		}

		void display (void) const 
		{
			std::cout << "Integer:" << this->i_num << std::endl; 
			std::cout << "Character:" << this->c_ans << std::endl; 
			std::cout << "Floating point:" << this->f_num << std::endl; 
		}

	private:
		int i_num; 
		char c_ans;
		float f_num; 
}; 

int main (void) 
{
	TestClass *ptr1_t = new TestClass (10, 'A', 3.14); 
	std::cout << "Integer:" << ptr1_t->get_int () << std::endl
		  << "Character:" << ptr1_t->get_char () << std::endl 
		  << "Floating point:" << ptr1_t->get_float () << std::endl; 

	delete ptr1_t; 
}
