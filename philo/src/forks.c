/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macarval <macarval@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 15:41:50 by macarval          #+#    #+#             */
/*   Updated: 2023/11/30 09:24:33 by macarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	take_forks(t_philo *philo, t_table *table, int r_fork, int l_fork)
{
	// int	control;

	if (!read_mutex(&table->watcher->philo_died, &table->watcher->mutex)
		&& !check_dead(philo, table))
	{
		if (get_fork(table, r_fork, l_fork))
		{
			print_life(philo, MSG_FORK, 0);
			print_life(philo, MSG_FORK, 0);
			return (1);
		}

			// pthread_mutex_lock(&table->forks[l_fork].mutex_fork);
			// pthread_mutex_lock(&table->forks[r_fork].mutex_fork);
			// control = 0;
			// if (table->forks[r_fork].avaliable && table->forks[l_fork].avaliable)
			// {
			// 	table->forks[r_fork].avaliable = 0;
			// 	table->forks[l_fork].avaliable = 0;
			// 	print_life(philo, MSG_FORK, 0);
			// 	print_life(philo, MSG_FORK, 0);
			// 	control = 1;
			// }
			// pthread_mutex_unlock(&table->forks[l_fork].mutex_fork);
			// pthread_mutex_unlock(&table->forks[r_fork].mutex_fork);
			// return (control);


		// if (get_fork(&table->forks[l_fork].avaliable,
		// 		&table->forks[l_fork].mutex_fork))
		// {
		// 	if (get_fork(&table->forks[r_fork].avaliable,
		// 			&table->forks[r_fork].mutex_fork))
		// 	{
		// 		print_life(philo, MSG_FORK, 0);
		// 		print_life(philo, MSG_FORK, 0);
		// 		return (1);
		// 	}
		// 	else
		// 		write_mutex(&table->forks[l_fork].avaliable,
		// 			&table->forks[l_fork].mutex_fork, 1);
		// }
	}
	return (0);
}

void	define_id_forks(t_philo *philo, int *right_fork, int *left_fork)
{
	int	r_fork;
	int	l_fork;

	r_fork = philo->id - 1;
	l_fork = philo->id - 2;
	if (philo->id == 1)
		l_fork = ((t_table *)philo->table)->n_philos - 1;
	if (philo->id % 2 == 0)
	{
		*right_fork = r_fork;
		*left_fork = l_fork;
	}
	else
	{
		*right_fork = l_fork;
		*left_fork = r_fork;
	}
}

int	get_fork(t_table *table, int r_fork, int l_fork)
{
	int	control;

	control = 0;
	pthread_mutex_lock(&table->forks[r_fork].mutex_fork);
	pthread_mutex_lock(&table->forks[l_fork].mutex_fork);
	if (table->forks[r_fork].avaliable && table->forks[l_fork].avaliable)
	{
		table->forks[r_fork].avaliable = 0;
		table->forks[l_fork].avaliable = 0;
		control = 1;
	}
	pthread_mutex_unlock(&table->forks[r_fork].mutex_fork);
	pthread_mutex_unlock(&table->forks[l_fork].mutex_fork);
	return (control);
}

// int	get_fork(int *var, pthread_mutex_t *mutex)
// {
// 	int	control;

// 	control = 0;
// 	pthread_mutex_lock(mutex);
// 	if (*var)
// 	{
// 		*var = 0;
// 		control = 1;
// 	}
// 	pthread_mutex_unlock(mutex);
// 	return (control);
// }

void	return_forks(t_table *table, int r_fork, int l_fork)
{
	write_mutex(&table->forks[r_fork].avaliable,
		&table->forks[r_fork].mutex_fork, 1);
	write_mutex(&table->forks[l_fork].avaliable,
		&table->forks[l_fork].mutex_fork, 1);
}

int	check_dead(t_philo *philo, t_table *table)
{
	if (get_now(&table->start) - philo->last_eat >= table->data->t_die)
	{
		pthread_mutex_lock(&((t_table *)philo->table)->mutex_print);
		write_mutex(&table->watcher->philo_died,
			&table->watcher->mutex, philo->id);
		pthread_mutex_unlock(&((t_table *)philo->table)->mutex_print);
		return (1);
	}
	return (0);
}
