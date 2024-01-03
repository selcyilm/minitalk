#include "minitalk.h"

void	handler(int signum)
{
	static int	i = 0;
	static int	bit = 0;

	if (signum == SIGUSR1)
	{
		i |= 0x01 << bit;
		bit++;
	}
	else if (signum == SIGUSR2)
		bit++;
	if (bit == 8)
	{
		printf("%c", i);
		bit = 0;
		i = 0;
	}
}

int	main(void)
{
	int	pid;

	pid = getpid();
	printf("PID IS %d\nWaiting for message..\n", pid);
	while(1)
	{
		signal(SIGUSR1, handler);
		signal(SIGUSR2, handler);
		pause();
	}
	return (0);
}