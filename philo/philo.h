/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macarval <macarval@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 18:27:01 by macarval          #+#    #+#             */
/*   Updated: 2023/11/27 01:16:38 by macarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <pthread.h>
# include <sys/time.h>
# include <time.h>

typedef struct s_watch
{
	pthread_mutex_t	mutex;
	int				philo_died;
}	t_watch;

typedef struct s_fork
{
	pthread_mutex_t	mutex_fork;
	int				id;
	int				avaliable;

}	t_fork;

typedef struct s_data
{
	long int		t_die;
	long int		t_eat;
	long int		t_sleep;
	int				n_times;
}	t_data;

typedef struct s_philo
{
	int				id;
	long int		last_eat;
	int				n_times_eat;
	void			*table;
}	t_philo;

typedef struct s_table
{
	int				n_philos;
	t_data			*data;
	struct timeval	start;
	t_fork			*forks;
	t_philo			*philos;
	pthread_t		*threads;
	t_watch			*watcher;
	pthread_mutex_t	mutex_print;
}	t_table;

// philo.c
void		free_table(t_table *table);
int			only_philo(t_table	*table);
int			verify_args(int argc, char *argv[]);

// create.c
void		create_forks(t_table *table);
void		create_philo(t_table *table);
void		create_data(t_table *table, int argc, char *argv[]);
void		create_table(t_table *table, int argc, char *argv[]);

// forks.c
int			check_dead(t_philo *philo, t_table *table);
int			get_fork(int *var, pthread_mutex_t *mutex);
void		return_forks(t_table *table, int r_fork, int l_fork);
int			take_forks(t_philo *philo, t_table *table, int r_fork, int l_fork);

// life.c
void		action(t_philo *philo);
void		eating(t_philo *philo, t_table *table);
void		sleeping(t_philo *philo, t_table *table);
void		print_life(t_philo *philo, char *msg, int is_eat);

// threads.c
int			final_eat(t_table *table);
void		*observer_threads(void *arg);
int			manage_threads(t_table *table);
pthread_t	*create_threads(t_table *table);
int			join_threads(t_table *table);

// time.c
void		*init(void *arg);
long int	get_now(struct timeval *start);
int			read_mutex(int	*var, pthread_mutex_t *mutex);
long int	time_diff(struct timeval *start, struct timeval *end);
void		write_mutex(int *var, pthread_mutex_t *mutex, int value);

// utils.c
int			is_digit(char *argv);
int			ft_atoi(const char *str);

#endif
