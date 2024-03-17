/*
 * Program to print the count of negative numbers entered
 */

#include <iostream>

int main(void)
{	
	int input;
	int cnt = 0;

	std::cout << "Enter numbers and this program will print the count of all negative numbers [Press Ctrl+D to give EOF]" << std::endl;
	
	// Ctrl + Z in Windows Operating System
	
	while(std::cin >> input)
		(input < 0) ? cnt++ : cnt;
	
	std::cout << "\nThe count of negative numbers entered : " << cnt << std::endl;
	return (0);
}

