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

void	ft_error(int err)
{
	ft_putstr_fd("Error: ", 1);
	if (err == 0)
		ft_putstr_fd("Missing arguments\n", 1);
	if (err == 1)
		ft_putstr_fd("Invalid PID\n", 1);
	if (err == 2)
		ft_putstr_fd("Invalid Message\n", 1);
	exit(1);
}

void	send_signal(int pid, char c)
{
	static int	i = 0;

	while (i < 8)
	{
		if ((c >> i) & 1)
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
		usleep(77);
		i++;
	}
	if (i == 8)
		i = 0;
}

int	main(int ac, char **av)
{
	int		pid;
	int		i;

	if (ac != 3)
		ft_error(0);
	pid = atoi(av[1]);
	if (pid <= 0)
		ft_error(1);
	if (!av[2])
		ft_error(2);
	i = 0;
	while (av[2][i])
	{
		send_signal(pid, av[2][i]);
		i++;
	}
	send_signal(pid, 0);
	return (0);
}
