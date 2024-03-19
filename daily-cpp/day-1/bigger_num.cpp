/*
 * Program to print the larger number between two numbers 
 */

#include <iostream>

int main(void)
{
	int v1, v2;

	std::cout << "Enter two numbers : ";
	std::cin >> v1 >> v2;

	(v1 <= v2) ? (std::cout << "Second number entered is bigger than the first number" << std::endl) : 
					(std::cout << "First number entered is bigger than the second number" << std::endl);

	return (0);	
}

