/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoukhart <aoukhart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 15:00:49 by aoukhart          #+#    #+#             */
/*   Updated: 2022/04/11 15:30:57 by aoukhart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Minitalk.h"

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_fill(unsigned int x, int n, unsigned int size, char *str)
{
	unsigned int	x1;
	unsigned int	i;

	x1 = x;
	i = 0;
	while (x1 != 0 && ++size)
		x1 /= 10;
	if (n < 0)
		size++;
	str = malloc((size + 1) * sizeof(char));
	if (!str)
		return (NULL);
	str[size] = '\0';
	while (size > 0 && x > 0)
	{
		str[size - 1] = ((x % 10) + 48);
		x /= 10;
		size--;
	}
	if (n < 0)
		str[0] = '-';
	return (str);
}

char	*ft_itoa(int n)
{
	char			*str;
	unsigned int	x;
	unsigned int	size;

	str = NULL;
	if (n < 0)
		x = n * -1;
	else
		x = n;
	if (n == 0)
		return (ft_strdup("0"));
	size = 0;
	return (ft_fill(x, n, size, str));
}

char	*ft_strdup(char *s1)
{
	char	*copy;
	int		i;

	i = 0;
	copy = malloc((ft_strlen(s1) + 1) * sizeof(char));
	if (!copy)
		return (NULL);
	while (s1[i])
	{
		copy[i] = s1[i];
		i++;
	}
	copy[i] = '\0';
	return (copy);
}

int	ft_atoi(const char *nptr)
{
	int	ret;
	int	i;
	int	sign;

	ret = 0;
	sign = 1;
	i = 0;
	while (nptr[i] == '\t' || nptr[i] == '\n' || nptr[i] == '\v'
		|| nptr[i] == '\f' || nptr[i] == '\r' || nptr[i] == ' ')
	{
		i++;
	}
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			sign *= -1;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
		ret = (ret * 10) + (nptr[i++] - '0');
	return (ret * sign);
}
