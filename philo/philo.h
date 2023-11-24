/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macarval <macarval@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 18:27:01 by macarval          #+#    #+#             */
/*   Updated: 2023/11/24 19:09:21 by macarval         ###   ########.fr       */
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

// # define TAKEN 1
// # define EAT 2
// # define SLEEP 3
// # define THINK 4
// # define DIED 5

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
	int				t_die;
	int				t_eat;
	int				t_sleep;
	int				n_times;
}	t_data;

typedef struct s_philo
{
	int				id;
	int				hand_forks;
	int				last_eat;
	struct timeval	start;
	t_watch			*watch;
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
}	t_table;



// philo.c
int			only_philo(t_table	*table);
int			verify_args(int argc, char *argv[]);

// create.c
void		create_forks(t_table *table);
void		create_philo(t_table *table);
void		create_data(t_table *table, int argc, char *argv[]);
void		create_table(t_table *table, int argc, char *argv[]);

// life.c
void		action(t_philo *philo);
int			eating(t_philo *philo, t_table *table);
int			sleeping(t_philo *philo, t_table *table);
int			thinking(t_philo *philo, t_table *table);

// threads.c
void		*observer_threads(void *arg);
int			manage_threads(t_table *table);
pthread_t	*create_threads(t_table *table);
int			join_threads(t_table *table);

// time.c
void		*init(void *arg);
long int	time_diff(struct timeval *start, struct timeval *end);

// utils.c
int			is_digit(char *argv);
int			ft_atoi(const char *str);

#endif
