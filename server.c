#include "common.h"

/*
**	Starts by changing the default answer to the SIGUSR1 and SIGUSR2 signals,
**	which will be used as code to pass bits (0 and 1, respectively).
**	It runs an infinite loop, during which it can receive signals from the
**	client program, which will allow it to print the transmitted string.
**
**	NOTE: I'm not entirely sure SA_SIGINFO really needs to be defined, since the
**	compiler raises no issue without it and it runs smoothly. Still, according
**	to the documentation of sigaction, it should be defined.
*/

int	main(void)
{
	struct sigaction	sa;

	sa.sa_sigaction = save_to_array;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	sigemptyset(&sa.sa_mask);
	sigaddset(&sa.sa_mask, SIGUSR1);
	sigaddset(&sa.sa_mask, SIGUSR2);
	sa.sa_flags = SA_SIGINFO;
	ft_putstr_fd("Server is now running. PID: ", 1);
	ft_putnbr_fd(getpid(), 1);
	ft_putchar_fd('\n', 1);
	while (1)
		pause();
}

/*
**	Starts by doing typecasting to ucontext since it will not be needed;
**	It will use the signals received to rebuild the chars from the string given
**	to client. Everytime array.iter gets to 8, it prints the char and resets the
**	array.
**	When it gets a null char, it understands it's the end of the string, prints
**	a nl char and sends a signal back to client to acknowledge the reception of
**	the string.
*/

void	save_to_array(int signal, siginfo_t *info, void *ucontext)
{
	static t_static	array;
	u_int8_t		converted_signal;
	u_int8_t		decimal;

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
		write(1, &decimal, 1);
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
	u_int8_t	decimal;
	u_int8_t	base_2;
	u_int8_t	iter;

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
