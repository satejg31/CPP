#include <iostream> 
#include <cstdlib> 

class Range{
public: 
	class Iterator; 

	Range(int s, int e) : first(s), last(e) {} 

	Range(int e) : first(0), last(e) {} 

	Iterator &begin(void) 
	{
		Iterator *pIter = new Iterator(this->first); 
		return *pIter; 
	}
	
	Iterator &end(void) 
	{
		Iterator *pIter = new Iterator(last);
		return *pIter; 
	}

	class Iterator{
	public:
		Iterator() {} 

		Iterator(int n) : i(n) {} 

		void operator++(void) 
		{
			++i;
		}

		void operator--(void) 
		{
			--i;
		}

		void operator++(int) 
		{
			i++;
		}
		
		void operator--(int) 
		{
			i--;
		}

		int operator*(void) const 
		{
			return (i);
		}

		bool operator==(const Iterator &other_iter) const
		{ 
			return (this->i == other_iter.i); 
		}

		bool operator!=(const Iterator &other_iter) const
		{ 
			return (this->i != other_iter.i);
		}

	private:
		int i; 
	}; 

private:
	int first, last; 
}; 

int main(void)
{
	Range r(10, 20); 

	for(Range::Iterator &it=r.begin(); it != r.end(); ++it)
		std::cout << *it << std::endl; 

	return EXIT_SUCCESS; 
}

