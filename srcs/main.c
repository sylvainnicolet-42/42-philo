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

static int	start_simulation(t_env *env)
{
	t_philo	*philo;

	philo = malloc(sizeof(t_philo) * env->nb_philo);
	if (!philo)
		return (EXIT_FAILURE);
	init_philo(philo, env);
	display_philo(philo, env);
	return (0);
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
	init_env(argv, &env);
	display_env(&env);
	start_simulation(&env);
	return (EXIT_SUCCESS);
}
