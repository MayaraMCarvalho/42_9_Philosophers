/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macarval <macarval@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 18:23:28 by macarval          #+#    #+#             */
/*   Updated: 2023/11/27 00:50:31 by macarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char *argv[])
{
	int		control;
	t_table	table;

	if (verify_args(argc, argv))
		return (1);
	create_table(&table, argc, argv);
	if (!only_philo(&table))
	{
		control = manage_threads(&table);
		if (control != 0)
			printf("Thread error: %i\n", control);
	}
	free_table(&table);
	return (0);
}

int	verify_args(int argc, char *argv[])
{
	int	i;

	if (argc != 5 && argc != 6)
	{
		if (argc < 5)
			write(STDERR_FILENO, "Less arguments than expected\n\0", 31);
		if (argc > 6)
			write(STDERR_FILENO, "More arguments than expected\n\0", 31);
		printf("\nUsage: ./philo [number_of_philosophers] [time_to_die]");
		printf(" [time_to_eat time_to_sleep] ");
		printf("[number_of_times_each_philosopher_must_eat (Optional)]\n\n");
		return (1);
	}
	i = 0;
	while (argv[++i])
	{
		if (is_digit(argv[i]))
		{
			printf("'%s' is a invalid argument. Use only numbers!!\n", argv[i]);
			return (2);
		}
	}
	return (0);
}

int	only_philo(t_table	*table)
{
	struct timeval	end;

	if (table->n_philos < 2)
	{
		gettimeofday(&end, NULL);
		printf("%li 1 has a taken a fork\n", time_diff(&table->start, &end));
		usleep(table->data->t_die * 1000);
		gettimeofday(&end, NULL);
		printf("%li 1 died\n", time_diff(&table->start, &end));
		return (1);
	}
	return (0);
}

void	free_table(t_table *table)
{
	int	i;

	i = -1;
	while (++i < table->n_philos)
		pthread_mutex_destroy(&table->forks[i].mutex_fork);
	pthread_mutex_destroy(&table->mutex_print);
	pthread_mutex_destroy(&table->watcher->mutex);
	free(table->data);
	free(table->philos);
	free(table->forks);
	free(table->watcher);
}
