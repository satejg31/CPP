#include <iostream> 
#include <cstdlib> 
#include <cstdio> 

class TestClass 
{
public: 
	TestClass () {} 
	TestClass (int i, char c, double d) : i_num (i), c_ans (c), d_num (d) {} 

	friend void friend_function (const TestClass &ref); 

	friend std::ostream & operator<< (std::ostream &stream, const TestClass &ref)
	{
		stream << "i_num:" << ref.i_num << " c_ans:" << ref.c_ans << " d_num:" 
			   << ref.d_num; 
		return stream; 
	}

	friend std::istream & operator>> (std::istream &i_stream, TestClass &ref)
	{
		std::cout << "Enter i_num:"; 
		i_stream >> ref.i_num; 
		std::cout << "Enter c_ans:"; 
		i_stream >> ref.c_ans;
		std::cout << "Enter d_num:"; 
		i_stream >> ref.d_num; 

		return i_stream; 
	}
private:
	int i_num; 
	char c_ans;
	double d_num; 
}; 
 
void friend_function (const TestClass &ref)
{
	std::cout << "ref.i_num:" << ref.i_num << std::endl
			  << "ref.c_ans:" << ref.c_ans << std::endl
			  << "ref.d_num:" << ref.d_num << std::endl; 

}


int main (void)
{
	TestClass t1(10, 'A', 3.14); 
	TestClass t2; 
	friend_function (t1);
	std::cout << t1 << std::endl; 

	std::cin >> t2; 
	std::cout << t2 << std::endl; 

	return (EXIT_SUCCESS); 
}