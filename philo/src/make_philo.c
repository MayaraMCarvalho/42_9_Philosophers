/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_philo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macarval <macarval@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 15:37:31 by macarval          #+#    #+#             */
/*   Updated: 2023/11/09 16:27:41 by macarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	make_philo(t_table *table)
{
	int		i;
	
	table->philos = (t_philo *) malloc (table->n_philos * sizeof (t_philo));
	if (!table->philos)
		return ;
	i = -1;
	while (++i < table->n_philos)
	{
		table->philos[i].id = i + 1;
		table->philos[i].hand_forks = 0;
		table->philos[i].t_die = table->t_die;
		table->philos[i].t_eat = table->t_eat;
		table->philos[i].t_sleep = table->t_sleep;
	}
}
