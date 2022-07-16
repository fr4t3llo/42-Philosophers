/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skasmi <skasmi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 15:32:49 by skasmi            #+#    #+#             */
/*   Updated: 2022/07/07 21:45:54 by skasmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	loop(t_philo *philos)
{
	while (1)
	{
		if ((ft_get_time()) - philos->time_last_meal
			> philos->data_of_shared->time_to_die)
		{
			philos->data_of_shared->death = 1;
			printf("%ld philo %d -> is died\n", ft_get_time()
				- philos->data_of_shared->time_simulation, philos->id_philo);
			break ;
		}
		if (philos->data_of_shared->if_full
			== philos->data_of_shared->philo_init)
		{
			philos->data_of_shared->death = 1;
			return ;
		}
		philos = philos->next;
		usleep(500);
	}
}

void	init_shared(t_shared *t, char	**av, int ac)
{
	int	i;

	i = 0;
	t->philo_init = ft_atoi(av[1]);
	t->time_to_die = ft_atoi(av[2]);
	t->time_to_eat = ft_atoi(av[3]);
	t->time_to_sleep = ft_atoi(av[4]);
	t->death = 0;
	t->time_simulation = ft_get_time();
	t->number_of_eat = -1;
	if (ac == 6)
		t->number_of_eat = ft_atoi(av[5]);
	t->if_full = 0;
}

void	ft_lstaddback(t_philo **philo, t_philo *new)
{
	t_philo	*tmp;

	tmp = *philo;
	if (!*philo)
	{
		*philo = new;
	}
	else
	{
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
	}
}

t_philo	*ft_lstnew(t_shared *t, int i)
{
	t_philo	*philo;

	philo = (t_philo *)malloc(sizeof(t_philo));
	philo->id_philo = i + 1;
	philo->number_of_meal = 0;
	philo->time_last_meal = t->time_simulation;
	pthread_mutex_init(&philo->forks, NULL);
	philo->data_of_shared = t;
	philo->next = NULL;
	return (philo);
}

int	main(int ac, char **av)
{
	t_shared	t;
	t_philo		*philo;

	philo = NULL;
	if (!(ac == 5 || ac == 6))
		return (1);
	if (!ft_chech_isdigit(av))
		return (0);
	if (ft_parss(av) == 0)
		return (0);
	if (ft_check_philo(ft_atoi(av[1])) == 0)
		return (0);
	init_shared(&t, av, ac);
	ft_create_philo(&t, &philo);
	ft_create_thread(&t, philo);
	loop(philo);
	return (0);
}
