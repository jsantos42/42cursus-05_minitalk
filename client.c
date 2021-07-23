#include <unistd.h>
#include <signal.h>
//delete the following 3
#include <stdio.h>  //this can go
#include <stdlib.h>  //this can go
#include <string.h>

void function(char *str)
{
	printf("%s", str);
}

int main(int argc, char **argv)
{
	int		pid;
	char	*str;

	if (argc != 3)
		return (1);
	pid = atoi(argv[1]); // replace with my atoi function
	str = strcpy(str, argv[2]); //replace with my strcpy function
//	signal(pid, function(str));
//	kill(pid, 9);


    return 0;
}
