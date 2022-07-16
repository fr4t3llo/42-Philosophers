/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skasmi <skasmi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 15:26:09 by skasmi            #+#    #+#             */
/*   Updated: 2022/07/07 21:51:01 by skasmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_isdigit(int nb)
{
	if (nb <= '9' && nb >= '0')
		return (1);
	return (0);
}

int	ft_chech_isdigit(char **str)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	while (str[i])
	{
		j = 0;
		while (str[i][j] != '\0')
		{	
			if (ft_isdigit(str[i][j]) == 0)
			{
				printf("\033[0;31mError arg !!");
				return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}

int	ft_parss(char **s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i][0] == '\0')
			return (0);
		i++;
	}
	return (1);
}

int	ft_atoi(const char *str)
{
	int	i;
	int	m;
	int	w;

	w = 1;
	i = 0;
	m = 0;
	while (str[i] && (str[i] == ' ' || str[i] == '\n'
			|| str[i] == '\t' || str[i] == '\v'
			|| str[i] == '\r' || str[i] == '\f'))
		i++;
	if (str[i] && (str[i] == '-' || str[i] == '+'))
	{
		if (str[i] == '-')
		{
			w = w * (-1);
		}
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		m = (m * 10) + (str[i] - 48);
		i++;
	}
	return (m * w);
}

int	ft_check_philo(int nb)
{
	if (nb <= 0)
		return (0);
	return (1);
}
