/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macarval <macarval@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 09:16:10 by macarval          #+#    #+#             */
/*   Updated: 2023/11/24 19:03:43 by macarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

long int	time_diff(struct timeval *start, struct timeval *end)
{
	long int	time;

	time = (end->tv_sec - start->tv_sec) * 1e+3;
	time += (end->tv_usec - start->tv_usec) / 1e+3;
	return (time);
}

void	*init(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *) arg;
	action(philo);
	return (NULL);
}
