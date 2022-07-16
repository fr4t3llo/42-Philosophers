/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skasmi <skasmi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/02 17:27:40 by skasmi            #+#    #+#             */
/*   Updated: 2022/07/07 21:52:04 by skasmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	print_stamp(char *str, long time, t_philo *philo)
{
	if (philo->data->if_die)
	{
		sem_wait(philo->data->print);
		printf(str, time, philo->id);
	}
	else
	{
		sem_wait(philo->data->print);
		printf(str, time, philo->id);
		sem_post(philo->data->print);
	}
}

int	arg_null(t_data *data)
{
	if (!data->nbr_philo || !data->t_die || !data->t_eat \
			|| !data->t_sleep || data->max_meals == 0)
	{
		error();
		return (1);
	}
	if (data->nbr_philo == -1 || data->t_die == -1 || data->t_eat == -1 \
			|| data->t_sleep == -1 || data->max_meals == 0)
	{
		int_error();
		return (1);
	}
	return (0);
}

long	ft_gettime(void)
{
	struct timeval	tp;
	long			time;

	gettimeofday(&tp, NULL);
	time = tp.tv_sec * 1000 + tp.tv_usec / 1000;
	return (time);
}

void	ft_usleep(int time)
{
	long	start;

	start = ft_gettime();
	while (ft_gettime() - start <= time)
		usleep(100);
}

void	ft_free(t_philo *philos)
{
	t_philo	*back_up;

	while (philos)
	{
		back_up = philos->next;
		sem_close(philos->data->print);
		sem_close(philos->data->fork);
		free(philos);
		philos = back_up;
		if (philos && !philos->next)
			free(philos->data);
	}
}
