/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: synicole <synicole@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 20:40:35 by synicole          #+#    #+#             */
/*   Updated: 2023/04/20 20:40:37 by synicole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	ft_init_threads(t_philo *philo, t_env *env)
{
	int	i;

	i = 0;
	while (i < env->nb_philo)
	{
		philo[i].right_fork = philo[(i + 1) % env->nb_philo].left_fork;
		pthread_create(&philo[i].thread, NULL, &ft_philo_life, &philo[i]);
		i++;
	}
	return (0);
}

void	ft_end_threads(t_philo *philo, t_env *env)
{
	int	i;

	i = 0;
	while (i < env->nb_philo)
	{
		pthread_join(philo[i].thread, NULL);
		i++;
	}
}
