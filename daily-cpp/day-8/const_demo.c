#include <stdio.h> 

struct A 
{
	int i_num; 
	char c_ans; 
	float f_num; 
}; 

struct A c_in = {10, 'A', 3.14}; 


int main (void) 
{
	const struct A *ptr = &c_in; 
	ptr->i_num = 2000; 
	//c_in.i_num = 1000; 
	return (0); 
}
