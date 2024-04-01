#include <iostream> 

class Int
{
private: 
	int i_num; 
public: 
	
	Int() : i_num(0) {} 
	
	Int(int i_in_num) : i_num (i_in_num) {} 

	int get() const {return i_num;}

	void set(int i_new_num) {i_num = i_new_num;}
}; 

Int *get_new_Int_via_pointer(int i_init_num); 
Int &get_new_Int_via_object(int i_init_num); 

int main(void)
{
	Int *p = get_new_Int_via_pointer(100); 
	Int &refInt = get_new_Int_via_object(200); 

	std::cout << "Val:" << p->get() << std::endl; 
	std::cout << "Val:" << refInt.get() << std::endl; 

	delete p; 
	delete &refInt; 

	p = NULL; 

	return 0; 
}

Int *get_new_Int_via_pointer(int i_init_num)
{
	Int *pInt = new Int(i_init_num); 
	return pInt; 
} 
Int &get_new_Int_via_object(int i_init_num)
{
	Int *pInt = new Int(i_init_num); 
	return *pInt; 
	//	return *(new Int(i_init_num)); 

}