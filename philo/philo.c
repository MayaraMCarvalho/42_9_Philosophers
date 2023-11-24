/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macarval <macarval@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 18:23:28 by macarval          #+#    #+#             */
/*   Updated: 2023/11/24 08:38:13 by macarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char *argv[])
{
	int				control;
	t_table			table;

	if (verify_args(argc, argv))
		return (1);
	create_table(&table, argc, argv);
	control = manage_threads(&table);
	if (control != 0)
		printf("Thread error: %i\n", control);
	free(table.philos);
	free(table.watcher);
	return (0);
}

int	verify_args(int argc, char *argv[])
{
	if (argc < 5 && argc > 6 && argv)
	{
		print_error();
			return (1);
	}
	return (0);
}
void	print_error(void)
{
	printf("Number of arguments invalid!!!\n");
	printf("\nUsage: ./philo [number_of_philosophers] [time_to_die]");
	printf(" [time_to_eat time_to_sleep] ");
	printf("[number_of_times_each_philosopher_must_eat (Optional)]\n\n");
}
