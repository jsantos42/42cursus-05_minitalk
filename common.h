#ifndef COMMON_H
#define COMMON_H

#include <unistd.h>
#include <signal.h>
#include "libft/libft.h"

typedef struct s_static {
	int	iter;
	int	bin[8];
}	t_static;

void	convert_to_binary_and_send(int *bin, int letter, int pid);
void	send_binary(int *bin, int pid);
void	save_to_array(int signal);
int		decimal_conv(int *bin);

#endif
