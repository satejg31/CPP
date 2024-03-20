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

		T () {} 

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

		void display (void)
		{
			cout << "object's integer:" << i_num << endl
			     << "object's character:" << c_ans << endl 
			     << "object's float:" << f_num << endl; 
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
	T in1 (10, 'A', 3.14); 
	T *ptr1 = new T (100, 'Z', 6.28); 
	
	cout << "Displaying in1:" << endl; 
	in1.display (); 

	cout << "Displaying ptr1:" << endl; 
	ptr1->display (); 

	T in2; 
	T *ptr2 = new T (); 

	cout << "Displaying in2:" << endl; 
	in2.display (); 

	cout << "Displaying ptr2:" << endl; 
	ptr2->display (); 

	return 0; 
}
