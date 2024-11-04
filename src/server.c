/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   server.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: selcyilm <selcyilm@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/01/03 21:43:56 by selcyilm      #+#    #+#                 */
/*   Updated: 2024/01/04 10:33:40 by selcyilm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk.h"

void handler(int sig)
{
	static char	c = 0;
	static int	i = 0;

	if (sig == SIGUSR1)
		i++;
	if (sig == SIGUSR2)
	{
		c |= 1 << i;
		i++;
	}
	if (i == 8)
	{
		ft_putchar_fd(i, 1);
		c = 0;
		i = 0;
	}
}

int	main(void)
{
	int	pid;

	struct sigaction sa;
	sa.sa_handler = handler;
	sa.sa_flags = SA_RESTART;
	pid = getpid();
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	printf("PID IS %d\nWaiting for message..\n", pid);
	while (1)
		pause();
	return (0);
}
