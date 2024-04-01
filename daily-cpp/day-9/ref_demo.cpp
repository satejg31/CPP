#include <iostream>

struct A 
{
	int a; 
	char b; 
	float c; 
}; 

void f1(struct A &ref); 
struct A &f2(void); 

int main(void)
{
	int n = 10; 
	int &ref_n = n; 
	int *p = &n; 

	std::cout << "n:" << n << " ref_n:" << ref_n << std::endl; 
	std::cout << "&n:" << &n << " &ref_n:" << &ref_n << std::endl; 
	std::cout << "p:" << p << " &p:" << &p << std::endl; 

	struct A inA = {10, 'A', 3.14f}; 
	std::cout << "&inA:" << &inA << std::endl; 
	f1(inA); 
	std::cout << "inA.a:" << inA.a << " inA.b:" << inA.b << " inA.c:" << inA.c << std::endl; 

	struct A &refA = f2(); 
	std::cout << "&refA:" << &refA << std::endl; 
	std::cout << "refA.a:" << refA.a << " refA.b:" << refA.b << " refA.c:" << refA.c << std::endl; 

	free(&refA); 

	return 0; 
}

void f1(struct A &ref)
{
	std::cout << "&ref:" << &ref << std::endl; 
	std::cout << "ref.a:" << ref.a << " ref.b:" << ref.b << " ref.c:" << ref.c << std::endl; 
	ref.a = 100; 
	ref.b = 'Z'; 
	ref.c = 6.28f; 
}

struct A &f2(void)
{
	struct A *p = reinterpret_cast<struct A*>(malloc(sizeof(struct A))); 
	memset(p, 0, sizeof(struct A)); 
	p->a = 1000; 
	p->b = 'K'; 
	p->c = 9.13f; 
	std::cout << "f2:p:" << p << std::endl; 
	return (*p); 
}