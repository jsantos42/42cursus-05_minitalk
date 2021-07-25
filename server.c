#include "common.h"

int main()
{
	signal(SIGUSR1, save_to_array);
	signal(SIGUSR2, save_to_array);
	while (1)
	{
		printf("%d\n", getpid());
//		raise(SIGUSR1);
//		raise(SIGUSR2);
//		raise(SIGUSR1);
//		raise(SIGUSR1);
//		raise(SIGUSR1);
//		raise(SIGUSR1);
//		raise(SIGUSR1);
//		raise(SIGUSR1);
		pause();
	}
    return 0;
}

void	save_to_array(int signal)
{
	static int	iter;
	static int	bin[8];
	int 		converted_signal;
	int			decimal;

	printf("got a signal %d\n", signal);
	if (signal == SIGUSR1)
		converted_signal = 0;
	else if (signal == SIGUSR2)
		converted_signal = 1;
	if (iter < 8)
	{
		bin[iter] = converted_signal;
		iter++;
	}
	if (iter == 8)
	{
		decimal = decimal_conv(bin);
		printf("%c", decimal);
//		write(1, &decimal, 1);
		iter = 0;
	}
}

int	decimal_conv(int *bin)
{
	int	decimal;
	int base_2;
	int iter;

	decimal = 0;
	base_2 = 128;
	iter = 0;
	while (iter < 8)
	{
		if (bin[iter] == 1)
			decimal += base_2;
		base_2 /= 2;
		iter++;
	}
	return (decimal);
}
