#include "common.h"

int main(int argc, char **argv)
{
	int		pid;
	char	*str;
	size_t	size;
	int		bin[8];
	int iter = 0; /// delete this one

	if (argc != 3)
		return (1);
	pid = ft_atoi(argv[1]);
	size = ft_strlen(argv[2]);
	str = malloc(sizeof(char) * (size + 1));
	ft_strlcpy(str, argv[2], size + 1);
	while (*str)
	{
		printf("reading char number %d\n", iter); ///delete these two
		iter++;

		binary_conv(bin, *str);
		send_binary(bin, pid);
		str++;
	}
	binary_conv(bin, *str);
	send_binary(bin, pid);
	return 0;
}

void	binary_conv(int *bin, int letter)
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
}

void	send_binary(int *bin, int pid)
{
	int	iter;

	iter = 0;
	while (iter < 8)
	{
		if (bin[iter] == 0)
		{
			kill(pid, SIGUSR1);
			printf("sending signal number %d, which is %d\n", iter, SIGUSR1); ///delete this one
		}
		else
		{
			kill(pid, SIGUSR2);
			printf("sending signal number %d, which is %d\n", iter, SIGUSR2); ///delete this one
		}


		iter++;
	}
}