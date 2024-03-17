/*
 * Program to demonstrate if statement facility 
 */

#include <iostream>

int main(void)
{	
	int v1, v2;
	int lower, upper;
	int sum = 0;
	int i = 0;

	std::cout << "Enter two numbers to print the sum of all the numbers inclusive : ";
	std::cin >> v1 >> v2;
	
	// (v1 <= v2) ? (lower = v1, upper = v2) : (lower = v2, upper = v1);
	
	if(v1 == v2)
	{
		std::cout << "Please enter proper range : ";
		std::cin >> v1 >> v2;
	}

	if(v1 <= v2)
	{
		lower = v1;
		upper = v2;
	} else {
		lower = v2;
		upper = v1;
	}

	for(i = lower; i <= upper; i++)
		sum += i;

	std::cout << "The sum of all numbers is " << sum << std::endl;

	return (0);
}

