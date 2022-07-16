/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skasmi <skasmi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 15:37:58 by skasmi            #+#    #+#             */
/*   Updated: 2022/07/06 20:21:55 by skasmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long	ft_get_time(void)
{
	struct timeval	current_time;
	long			time;

	gettimeofday(&current_time, NULL);
	time = (current_time.tv_sec * 1000) + (current_time.tv_usec / 1000);
	return (time);
}

void	ft_create_philo(t_shared *t, t_philo **philo)
{
	int		i;
	t_philo	*tmp;

	i = 0;
	while (i < t->philo_init)
	{
		tmp = ft_lstnew(t, i);
		ft_lstaddback(philo, tmp);
		i++;
	}
	tmp->next = *philo;
}

void	ft_create_thread(t_shared *t, t_philo *philo)
{
	int	i;

	i = 0;
	while (i < t->philo_init)
	{
		pthread_create(&philo->thread_id, NULL, &routine, philo);
		philo = philo->next;
		i++;
	}
	i = 0;
}
