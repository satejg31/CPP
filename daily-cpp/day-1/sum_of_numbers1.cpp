/*
 * Program to print sum of first 10 numbers using the while loop
 */

#include <iostream>

int main(void)
{
	std::cout << "Used is while_loop" << std::endl;
	int val = 1;
	int sum = 0;

	while(val <= 10)
	{
		sum += val;
		++val;
	}

	std::cout << "The sum of first 10 numbers is " << sum << std::endl;
	return (0);
}
