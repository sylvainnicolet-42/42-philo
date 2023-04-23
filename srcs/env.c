/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: synicole <synicole@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 21:08:00 by synicole          #+#    #+#             */
/*   Updated: 2023/04/14 21:08:02 by synicole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	ft_init_env(char **argv, t_env *env)
{
	int	i;

	env->nb_philo = ft_atoi(argv[1]);
	env->time_to_die = ft_atoi(argv[2]);
	env->time_to_eat = ft_atoi(argv[3]);
	env->time_to_sleep = ft_atoi(argv[4]);
	env->is_ready = FALSE;
	env->is_over = FALSE;
	env->meal_must_be_checked = FALSE;
	if (argv[5])
	{
		env->meal_must_be_checked = TRUE;
		env->philo_must_eat = ft_atoi(argv[5]);
	}
	env->fork = malloc(sizeof(pthread_mutex_t) * env->nb_philo);
	i = 0;
	while (i < env->nb_philo)
	{
		(pthread_mutex_init(&env->fork[i], NULL));
		i++;
	}
	return (0);
}
