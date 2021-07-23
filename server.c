#include <stdio.h>
#include <unistd.h>
#include <signal.h>

void	handler(int sig_num);

void choose_function(void(*func_name)(int), int number);
void print_hello(int num);
void print_goodbye(int num);

int main()
{
	int iter;
	int signal;

	choose_function(print_hello, 29);
	choose_function(print_goodbye, 29);
//	signal(SIGUSR1, &handler);


//	printf("Hello process number %d\n", getpid());

//	while (1)
//	{
//		//if gets string, print it
//		sleep(1);
//	}
    return 0;
}

void	handler(int sig_num)
{

}


void print_hello(int num)
{
	printf("hello, I'm number %d\n", num);
}

void print_goodbye(int num)
{
	printf("goodbye, I'm number %d\n", num);
}

void choose_function(void(*func_name)(int), int number)
{
	func_name(number);
}