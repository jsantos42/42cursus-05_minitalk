#ifndef COMMON_H
#define COMMON_H

#include <unistd.h>
#include <signal.h>
#include "libft/libft.h"

void	convert_to_binary_and_send(int *bin, int letter, int pid);
void	send_binary(int *bin, int pid);
void	save_to_array(int signal);
int		decimal_conv(int *bin);

#endif
