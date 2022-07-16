/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skasmi <skasmi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/02 17:28:41 by skasmi            #+#    #+#             */
/*   Updated: 2022/07/07 17:50:57 by skasmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	ft_init_philo(int ac, char **av, t_data **data)
{
	(*data) = (t_data *)malloc(sizeof(t_data));
	if (!(*data))
		return (1);
	(*data)->if_die = 0;
	(*data)->nbr_philo = ft_atoi_max(av[1]);
	(*data)->t_die = ft_atoi_max(av[2]);
	(*data)->t_eat = ft_atoi_max(av[3]);
	(*data)->t_sleep = ft_atoi_max(av[4]);
	if (ac == 6)
		(*data)->max_meals = ft_atoi_max(av[5]);
	else if (ac == 5)
		(*data)->max_meals = -1;
	(*data)->satiety = 0;
	(*data)->head = NULL;
	if (arg_null(*data))
	{
		free(*data);
		return (1);
	}
	(*data)->t_start = 0;
	sem_unlink("fork");
	sem_unlink("print");
	(*data)->fork = sem_open("fork", O_CREAT, 666, (*data)->nbr_philo);
	(*data)->print = sem_open("print", O_CREAT, 666, 1);
	return (0);
}

void	ft_create_table(char **av, t_philo **lst, t_data *data)
{
	int		i;
	t_philo	*node;

	i = 0;
	while (++i <= ft_atoi_max(av[1]))
	{
		node = ft_lstnew(i, data);
		ft_lstadd_back(lst, node);
		if (i == 1)
			data->head = node;
	}
}

void	ft_create_philo(t_philo **philos)
{
	t_philo	*head;

	head = *philos;
	head->data->t_start = ft_gettime();
	while (head)
	{
		head->pid = fork();
		if (head->pid < 0)
			return ;
		if (head->pid == 0)
		{
			head->last_meal = ft_gettime();
			ft_routine(head);
		}
		else
			head = head->next;
	}
}
