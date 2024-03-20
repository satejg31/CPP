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
	T *ptr; 
	int ret_i; 
	char ret_c; 
	float ret_f; 

	ptr = new T (10, 'A', 3.14); 
	
	ret_i = ptr->get_num (); 
	ret_c = ptr->get_char (); 
	ret_f = ptr->get_float ();
	cout << "Printing initial state:" << endl
	     << "ptr's integer:" << ret_i << endl 
	     << "ptr's character:" << ret_c << endl 
	     << "ptr's float:" << ret_f << endl; 
	
	cout << "Setting ptr's new state...." << endl; 
	ptr->set_num (1000); 
	ptr->set_char ('Z'); 
	ptr->set_float (234.23); 

	ret_i = ptr->get_num (); 
	ret_c = ptr->get_char (); 
	ret_f = ptr->get_float ();
	cout << "Printing modified state:" << endl
	     << "ptr's integer:" << ret_i << endl 
	     << "ptr's character:" << ret_c << endl 
	     << "ptr's float:" << ret_f << endl; 

	return 0; 
}
