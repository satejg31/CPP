/*
 * Program to print the addition of two numbers and printing the addition
 *
 */


#include <iostream>

int main(void)
{
	int v1;
	int v2;

	std::cout << "Enter two numbers : ";
       	std::cin >> v1 >> v2;
	std::cout << "The addition of " << v1 << " and " << v2 << " is " << v1 + v2 << std::endl;

	return (0);
}

