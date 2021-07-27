#include "common.h"

int main(void)
{
	struct sigaction	sa;

	sa.sa_sigaction = save_to_array;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	sigemptyset(&sa.sa_mask);
	sigaddset(&sa.sa_mask, SIGUSR1);
	sigaddset(&sa.sa_mask, SIGUSR2);
//	sa.sa_flags = SA_SIGINFO; ////not sure if needed
	ft_putstr_fd("Server is now running. PID: ", 1);
	ft_putnbr_fd(getpid(), 1);
	ft_putchar_fd('\n', 1);
	while (1)
		pause();
    return (0);
}

void	save_to_array(int signal, siginfo_t *info, void *ucontext)
{
	static t_static	array;
	int				converted_signal;
	int				decimal;

	(void)ucontext;
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
		write(1, &decimal, 1); //if it prints every 8, how come it prints a unicode thats 16, does it know it will get for another 8?
		if (decimal == '\0')
		{
			write(1, "\n", 1);
			kill(info->si_pid, SIGUSR1);
		}
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
