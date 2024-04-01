#include <iostream> 
#include <cstdlib> 


class Int
{
	public: 
			Int() : i_num(0) {} 

			Int(int in_i_num) : i_num(in_i_num) {} 

			Int *operator+(const Int &other)
			{
				return (new Int(this->i_num + other.i_num)); 
			}

			Int *operator-(const Int &other)
			{
				return (new Int(this->i_num - other.i_num)); 
			}

			Int *operator*(const Int &other)
			{
				return (new Int(this->i_num * other.i_num)); 
			}

			Int *operator/(const Int &other)
			{
				return (new Int(this->i_num / other.i_num)); 
			}

			Int &operator=(const Int &other) 
			{
				this->i_num = other.i_num;
		  		return (*this); 		
			}

			void display(void) const 
			{
				std::cout << i_num << std::endl; 
			}		
		
			void set(int in_i_num) 
			{
				i_num = in_i_num; 
			}
	private:
			int i_num; 
}; 


int main(void) 
{
	Int *pnum1 = new Int(); 
	Int *pnum2 = new Int(2000); 
	Int *psum=0, *psub=0, *pmul=0, *pdiv=0; 

	Int num4(500); 
	Int num5(num4); 

	pnum1->display(); 
	pnum1->set(1000); 
	pnum1->display(); 

	psum = *pnum1 + *pnum2; 
	psub = *pnum1 - *pnum2; 
	pmul = *pnum1 * *pnum2; 
	pdiv = *pnum1 / *pnum2; 

	std::cout << "Summation:"; 
	psum->display(); 

	std::cout << "Subtraction:"; 
	psub->display(); 

	std::cout << "Multiplication:"; 
	pmul->display(); 

	std::cout << "Division:"; 
	pdiv->display(); 

	std::cout << "*pnum1:"; 
	pnum1->display(); 

	std::cout << "*pnum2:"; 
	pnum2->display(); 
	
	*pnum2 = *pnum1; 
	
	std::cout << "*pnum2:"; 
	pnum2->display(); 

	std::cout << "num4:"; 
	num4.display(); 

	std::cout << "num5:"; 
	num5.display(); 
	
	delete pnum1; 
	pnum1 = 0; 
	
	delete pnum2; 
	pnum2 = 0; 

	delete psum; 
	psum = 0; 

	delete psub; 
	psub = 0; 

	delete pmul; 
	pmul = 0; 

	delete pdiv; 
	pdiv = 0; 

	return EXIT_SUCCESS; 
}
