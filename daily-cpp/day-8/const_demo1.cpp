#include <iostream>
#include <cstdlib> 
#include <cstdio>  

void f(const int *p); 

int main(void) 
{
	int n1 = 100; 
	int n2 = 200; 
	
	const int *p = &n1; 

	printf("Value of n1 = *p = %d\n", *p); 	//	Reading n1 from is allowed 
	f(&n1); 
	printf("Value of n1 = *p = %d\n", *p); 
	
	return EXIT_SUCCESS; 
}

void f(const int *p) 
{
	*p = 500; 
}
