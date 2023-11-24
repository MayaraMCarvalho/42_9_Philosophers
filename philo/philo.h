/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macarval <macarval@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 18:27:01 by macarval          #+#    #+#             */
/*   Updated: 2023/11/24 08:32:50 by macarval         ###   ########.fr       */
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

# define TAKEN 1
# define EAT 2
# define SLEEP 3
# define THINK 4
# define DIED 5

typedef struct s_watch
{
	pthread_mutex_t	mutex;
	int				philo_died;
}	t_watch;

// typedef struct s_fork
// {
// 	int				id;
// 	int				philo_right; // ?
// 	int				philo_left; // ?
// 	int				avaliable;

// }	t_fork;

typedef struct s_philo
{
	int				id;
	int				hand_forks;
	int				t_die;
	int				t_eat;
	int				t_sleep;
	struct timeval	start;
	t_watch			*watch;
}	t_philo;

typedef struct s_table
{
	int				n_philos;
	int				n_forks;
	int				t_die;
	int				t_eat;
	int				t_sleep;
	int				n_times;
	t_philo			*philos;
	struct timeval	start;
	t_watch			*watcher;
	pthread_t		*threads;
}	t_table;

// philo.c
void		print_error(void);
int			verify_args(int argc, char *argv[]);

// create.c
void		create_philo(t_table *table);
void		create_table(t_table *table, int argc, char *argv[]);

// life.c
int			eating(float time, t_philo *philo);
int			sleeping(float time, t_philo *philo);
int			thinking(float time, t_philo *philo);
void		action(float time, t_philo *philo, int action);

// threads.c
void		*observer_threads(void *arg);
int			manage_threads(t_table *table);
pthread_t	*create_threads(t_table *table);
int			join_threads(t_table *table);

// time.c
void		*init(void *arg);
float		time_diff(struct timeval *start, struct timeval *end);

// utils.c
int			ft_atoi(const char *str);

#endif
