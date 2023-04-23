/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: synicole <synicole@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 20:55:51 by synicole          #+#    #+#             */
/*   Updated: 2023/04/23 20:55:54 by synicole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

static void	ft_end_simulation(t_philo *philo, t_env *env)
{
	int	i;

	i = 0;
	while (i < env->nb_philo)
	{
		pthread_join(philo[i].thread, NULL);
		i++;
	}
	pthread_mutex_destroy(env->fork);
	free(env->fork);
	free(philo);
}

static void	ft_check_simulation(t_philo *philo, t_env *env)
{
	int			i;
	long int	now;

	while (env->is_ready == FALSE)
		continue ;
	while (env->is_over == FALSE)
	{
		i = 0;
		while (i < env->nb_philo)
		{
			printf("%d\n", env->time_to_die);
			printf("%ld\n", ft_now() - philo[i].last_meal_time);
			now = ft_now() - philo[i].last_meal_time;
			if (now >= env->time_to_die)
			{
				ft_die(&philo[i]);
				env->is_over = TRUE;
			}
			i++;
		}
	}
}

int	ft_start_simulation(t_env *env)
{
	t_philo	*philo;
	int		i;

	philo = malloc(sizeof(t_philo) * env->nb_philo);
	if (!philo)
		return (EXIT_FAILURE);
	ft_init_philos(philo, env);
	ft_init_threads(philo, env);
	env->start_time = ft_now();
	i = 0;
	while (i < env->nb_philo)
	{
		philo[i].thread_start_time = env->start_time;
		i++;
	}
	env->is_ready = TRUE;
	ft_check_simulation(philo, env);
	ft_end_simulation(philo, env);
	return (EXIT_SUCCESS);
}
