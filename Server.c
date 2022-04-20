/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoukhart <aoukhart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 14:24:23 by aoukhart          #+#    #+#             */
/*   Updated: 2022/04/11 15:18:24 by aoukhart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Minitalk.h"

void	sig_handler(int signum)
{
	static char	c;
	static int	count;

	if (signum == SIGUSR1)
	{
		c += 128 >> count;
		count++;
	}
	else
		count++;
	if (count == 8)
	{
		write(1, &c, 1);
		count = 0;
		c = 0;
	}
}

int	main(void)
{
	pid_t	pid;

	pid = getpid();
	write(1, ft_itoa(pid), ft_strlen(ft_itoa(pid)));
	signal(SIGUSR1, sig_handler);
	signal(SIGUSR2, sig_handler);
	while (42)
		pause();
	return (0);
}
