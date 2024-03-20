#include <iostream> 

using namespace std; 

class T
{
	public:
		T (int n, char c, float f) 
		{
			this->i_num = n; 
			this->c_ans = c; 
			this->f_num = f; 
		}

		int get_num (void); 

		char get_char (void)
		{
			return (this->c_ans); 
		}

		float get_float (void) 
		{
			return (this->f_num); 
		}

		void set_num (int new_num) 
		{
			this->i_num = new_num; 
		}

		void set_char (char new_char) 
		{
			this->c_ans = new_char; 
		}

		void set_float (float new_float) 
		{
			this->f_num = new_float; 
		}

	private: 
		int i_num; 
		char c_ans; 
		float f_num; 
}; 

int T::get_num (void) 
{
	return (this->i_num); 
}

int main (void) 
{
	int ret_i; 
	char ret_c; 
	float ret_f; 

	T in1(10, 'A', 3.14); 
	
	ret_i = in1.get_num (); 
	ret_c = in1.get_char (); 
	ret_f = in1.get_float (); 
	cout << "Printing initial state of object" << endl; 
	cout << "in1's integer:" << ret_i << endl; 
	cout << "in1's character:" << ret_c << endl; 
	cout << "in1's float:" << ret_f << endl; 

	in1.set_num (1000); 
	in1.set_char ('Z'); 
	in1.set_float (6.28); 

	ret_i = in1.get_num (); 
	ret_c = in1.get_char (); 
	ret_f = in1.get_float (); 
	cout << "Printing modified state of object" << endl; 
	cout << "in1's integer:" << ret_i << endl; 
	cout << "in1's character:" << ret_c << endl; 
	cout << "in1's float:" << ret_f << endl; 

	return 0; 
}
