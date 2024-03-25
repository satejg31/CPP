#include <iostream> 
#include "testclass.h" 

TestClass::TestClass (int i_num, char c_ans, float f_num) 
{
	this->i_num = i_num; 
	this->c_ans = c_ans; 
	this->f_num = f_num; 
}

void TestClass::display (void) const 
{
	std::cout << "Integer:" << this->i_num << std::endl
		  << "Character:" << this->c_ans << std::endl 
		  << "Floating:" << this->f_num << std::endl; 
}
