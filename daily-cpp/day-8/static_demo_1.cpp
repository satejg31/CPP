#include <iostream> 
#include <cstdlib> 
#include <pthread.h>
#include <unistd.h> 

int global_num; 

class TestClass 
{
	public: 
		TestClass () {} 
		void inc (void);  
		void dec (void); 
		static void init_lock (void){
			pthread_mutex_init (&lock2, NULL); 
		}
	private: 
		static pthread_mutex_t lock1; 
		static pthread_mutex_t lock2; 
}; 

pthread_mutex_t TestClass::lock1 = PTHREAD_MUTEX_INITIALIZER;  
pthread_mutex_t TestClass::lock2 = PTHREAD_MUTEX_INITIALIZER; 

void TestClass::inc (void) {
	pthread_mutex_lock (&lock2); 
	::global_num++; 
	std::cout << "thread_id:" << pthread_self () << " global_num:" 
		  << global_num << std::endl; 
	pthread_mutex_unlock (&lock2); 	
}

void TestClass::dec (void) {
	pthread_mutex_lock (&lock2); 
	::global_num--; 
	std::cout << "thread_id:" << pthread_self () << " global_num:" 
		  << global_num << std::endl; 
	pthread_mutex_unlock (&lock2); 
}

void *thread_function_1 (void*); 
void *thread_function_2 (void*); 

int main (void) 
{
	pthread_t th1, th2; 
	TestClass::init_lock (); 

	pthread_create (&th1, NULL, thread_function_1, NULL); 
	pthread_create (&th2, NULL, thread_function_2, NULL); 

	pthread_join (th1, NULL); 
	pthread_join (th2, NULL); 

	return (EXIT_SUCCESS); 
}

void *thread_function_1 (void *args) {
	TestClass *p_obj = new TestClass (); 
	for(int i = 0; i < 10; i++)
	{
		p_obj->inc (); 
		sleep (1); 
	}
	delete p_obj; 
	p_obj = 0; 
}

void *thread_function_2 (void *args) 
{
	TestClass *p_obj = new TestClass (); 
	for(int i = 0; i < 20; i++) {
		p_obj->dec (); 
		sleep (2); 
	}
	delete p_obj; 
	p_obj = 0; 
}
