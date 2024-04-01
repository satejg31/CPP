#include <iostream> 
#include <cstdlib> 

struct A
{
	int i_arr[4]; 
	double d_num; 
}; 

int *get_int_ptr(void); 
struct A &get_objA(void); 


int main(void) 
{
	int *p = get_int_ptr(); 
	*p = 100; 
	std::cout << "*p : " << *p << std::endl; 
	delete p; 
	p = 0;
	
	struct A &refA = get_objA(); 
	std::cout << "Dumping A:" << std::endl; 
	for(int i = 0; i < 4; i++) 
			std::cout << "refA.i_arr[" << i << "]:" << refA.i_arr[i] << std::endl; 
	std::cout << "refA.d_num:" << refA.d_num << std::endl; 

	delete (&refA); 


	return EXIT_SUCCESS; 
}

int *get_int_ptr(void) 
{
	return (new int()); 
}

struct A &get_objA(void) 
{
	struct A *p = new struct A; 
	for(int i = 0; i < 4; ++i)
		p->i_arr[i] = (i + 1) * 100; 
	p->d_num = 3.1415; 

	return (*p); 
}

