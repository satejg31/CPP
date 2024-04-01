#include <iostream> 
#include <cstdlib> 
#include <string> 

class StudentRecord{
public:	
	StudentRecord() {} 

	StudentRecord(std::string &s_name_in, int s_roll_in=0, double s_marks_in=0.0) : 
			  	  s_name(s_name_in), s_roll(s_roll_in), s_marks(s_marks_in) {} 

	friend std::ostream &operator<< (std::ostream &os, StudentRecord &instance)
	{
		os << "Name:" << instance.s_name << std::endl << "Roll:" << instance.s_roll
		   << std::endl << "Marks:" << instance.s_marks << std::endl; 
		return (os); 

	}

	friend std::istream &operator>> (std::istream &in, StudentRecord &instance)
	{
		std::cout << "Enter Name:"; 
		in >> instance.s_name; 
		std::cout << "Enter Roll:"; 
		in >> instance.s_roll; 
		std::cout << "Enter Marks:"; 
		in >> instance.s_marks; 

		return (in); 
	}

private:
	std::string s_name; 
	int s_roll; 
	double s_marks; 
}; 

int main(void)
{
	StudentRecord s; 
	std::cout << "Main:Inputting student record:" << std::endl; 
	std::cin >> s; 
	std::cout << "Main:Outputting student record:" << std::endl; 
	std::cout << s; 

	return EXIT_SUCCESS; 
}
