/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skasmi <skasmi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 17:20:23 by skasmi            #+#    #+#             */
/*   Updated: 2022/07/07 17:41:12 by skasmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	loop(t_philo *philos)
{
	int		r;
	t_philo	*node;

	r = 0;
	node = philos;
	while (philos)
	{
		waitpid(-1, &r, 0);
		if (r == 0)
		{
			while (node)
			{
				kill(node->pid, SIGKILL);
				node = node->next;
			}
			ft_exit(0, philos->data->head);
		}
		else
			philos = philos->next;
	}
}

int	main(int ac, char **av)
{
	t_philo	*philos;
	t_data	*data;

	if (ac < 5 || ac > 6)
		if (error())
			return (1);
	if (check_args(ac, av))
		return (1);
	if (ft_init_philo(ac, av, &data))
		return (1);
	ft_create_table(av, &philos, data);
	ft_create_philo(&philos);
	loop(philos);
	return (0);
}
