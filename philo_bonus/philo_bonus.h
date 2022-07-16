/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skasmi <skasmi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/02 17:11:26 by skasmi            #+#    #+#             */
/*   Updated: 2022/07/07 17:53:09 by skasmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H

# include <libc.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <string.h>
# include <limits.h>
# include <sys/time.h>
# include <pthread.h>
# include <semaphore.h>

# define FORK_STMP "%ld philo \033[0;36m%d \033[0;37m-> has taken fork\n"
# define EAT_STMP "%ld philo \033[0;36m%d \033[0;37m-> is eating\n"
# define SLEEP_STMP "%ld philo \033[0;36m%d \033[0;37m-> is sleeping\n"
# define THINK_STMP "%ld philo \033[0;36m%d \033[0;37m-> is thinking\n"
# define DIE_STMP "%ld philo %d -> is died\n"

typedef struct s_data
{
	int				nbr_philo;
	int				t_die;
	int				t_eat;
	int				t_sleep;
	int				max_meals;
	int				if_die;
	long			t_start;
	int				satiety;
	struct s_philo	*head;
	sem_t			*fork;
	sem_t			*print;
}	t_data;

typedef struct s_philo
{
	int				id;
	int				pid;
	long			last_meal;
	int				n_meals;
	t_data			*data;
	pthread_t		thread;
	struct s_philo	*next;
}	t_philo;

t_philo	*ft_lstnew(int id, t_data *data);
t_philo	*ft_lstlast(t_philo *lst);
void	ft_lstadd_back(t_philo **lst, t_philo *new);
int		error(void);
int		arg_error(char *arg);
void	ft_null(void);
void	int_error(void);
int		check_args(int ac, char **av);
void	check_full(void *philo); // satiety
void	ft_exit(int status, t_philo *lst);
void	print_stamp(char *str, long time, t_philo *philo);
long	ft_gettime(void);
int		arg_null(t_data *data); //null arg
void	ft_usleep(int time);
void	ft_free(t_philo *philos); // free_stc
int		ft_init_philo(int ac, char **av, t_data **data); // data init
void	ft_create_table(char **av, t_philo **lst, t_data *data); // create_table
void	ft_create_philo(t_philo **philos); // philo_birth
void	ft_eat(t_philo *philo); // eating
void	ft_sleeping(t_philo *philo); //sleeping
void	ft_thinking(t_philo *philo); // thinking
void	ft_routine(void *philos); // routine

//************* libft_function ***************
int		ft_isdigit(int c);
int		ft_atoi_max(const char *str);
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);
size_t	ft_strlen(const char *s);
void	*ft_calloc(size_t count, size_t size);
char	*ft_strchr(const char *s, int c);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
char	*ft_strtrim(char const *s1, char const *set);

#endif
