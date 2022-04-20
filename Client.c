/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoukhart <aoukhart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 14:45:27 by aoukhart          #+#    #+#             */
/*   Updated: 2022/04/11 15:00:06 by aoukhart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Minitalk.h"

void	send_char(pid_t pid, char *str)
{
	int	i;
	int	j;
	int	bit;

	i = 0;
	while (str[i])
	{
		j = 0;
		bit = 128;
		while (j < 8)
		{
			if ((str[i] & bit) == bit)
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			usleep(500);
			bit = bit >> 1;
			j++;
		}
		i++;
	}
}

int	main(int ac, char **av)
{
	pid_t	pid;

	if (ac == 3)
	{
		pid = ft_atoi(av[1]);
		send_char(pid, av[2]);
		send_char(pid, "\n");
	}
	else
		write(2, "Check Number Of Arguments !!", 29);
	return (0);
}
