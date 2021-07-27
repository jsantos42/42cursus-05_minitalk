#include "common.h"
//#include <time.h>
//#include <stdio.h>

int main(int argc, char **argv)
{
	int		pid;
	char	*str;
	size_t	size;
	int		bin[8];

//	clock_t begin = clock();
	if (argc != 3)
		error_handler(INVALID_INPUT);
	pid = ft_atoi(argv[1]);
	size = ft_strlen(argv[2]);
	str = malloc(sizeof(char) * (size + 1)); //this malloc is probably not needed, and the same applies to the free
	ft_strlcpy(str, argv[2], size + 1);
	while (*str)
	{
		convert_to_binary_and_send(bin, *str, pid);
		str++;
	}
	convert_to_binary_and_send(bin, '\0', pid);
	free(str);
//	clock_t end = clock();
//	double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
//	printf("%f\n", time_spent);

	sleep(5); ///wait for feedback
///error_handler
//	return (0);
}

void	convert_to_binary_and_send(int *bin, int letter, int pid)
{
	int base_2;
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
	send_binary(bin, pid);
}

void	send_binary(int *bin, int pid)
{
	int	iter;

	iter = 0;
	while (iter < 8)
	{
		if (bin[iter] == 0)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(100);
		iter++;
	}
}


int	error_handler(int error)
{
	if (error == INVALID_INPUT)
		ft_putstr_fd("Invalid input\n", 1);
	exit(1);
}