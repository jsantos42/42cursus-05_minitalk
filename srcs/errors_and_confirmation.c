#include "../include/common.h"

int	error_handler(int error)
{
	ft_putstr_fd("ERROR: ", 1);
	if (error == INVALID_INPUT)
	{
		ft_putstr_fd("Invalid input.\n", 1);
		ft_putstr_fd("Please try: ./client <PID> <string to send>\n", 1);
	}
	else if (error == TRANSMISSION_ERROR)
	{
		ft_putstr_fd("Not able to send the string. Please check that: \n", 1);
		ft_putstr_fd("1) the server is running and \n2) the PID given is ", 1);
		ft_putstr_fd("the correct one.\n", 1);
	}
	else if (error == NO_FEEDBACK)
	{
		ft_putstr_fd("Not getting any confirmation signal from the server", 1);
		ft_putstr_fd("The message might have been lost in transit. ", 1);
		ft_putstr_fd("Exiting now.\n", 1);
	}
	exit(1);
}

void	print_confirmation(int signal, siginfo_t *info, void *ucontext)
{
	(void)signal;
	(void)info;
	(void)ucontext;
	ft_putstr_fd("The server just confirmed the reception of the string. ", 1);
	ft_putstr_fd("Exiting now.\n", 1);
	exit(0);
}
