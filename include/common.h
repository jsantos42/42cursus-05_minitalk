#ifndef COMMON_H
# define COMMON_H

# include <signal.h>
# include "../libs/libft/libft.h"

# define INVALID_INPUT -1
# define TRANSMISSION_ERROR -2
# define NO_FEEDBACK	-3

typedef struct s_static {
	int	iter;
	int	bin[8];
}	t_static;

// Client:
void	convert_to_binary_and_send(int *bin, unsigned char letter, int pid);
int		send_binary(int *bin, int pid);
int		error_handler(int error);
void	print_confirmation(int signal, siginfo_t *info, void *ucontext);

// Server:
void	save_to_array(int signal, siginfo_t *info, void *ucontext);
int		decimal_conv(int *bin);

#endif
