/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macarval <macarval@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 18:27:01 by macarval          #+#    #+#             */
/*   Updated: 2023/11/09 18:40:24 by macarval         ###   ########.fr       */
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

typedef struct s_fork
{
	int				id;
	int				philo_right; // ?
	int				philo_left; // ?
	int				avaliable;

}	t_fork;

typedef struct s_philo
{
	int				id;
	int				hand_forks;
	int				t_die;
	int				t_eat;
	int				t_sleep;
	struct timeval	start;

}	t_philo;

typedef struct s_table
{
	int				n_philos;
	int				n_forks;
	int				t_die;
	int				t_eat;
	int				t_sleep;
	int				n_times;
	t_fork 			*forks;
	t_philo			*philos;
	struct timeval	start;
}	t_table;

// philo.c
void		*observer(void *args);
int			create_thread(t_table *table);
void		create_table(t_table *table, int argc, char *argv[]);

// life.c
int			action(float time, int philo, int action);

// make_philo.c
void		make_philo(t_table *table);
void		free_philos(t_philo *list);
void		insert_last(t_philo **lst, t_philo *new);
t_philo		*insert_front(t_philo *new, int id, t_table *table);


// time.c
void		*init_timer(void* arg);
float		time_diff(struct timeval *start, struct timeval *end);

// utils.c
int			ft_atoi(const char *str);

#endif
