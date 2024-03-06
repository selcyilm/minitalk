/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   server.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: selcyilm <selcyilm@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/01/03 21:43:56 by selcyilm      #+#    #+#                 */
/*   Updated: 2024/03/06 13:58:58 by selcyilm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk.h"

void	handler(int signum)
{
	static char	i = 0;
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
		ft_putchar(i);
		bit = 0;
		i = 0;
	}
}

int	main(void)
{
	int	pid;

	pid = getpid();
	ft_putstr("PID IS ");
	ft_putnbr(pid);
	ft_putstr(" Waiting for message..\n");
	while (1)
	{
		signal(SIGUSR1, handler);
		signal(SIGUSR2, handler);
		pause();
	}
	return (0);
}
