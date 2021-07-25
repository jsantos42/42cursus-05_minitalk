#include "common.h"

int main()
{
	signal(SIGUSR1, save_to_array);
	signal(SIGUSR2, save_to_array);
	ft_putnbr_fd(getpid(), 1);
	ft_putchar_fd('\n', 1);
	while (1)
		sleep(10);
    return (0);
}

void	save_to_array(int signal)
{
	static t_static	array;
	int				converted_signal;
	int				decimal;

	if (signal == SIGUSR1)
		converted_signal = 0;
	else if (signal == SIGUSR2)
		converted_signal = 1;
	if (array.iter < 8)
	{
		array.bin[array.iter] = converted_signal;
		array.iter++;
	}
	if (array.iter == 8)
	{
		decimal = decimal_conv(array.bin);
		write(1, &decimal, 1);
		array.iter = 0;
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
