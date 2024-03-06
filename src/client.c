/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   client.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: selcyilm <selcyilm@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/01/03 21:43:50 by selcyilm      #+#    #+#                 */
/*   Updated: 2024/01/05 15:50:07 by selcyilm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk.h"

void	ft_error(int err)
{
	ft_putstr("Error: ");
	if (err == 0)
		ft_putstr("Missing arguments\n");
	if (err == 1)
		ft_putstr("Invalid PID\n");
	if (err == 2)
		ft_putstr("Invalid Message\n");
	exit(1);
}

void	send_signal(int pid, char c)
{
	static int	i;

	i = 0;
	while (i < 8)
	{
		if (c & (0x01 << i))
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(100);
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
	pid = ft_atoi(av[1]);
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
