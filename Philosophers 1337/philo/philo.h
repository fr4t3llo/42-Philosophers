/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skasmi <skasmi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 15:25:46 by skasmi            #+#    #+#             */
/*   Updated: 2022/07/07 21:51:19 by skasmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>

typedef struct s_shared
{
	int				philo_init;
	int				time_to_eat;
	int				time_to_die;
	int				time_to_sleep;
	int				number_of_eat;
	long			time_simulation;
	int				death;
	int				if_full;
	struct s_philo	*head;
}	t_shared;

typedef struct s_philo
{
	long			time_last_meal;
	int				id_philo;
	int				number_of_meal;
	pthread_mutex_t	forks;
	pthread_t		thread_id;
	t_shared		*data_of_shared;
	struct s_philo	*next;
}	t_philo;

t_philo		*ft_lstnew(t_shared *t, int i);
void		ft_lstaddback(t_philo **philo, t_philo *new);
int			ft_isdigit(int nb);
int			ft_atoi(const char *str);
int			ft_chech_isdigit(char **str);
int			ft_check_philo(int nb);
void		*routine(void *av);
long		ft_get_time(void);
void		init_shared(t_shared *t, char	**av, int ac);
void		ft_create_thread(t_shared *t, t_philo *philo);
void		ft_create_philo(t_shared *t, t_philo **philo);
int			ft_parss(char **s);

#endif
