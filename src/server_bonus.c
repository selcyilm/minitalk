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

#include "../include/minitalk_bonus.h"

void	error_sending_signal(void)
{
	ft_printf("Error sending signal.\n");
	exit(2);
}

void	handler(int sig, siginfo_t *client, void *context)
{
	static char	c = 0;
	static int	i = 0;

	(void) context;
	c <<= 1;
	if (sig == SIGUSR2)
		c |= 1;
	i++;
	if (i == 8 && c)
	{
		ft_printf("%c", c);
		c = 0;
		i = 0;
	}
	else if (i == 8 && !c)
	{
		if (kill(client->si_pid, SIGUSR2) == -1)
			error_sending_signal();
		i = 0;
	}
	if (kill(client->si_pid, SIGUSR1) == -1)
		error_sending_signal();
}

int	main(void)
{
	struct sigaction	sa;

	sa.sa_flags = SA_SIGINFO | SA_NODEFER;
	sa.sa_sigaction = handler;
	sigemptyset(&sa.sa_mask);
	if (sigaction(SIGUSR1, &sa, NULL) == -1)
		return (1);
	if (sigaction(SIGUSR2, &sa, NULL) == -1)
		return (1);
	ft_printf("PID: %d\nWaiting for Message...\n", getpid());
	while (1)
		pause();
}
