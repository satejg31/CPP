#include <iostream> 
#include <cstdlib> 

class TestClass 
{
	public: 
		TestClass () : i_num (0), c_ans ('\0'), f_num (0.0), 
			       mt_num (0) {}
		TestClass (int i_num, char c_ans, float f_num, int mt_num) 
		{
			this->i_num = i_num; 
			this->c_ans = c_ans; 
			this->f_num = f_num; 
			this->mt_num = mt_num; 
		}
		int get_int (void) const; 
		char get_char (void) const; 
		float get_float (void) const; 
		int get_mtnum (void) const; 
		void set_int (int new_int); 
		void set_char (char new_char); 
		void set_float (float new_float); 
	private:
		int i_num; 
		char c_ans; 
		float f_num; 
		mutable int mt_num; 
}; 

int TestClass::get_int (void) const 
{
	//this->i_num = 100; //compilation error 
	return (this->i_num); 
}

char TestClass::get_char (void) const
{
	return (this->c_ans); 
}

float TestClass::get_float (void) const 
{
	return (this->f_num); 
}

int TestClass::get_mtnum (void) const 
{
	// mutable member can be modified through
	// const method 
	this->mt_num = 5000; 
	return (this->mt_num); 
}

void TestClass::set_int (int new_int) 
{
	this->i_num = new_int; 
}
void TestClass::set_char (char new_char) 
{
	this->c_ans = new_char; 
}

void TestClass::set_float (float new_float) 
{
	this->f_num = new_float; 
}

const TestClass tobj_g (6000, 'A', 45.54, 600); 

int main (void) 
{
	TestClass *t1 = new TestClass (1000, 'A', 3.14f, 100); 
	std::cout << "i_num:" << t1->get_int () << std::endl; 
	t1->set_int (100); 
	std::cout << "i_num:" << t1->get_int () << std::endl; 
	const TestClass *t2 = t1; 
	//t2->set_int (2000); // Compilation error
	std::cout << "i_num:" << t2->get_int () << std::endl; 
	// remove const of get_int and try to invoke it through 
	// through const pointer t2. It will result in compile 
	// time error 
	std::cout << "Calling get_mtnum from t1:" << t1->get_mtnum () 
		  << std::endl; 
	std::cout << "Calling get_mtnum from t2:" << t2->get_mtnum () 
		  << std::endl; 
//	tobj_g.set_int (6); // compilation error 
	std::cout << "tobj.get_mtnum:" << tobj_g.get_mtnum () << std::endl; 
	const TestClass tobj_l (7000, 'Z', 45.54, 700); 
//	tobj_l.set_int (7); // compilation error  
	std::cout << "tobj_l.get_mtnum ():" << tobj_l.get_mtnum () << std::endl; 
	return 0; 
}
