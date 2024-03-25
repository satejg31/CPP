#ifndef _TESTCLASS_H 
#define _TESTCLASS_H 

class TestClass 
{
	public:
		TestClass () : i_num(0), c_ans('\0'), f_num(0.0) {}
		TestClass (int i_num, char c_ans, float f_num); 	
		inline int get_integer (void) const; 
		inline char get_char (void) const; 
		inline float get_float (void) const; 
		inline void set_integer (int new_int); 
		inline void set_char (char new_char); 
		inline void set_float (float new_float); 
		void display (void) const; 
	private:
		int i_num; 
		char c_ans; 
		float f_num; 	
}; 

inline int TestClass::get_integer (void) const 
{
	return this->i_num; 
}

inline char TestClass::get_char (void) const 
{
	return this->c_ans; 
}

inline float TestClass::get_float (void) const
{
	return this->f_num; 
}

inline void TestClass::set_integer (int new_int) 
{
	this->i_num = new_int; 
}

inline void TestClass::set_char (char new_char) 
{
	this->c_ans = new_char; 
}

inline void TestClass::set_float (float new_float) 
{
	this->f_num = new_float; 
}


#endif /* _TESTCLASS_H */ 
