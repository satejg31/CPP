#include <iostream> 

class TestClass 
{
	public: 
		TestClass (int num, char c_ans, float f_num) 
		{
			this->i_num = num; 
			c_ans = c_ans; 
			f_num = f_num; 
		}	

		int get_num (void); 
		char get_char (void); 
		float get_float (void); 
		void set_num (int new_num); 
		void set_char (char new_char); 
		void set_fnum (float new_fnum); 

	private: 
		int i_num; 
		char c_ans; 
		float f_num; 
}; 

int TestClass::get_num (void) 
{
	return this->i_num; 
}

char TestClass::get_char (void) 
{
	return this->c_ans; 
}

float TestClass::get_float (void) 
{
	return this->f_num; 
}

void TestClass::set_num (int i_num)
{
	this->i_num = i_num; 
}

void TestClass::set_char (char new_char) 
{
	this->c_ans = new_char; 
}

void TestClass::set_fnum (float new_fnum) 
{
	this->f_num = new_fnum; 
}

int main (void) 
{
	TestClass t1(10, 'A', 3.14); 
	TestClass *t_ptr = new TestClass (20, 'B', 6.28); 

	std::cout << "obj1:integer:" << t1.get_num () << std::endl; 
	std::cout << "obj1:character:" << t1.get_char () << std::endl; 
	std::cout << "obj1:float:" << t1.get_float () << std::endl; 

	t_ptr->set_num (200); 
	t_ptr->set_char ('Z'); 
	t_ptr->set_fnum (100.100); 

	std::cout << "obj2:integer:" << t_ptr->get_num () << std::endl; 
	std::cout << "obj2:character:" << t_ptr->get_char () << std::endl; 
	std::cout << "obj2:float:" << t_ptr->get_float () << std::endl; 

	delete t_ptr; 
	return 0; 
}
