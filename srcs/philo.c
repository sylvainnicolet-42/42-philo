/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: synicole <synicole@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 19:44:48 by synicole          #+#    #+#             */
/*   Updated: 2023/04/14 19:44:50 by synicole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	start_meal(char **argv)
{
	t_env	*env;

	env = init_env(argv);
	if (!env || !valid_env(env))
		return (-1);
	display_env(env);
	return (0);
}

int	main(int argc, char **argv)
{
	(void)argv;
	if (argc < 5 || argc > 6)
	{
		printf(
			"./philo [number_of_philosophers] [time_to_die] [time_to_eat] "
			"[time_to_sleep] *[number_of_times_each_philosopher_must_eat]\n");
		return (-1);
	}
	if (start_meal(argv) == -1)
	{
		printf("Error: Arguments invalid\n");
		return (-1);
	}
	return (0);
}
