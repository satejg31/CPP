#include <iostream> 

/* class T{
 *	static attr1;
 *	static attr2; 
 *
 *	static attrn;
 * };  
 *
 * TYPE T::attr1 = <something> 
 * TYPE T::attr2 = <something> 
 *
 *
 * TYPE T::attrn = <something> 
 */ 

class TestClass {
	public: 
		
		TestClass () : i_num (0), c_ans ('\0'), f_num (0.0) {} 

		TestClass (int i_num, char c_ans, float f_num)  {
			this->i_num = i_num; 
			this->c_ans = c_ans; 
			this->f_num = f_num; 
		}

		int get_int (void) const; 
		char get_char (void) const; 
		float get_float (void) const; 
		void set_int (int new_int); 
		void set_char (char new_char); 
		void set_float (float new_float); 
		void display (void) const; 
		
		static void static_method (void) {
			std::cout << "This is a static method" << std::endl; 
			static_num = 100; // can be used in static method
			std::cout << "static_num:" << static_num << std::endl;  
			//std::cout << "i_num:" << i_num << std::endl; 
		}	

	private:
		int i_num; 
		char c_ans; 
		float f_num; 
		static int static_num; 
}; 

int TestClass::static_num = 0; 

int TestClass::get_int (void) const {
	++static_num; // Can be used object methods  
	return (this->i_num); 
}

char TestClass::get_char (void) const {
	++static_num; 
	return (this->c_ans); 
}

float TestClass::get_float (void) const {
	return (this->f_num); 
}

void TestClass::set_int (int new_int) {
	this->i_num = new_int; 
}

void TestClass::set_char (char new_char) {
	this->c_ans = new_char; 
}

void TestClass::set_float (float new_float) {
	this->f_num = new_float; 
}

void TestClass::display (void) const {
	std::cout << "i_num:" << i_num << std::endl 
		  << "c_ans:" << c_ans << std::endl 
		  << "f_num:" << f_num << std::endl
		  << "static_num:" << static_num << std::endl; 
}

int main (void) {
	TestClass *ptr1 = new TestClass (10, 'A', 3.14f); 
	const TestClass *ptr2 = new TestClass (20, 'B', 6.28f); 

	std::cout << "ptr1:i_num:" << ptr1->get_int () << std::endl; 
	std::cout << "ptr2:c_ans:" << ptr2->get_char () << std::endl; 

	ptr1->display (); 
	ptr2->display (); 

	ptr1->static_method (); // can be done, not recommended  
	TestClass::static_method (); // static method belongs to class 
	// therefore, scope should be resolved giving class name 

	return (0); 
}
