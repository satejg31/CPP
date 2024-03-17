/*
 * Program to print the range of all the numbers given to the standard input
 *
 */

#include <iostream>

int main(void)
{
	int v1, v2;
	int lower, upper;
	std::cout << "Enter two numbers to print all the numbers between them : ";
	std::cin >> v1 >> v2;

	(v1 <= v2) ? (lower = v1, upper = v2) : (lower = v2, upper = v1);

	for(int i=lower; i <= upper ; i++)
		std::cout << i << " ";
	std::cout << "\n";
	
	return (0);
}

