/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_routine.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skasmi <skasmi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 17:25:47 by skasmi            #+#    #+#             */
/*   Updated: 2022/07/07 17:44:08 by skasmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	ft_eat(t_philo *philo)
{
	sem_wait(philo->data->fork);
	print_stamp(FORK_STMP, ft_gettime() - philo->data->t_start, philo);
	sem_wait(philo->data->fork);
	print_stamp(FORK_STMP, ft_gettime() - philo->data->t_start, philo);
	print_stamp(EAT_STMP, ft_gettime() - philo->data->t_start, philo);
	philo->n_meals++;
	philo->last_meal = ft_gettime();
	ft_usleep(philo->data->t_eat);
	sem_post(philo->data->fork);
	sem_post(philo->data->fork);
}

void	ft_sleeping(t_philo *philo)
{
	print_stamp(SLEEP_STMP, ft_gettime() - philo->data->t_start, philo);
	ft_usleep(philo->data->t_sleep);
}

void	ft_thinking(t_philo *philo)
{
	print_stamp(THINK_STMP, ft_gettime() - philo->data->t_start, philo);
}

void	ft_routine(void *philos)
{
	t_philo	*back_up;

	back_up = (t_philo *)philos;
	pthread_create(&back_up->thread, NULL, (void *)check_full, back_up);
	if (back_up->id % 2 == 0)
		usleep(500);
	while (back_up->data->if_die == 0)
	{
		ft_eat(back_up);
		if (back_up->data->satiety)
			break ;
		ft_sleeping(back_up);
		ft_thinking(back_up);
	}
	if (back_up->data->satiety == 1)
		ft_exit(1, back_up->data->head);
	if (back_up->data->if_die == 1)
		ft_exit(0, back_up->data->head);
}
