/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macarval <macarval@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 18:23:28 by macarval          #+#    #+#             */
/*   Updated: 2023/11/19 19:14:51 by macarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char *argv[])
{
	int				i;
	int				control;
	t_table			table;

	if (argc == 5 || argc == 6)
	{
		create_table(&table, argc, argv);
		i = table.n_times;
		gettimeofday(&table.start, NULL);
		while (i != 0)
		{
			control = create_thread(&table);
			if (control != 0)
			{
				printf("Thread error: %i\n", control);
				return (1);
			}
			if (table.n_times > 0)
				i--;
		}
		free(table.philos);
	}
	else
	{
		printf("Number of arguments invalid!!!\n");
		printf("\nUsage: ./philo [number_of_philosophers] [time_to_die]");
		printf(" [time_to_eat time_to_sleep] ");
		printf("[number_of_times_each_philosopher_must_eat (Optional)]\n\n");
	}
	return (0);
}

void	create_table(t_table *table, int argc, char *argv[])
{
	table->n_philos = ft_atoi(argv[1]);
	table->n_forks = table->n_philos;
	table->t_die = ft_atoi(argv[2]);
	table->t_eat = ft_atoi(argv[3]);
	table->t_sleep = ft_atoi(argv[4]);
	table->n_times = -1;
	if (argc == 6)
		table->n_times = ft_atoi(argv[5]);
	make_philo(table);
}

int	create_thread(t_table *table)
{
	int				i;
	pthread_t		threads[table->n_philos];
	pthread_t		watcher;

	if (pthread_create(&watcher, NULL, &observer, (void *)threads) != 0)
			return (1);
	i = -1;
	while (++i < table->n_philos)
	{
		table->philos[i].start = table->start;
		if (pthread_create(&threads[i], NULL, &init_timer, &table->philos[i]) != 0)
			return (i);
	}
	i = -1;
	while (++i < table->n_philos)
	{
		if (pthread_join(threads[i], NULL) != 0)
			return (i);
	}
	return (0);
}

void	*observer(void *args)
{
	pthread_t	*threads;
	// int			result;
	int			i;

	threads = (pthread_t *)args;
	while (1)
	{
		i = -1;
		while(++i <= 3 && threads)
		{
			// pthread_kill(threads[i], 0);
			// if (result == 0)
			// 	printf("Thread %i is still running\n", i);
			// else if (result == -1)
			// 	printf("Thread %i has finished\n", i);
			// else
			// 	perror("pthread_kill");
		}
	}
	sleep(2);
}
