#ifndef COMMON_H
#define COMMON_H

#include <unistd.h>
#include <signal.h>
#include "libft/libft.h"

#define	INVALID_INPUT -1

typedef struct s_static {
	int	iter;
	int	bin[8];
}	t_static;

void	convert_to_binary_and_send(int *bin, unsigned char letter, int pid);
void	send_binary(int *bin, int pid);
void	save_to_array(int signal, siginfo_t *info, void *ucontext);
int		decimal_conv(int *bin);
int	error_handler(int error);
void	print_confirmation(int signal, siginfo_t *info, void *ucontext);

#endif
