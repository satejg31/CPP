/*
 * Program to print the Multiplication of two numbers and printing the addition
 *
 */


#include <iostream>

int main(void)
{
	int v1;
	int v2;

	std::cout << "Enter two numbers : ";
       	std::cin >> v1 >> v2;
	if(v1 == 0 && v2 == 0)
	{
		std::cout << "Add valid input for the program!" << std::endl;
		std::cout << "Enter two numbers again : ";
		std::cin >> v1 >> v2;
	}
	std::cout << "The multiplication of " << v1 << " and " << v2 << " is " << v1 * v2 << std::endl;

	return (0);
}

