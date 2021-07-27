#include "common.h"

int	error_handler(int error)
{
	ft_putstr_fd("ERROR: ", 1);
	if (error == INVALID_INPUT)
		ft_putstr_fd("Invalid input. Please try: ./client <PID> <string to send>.\n", 1);
	else if (error == TRANSMISSION_ERROR)
		ft_putstr_fd("Not able to send the string. Please check that: \n1) the"
					 " server is running and \n2) the PID given is the correct one.\n",
					 1);
	else if (error == NO_FEEDBACK)
		ft_putstr_fd("Not getting any confirmation message from the server, "
					 "the message might have been lost in transit. Exiting now.\n", 1);
	exit(1);
}

void	print_confirmation(int signal, siginfo_t *info, void *ucontext)
{
	(void)info;
	(void)ucontext;
	ft_putstr_fd("Server just confirmed reception of the string. Exiting now.", 1);
	exit(1);
}
