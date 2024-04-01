#include <iostream> 
#include <cstdlib> 
#include <vector> 

#define CAP 100 
#define VEC_SIZE 10 

int main(void) 
{
	std::vector<int> ivec; 
	
	for(int i=0; i != VEC_SIZE; ++i)
			ivec.push_back(rand() % CAP); 

	for(std::vector<int>::iterator iter = ivec.begin(); 
		iter != ivec.end(); ++iter)
			std::cout << "*iter:" << *iter << std::endl; 
	
	std::string s; 
	std::vector<std::string> svec; 
	for(int i=0; i != VEC_SIZE; ++i)
	{
		std::cout << "Enter string:" << std::endl; 
		std::cin >> s; 
		svec.push_back(s); 
	}

	for(std::vector<std::string>::iterator iter = svec.begin(); 
		iter != svec.end(); ++iter)
			std::cout << "*iter:" << *iter << std::endl; 


	return (EXIT_SUCCESS); 
}
