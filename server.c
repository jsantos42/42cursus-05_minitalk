#include "common.h"

void choose_function(void(*func_name)(int), int number);
void print_hello(int num);
void print_goodbye(int num);
void	save_to_array(int *bin, int iter, int num);

int main()
{
	int iter;
	int signal;
	static int	bin[8];

	signal(SIGUSR1, save_to_array(bin, iter, 0));
	signal(SIGUSR2, save_to_array(bin, iter, 1));
	while (1)
	{
		printf("%d", getpid());
		sleep(1);
	}





	choose_function(print_hello, 29);
	choose_function(print_goodbye, 29);
//	signal(SIGUSR1, &handler);
    return 0;
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

void	save_to_array(int *bin, int iter, int num)
{
	if (iter < 8)
	{
		bin[iter] = num;
		iter++;
	}
	else
	{
		//convert to decimal and printchar
		iter = 0;
	}
}





}