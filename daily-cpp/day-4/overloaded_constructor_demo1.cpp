#include <iostream>
#include <string> 

class StudentRecord 
{
	public: 
		StudentRecord () : st_roll(0), st_marks(0.0) {} 

		StudentRecord (std::string &s_name, std::string &s_city, 
			       int roll, double marks) 
		{
			this->st_name  = s_name; 
			this->st_city  = s_city; 
			this->st_roll  = roll; 
			this->st_marks = marks; 
		}

		StudentRecord (std::string &s_name, std::string &s_city) : 
			       st_roll (0), st_marks (0.0)
		{
			this->st_name = s_name; 
			this->st_city = s_city; 
		}

		StudentRecord (int i_roll, double d_marks) 
		{
			this->st_roll  = i_roll; 
			this->st_marks = d_marks; 
		}

		void display (void) const 
		{
			std::cout << "Name:" << this->st_name << std::endl 
				  << "City:" << this->st_city << std::endl 
				  << "Roll:" << this->st_roll << std::endl 
				  << "Marks:" << this->st_marks << std::endl; 
		}

		void set (std::string &s_name, std::string &s_city, 
			  int i_roll, double d_marks) 
		{
			this->st_name  = s_name; 
			this->st_city  = s_city; 
			this->st_roll  = i_roll; 
			this->st_marks = d_marks; 
		}

		void set_name (std::string &new_name)
		{
			this->st_name = new_name; 
		}

		void set_city (std::string &new_city)
		{
			this->st_city = new_city; 
		}

		void set_roll (int new_roll) 
		{
			this->st_roll = new_roll; 
		}

		void set_marks (double new_marks) 
		{
			this->st_marks = new_marks; 
		}

		void show_ptrs (void) 
		{
			std::cout << &st_name << std::endl; 
			std::cout << &st_city << std::endl; 
		}
	
	private:
		std::string st_name; 
		std::string st_city; 
		int st_roll; 
		double st_marks; 
}; 

int main (void)
{
	std::string name1("Yogeshwar"), name2("Pratik"); 
	std::string city1("Pune"), city2("Mumbai"); 

	StudentRecord *sr1 = new StudentRecord (); 
	std::cout << "Displaying sr1:" << std::endl; 
	sr1->display (); 
	sr1->set (name1, city1, 10, 40.5); 
	std::cout << "Displaying sr1 after set:" << std::endl; 
	sr1->display (); 

	StudentRecord *sr2 = new StudentRecord (name2, city2); 
	std::cout << "Displaying sr1:" << std::endl; 
	sr2->display (); 
	sr2->set_roll (200); 
	sr2->set_marks (56.454); 
	std::cout << "Displaying sr2 after set:" << std::endl; 
	sr2->display (); 

	std::cout << "A(name1):" << &name1 << std::endl 
		  << "A(city1)" << &city1 << std::endl; 
	sr1->show_ptrs (); 

	delete sr1; 
	delete sr2; 

	return 0; 
}
