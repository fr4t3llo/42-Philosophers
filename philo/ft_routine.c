/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_routine.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skasmi <skasmi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 19:26:32 by skasmi            #+#    #+#             */
/*   Updated: 2022/07/07 21:50:15 by skasmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_complet_routine(t_philo *philo, long start)
{
	pthread_mutex_lock(&philo->forks);
	printf("%ld philo \033[0;36m%d \033[0;37m-> has taken right fork\n",
		ft_get_time()
		- philo->data_of_shared->time_simulation, philo->id_philo);
	pthread_mutex_lock(&philo->next->forks);
	printf("%ld philo \033[0;36m%d \033[0;37m-> has taken left fork\n",
		ft_get_time()
		- philo->data_of_shared->time_simulation, philo->id_philo);
	printf("%ld philo \033[0;36m%d \033[0;37m-> is eating\n",
		ft_get_time()
		- philo->data_of_shared->time_simulation, philo->id_philo);
	philo->number_of_meal++;
	start = ft_get_time();
	while (ft_get_time() - start < philo->data_of_shared->time_to_eat)
		usleep(100);
}

void	ft_routine_small(t_philo	*philo)
{
	long	start;

	while (philo->data_of_shared->death != 1)
	{
		ft_complet_routine(philo, start);
		philo->time_last_meal = ft_get_time();
		pthread_mutex_unlock(&philo->forks);
		pthread_mutex_unlock(&philo->next->forks);
		if (philo->number_of_meal == philo->data_of_shared->number_of_eat)
			philo->data_of_shared->if_full++;
		if (philo->data_of_shared->if_full == philo->data_of_shared->philo_init)
			break ;
		printf("%ld philo \033[0;36m%d \033[0;37m-> is sleeping\n",
			ft_get_time()
			- philo->data_of_shared->time_simulation, philo->id_philo);
		start = ft_get_time();
		while (ft_get_time() - start < philo->data_of_shared->time_to_sleep)
			usleep(100);
		printf("%ld philo \033[0;36m%d \033[0;37m-> is thinking\n",
			ft_get_time()
			- philo->data_of_shared->time_simulation, philo->id_philo);
	}
}

void	*routine(void *av)
{
	t_philo	*philo;

	philo = (t_philo *)av;
	if (philo->id_philo % 2 == 0)
		usleep(500);
	ft_routine_small(philo);
	return (NULL);
}
