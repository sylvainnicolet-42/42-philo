/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: synicole <synicole@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 19:44:48 by synicole          #+#    #+#             */
/*   Updated: 2023/04/14 19:44:50 by synicole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	*ft_philo_life(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *) arg;
	ft_eating(philo);
	ft_sleeping(philo);
	ft_thinking(philo);
	return (NULL);
}

int	ft_init_philos(t_philo *philo, t_env *env)
{
	int	i;

	i = 0;
	while (i < env->nb_philo)
	{
		philo[i].id = i + 1;
		philo[i].nb_meal_eaten = 0;
		philo[i].is_dead = FALSE;
		philo[i].env = env;
		i++;
	}
	return (0);
}
