/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macarval <macarval@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 14:44:26 by macarval          #+#    #+#             */
/*   Updated: 2023/11/03 14:45:04 by macarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	ft_atoi(const char *str)
{
	int	i;
	int	r;
	int	s;

	i = 0;
	r = 0;
	s = 0;
	if (str[0] == '\0')
		return (0);
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == 43 || str[i] == 45)
	{
		s = i;
		i++;
	}
	while (str[i] && str[i] >= 48 && str[i] <= 57)
	{
		r = (r * 10) + str[i] - 48;
		i++;
	}
	if (str[s] == 45)
		r = -r;
	return (r);
}

