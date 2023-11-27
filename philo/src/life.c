/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   life.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macarval <macarval@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 11:53:42 by macarval          #+#    #+#             */
/*   Updated: 2023/11/27 01:00:33 by macarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	action(t_philo *philo)
{
	t_table			*table;

	table = philo->table;
	while (!read_mutex(&table->watcher->philo_died, &table->watcher->mutex)
		&& philo->n_times_eat != 0)
	{
		if (philo->id % 2 == 0)
			usleep(1500);
		eating(philo, table);
		sleeping(philo, table);
		if (!read_mutex(&table->watcher->philo_died, &table->watcher->mutex))
		{
			print_life(philo, "is thinking", 0);
			usleep(1000);
		}
		check_dead(philo, table);
	}
}

void	eating(t_philo *philo, t_table *table)
{
	int				right_fork;
	int				left_fork;

	right_fork = philo->id - 1;
	left_fork = philo->id - 2;
	if (philo->id == 1)
		left_fork = table->n_philos - 1;
	if (!check_dead(philo, table)
		&& !read_mutex(&table->watcher->philo_died, &table->watcher->mutex)
		&& take_forks(philo, table, right_fork, left_fork))
	{
		print_life(philo, "is eating", 1);
		if (philo->n_times_eat > 0)
			philo->n_times_eat--;
		usleep(table->data->t_eat * 1000);
		return_forks(table, right_fork, left_fork);
	}
	check_dead(philo, table);
}

void	sleeping(t_philo *philo, t_table *table)
{
	if (!read_mutex(&table->watcher->philo_died, &table->watcher->mutex))
	{
		print_life(philo, "is sleeping", 0);
		usleep(table->data->t_sleep * 1000);
	}
	check_dead(philo, table);
}

void	print_life(t_philo *philo, char	*msg, int is_eat)
{
	struct timeval	end;
	long int		time;

	gettimeofday(&end, NULL);
	time = time_diff(&((t_table *)philo->table)->start, &end);
	pthread_mutex_lock(&((t_table *)philo->table)->mutex_print);
	printf("%li %i %s\n", time, philo->id, msg);
	pthread_mutex_unlock(&((t_table *)philo->table)->mutex_print);
	if (is_eat)
		philo->last_eat = time;
}
