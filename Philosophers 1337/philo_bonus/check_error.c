/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skasmi <skasmi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/02 17:10:34 by skasmi            #+#    #+#             */
/*   Updated: 2022/07/07 17:37:50 by skasmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	error(void)
{
	ft_putendl_fd("\033[33m-- USAGE ERROR --\033[0m", 2);
	return (1);
}

int	arg_error(char *arg)
{
	free(arg);
	ft_putendl_fd("\033[33m-- ARG ERROR --\033[0m", 2);
	return (1);
}

void	ft_null(void)
{
	ft_putendl_fd("\033[31m-- NULL ARG --\033[0m", 2);
}

void	int_error(void)
{
	ft_putendl_fd("\033[31m-- MAX INT --\033[0m", 2);
}
