#ifndef MINITALK_COMMON_H
#define MINITALK_COMMON_H

#include <unistd.h>
#include <signal.h>
#include "libft/libft.h"

//delete the following 3
#include <stdio.h>  //this can go
//#include <stdlib.h>  //this can go
#include <string.h>

void	binary_conv(int *bin, int letter);
void	send_binary(int *bin, int pid);
void	save_to_array(int signal);
int	decimal_conv(int *bin);

#endif //MINITALK_COMMON_H
