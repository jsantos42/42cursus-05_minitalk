#include "../include/common.h"

/*
**	Starts by changing the default answer to the SIGUSR1 signal, printing a
**	confirmation message before exiting.
**	Then checks if the number of arguments is correct.
**	If so, it parses the string argv[2] and calls convert_to_binary_and_send on
**	each character of it. Funny enough, it works with Unicode chars too, because
**	these ones take 16bits (instead of 8), and when it moves to the next byte
**	with str++, it reads the second byte of the Unicode char; only after doing
**	so is main moving to the next char.
**	Finally it sends a null char to warn of the end of the string and waits for
**	a confirmation message from the server. If it doesn't arrive in 5 seconds,
**	it exits with an error.
**
**	NOTE: I'm not entirely sure SA_SIGINFO really needs to be defined, since the
**	compiler raises no issue without it and it runs smoothly. Still, according
**	to the documentation of sigaction, it should be defined.
*/

int	main(int argc, char **argv)
{
	int					pid;
	char				*str;
	int					bin[8];
	struct sigaction	sa;

	sa.sa_sigaction = print_confirmation;
	sigaction(SIGUSR1, &sa, NULL);
	sigemptyset(&sa.sa_mask);
	sigaddset(&sa.sa_mask, SIGUSR1);
	sa.sa_flags = SA_SIGINFO;
	if (argc != 3)
		error_handler(INVALID_INPUT);
	pid = ft_atoi(argv[1]);
	str = argv[2];
	while (*str)
	{
		convert_to_binary_and_send(bin, *str, pid);
		str++;
	}
	convert_to_binary_and_send(bin, '\0', pid);
	sleep(5);
	error_handler(NO_FEEDBACK);
}

/*
**	If the program is to work with Unicode chars, then it has to convert the
**	given char to an unsigned char.
*/

void	convert_to_binary_and_send(int *bin, unsigned char letter, int pid)
{
	int	base_2;
	int	iter;

	base_2 = 128;
	iter = 0;
	while (iter < 8)
	{
		if (letter / base_2)
			bin[iter] = 1;
		else
			bin[iter] = 0;
		letter %= base_2;
		base_2 /= 2;
		iter++;
	}
	if (send_binary(bin, pid) == -1)
		error_handler(TRANSMISSION_ERROR);
}

/*
**	The usleep is crucial so that signals don't overlap and are not ignored.
**	The value could be changed though.
*/

int	send_binary(int *bin, int pid)
{
	int	ret;
	int	iter;

	ret = 0;
	iter = 0;
	while (iter < NUMBER_OF_BITS)
	{
		if (bin[iter] == 0)
			ret = kill(pid, SIGUSR1);
		else
			ret = kill(pid, SIGUSR2);
		usleep(100);
		iter++;
	}
	return (ret);
}
