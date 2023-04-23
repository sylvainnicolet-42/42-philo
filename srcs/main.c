/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: synicole <synicole@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 16:39:52 by synicole          #+#    #+#             */
/*   Updated: 2023/04/20 16:39:54 by synicole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

static int	ft_start_simulation(t_env *env)
{
	t_philo	*philo;

	philo = malloc(sizeof(t_philo) * env->nb_philo);
	if (!philo)
		return (EXIT_FAILURE);
	ft_init_philos(philo, env);
	ft_display_philos(philo, env);
	ft_init_threads(philo, env);
	env->start_time = ft_now();
	env->is_ready = TRUE;
	ft_end_threads(philo, env);
	return (EXIT_SUCCESS);
}

int	main(int argc, char **argv)
{
	t_env	env;

	if (argc < 5 || argc > 6)
	{
		printf(
			"./philo [number_of_philosophers] [time_to_die] [time_to_eat] "
			"[time_to_sleep] *[number_of_times_each_philosopher_must_eat]\n");
		return (EXIT_FAILURE);
	}
	ft_init_env(argv, &env);
	if (DEBUG == TRUE)
		ft_display_env(&env);
	ft_start_simulation(&env);
	return (EXIT_SUCCESS);
}
