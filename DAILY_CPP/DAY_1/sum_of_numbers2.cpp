/*
 * Program to print the sum of first 10 numbers using the for statement 
 */

#include <iostream>

int main(void)
{
	std::cout << "Used is for_loop" << std::endl;
	int val = 0;
	int sum = 0;

	for(val = 1; val <= 10; val++)
		sum += val;

	std::cout << "The sum of first 10 numbers is " << sum << std::endl;
	return (0);	
}

