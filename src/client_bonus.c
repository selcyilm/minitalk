/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   client.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: selcyilm <selcyilm@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/01/03 21:43:50 by selcyilm      #+#    #+#                 */
/*   Updated: 2024/01/04 10:33:23 by selcyilm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk.h"

int	g_signal_recieved;

void	error_msg(int err)
{
	if (err == 1)
		ft_printf("Error: Missing Argument.\n");
	else if (err == 2)
		ft_printf("Error: No Message input.\n");
	else if (err == 3)
		ft_printf("Error: Invalid PID.\n");
	else if (err == 4)
		ft_printf("Error: Error sending message!\n");
	exit(1);
}

void	send_signal(int pid, char c)
{
	int	i;
	int	bit;

	bit = 0;
	i = 7;
	while (i >= 0)
	{
		bit = (c >> i) & 1;
		if (bit == 1)
		{
			if (kill(pid, SIGUSR2) == -1)
				error_msg(4);
		}
		else
		{
			if (kill(pid, SIGUSR1) == -1)
				error_msg(4);
		}
		while (g_signal_recieved == 0)
			;
		g_signal_recieved = 0;
		i--;
	}
}

void	recieved_hnd(int signum)
{
	(void) signum;
	g_signal_recieved = 1;
}

void	succes_handler(int signum)
{
	(void) signum;
	ft_printf("The message has been recieved!\n");
	exit(EXIT_SUCCESS);
}

int	main(int ac, char **av)
{
	int	pid;
	int	i;

	if (ac != 3)
		error_msg(1);
	if (!ft_strlen(av[2]))
		error_msg(2);
	i = 0;
	while (av[1][i])
	{
		if (!ft_isdigit(av[1][i]))
			error_msg(3);
		i++;
	}
	pid = ft_atoi(av[1]);
	signal(SIGUSR1, &recieved_hnd);
	signal(SIGUSR2, &succes_handler);
	i = 0;
	while (av[2][i])
		send_signal(pid, av[2][i++]);
	send_signal(pid, 0);
}
