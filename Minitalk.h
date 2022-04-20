/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoukhart <aoukhart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 14:22:11 by aoukhart          #+#    #+#             */
/*   Updated: 2022/04/11 15:16:57 by aoukhart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <unistd.h>
# include <stdio.h>
# include <signal.h>
# include <stdlib.h>

char	*ft_fill(unsigned int x, int n, unsigned int size, char *str);
char	*ft_itoa(int n);
int		ft_strlen(char *s);
char	*ft_strdup(char *s1);
int		ft_atoi(const char *nptr);

#endif