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

t_env	*init_env(char **argv)
{
	t_env	*env;

	env = malloc(sizeof(t_env));
	if (!env)
		return (0);
	env->nb_philo = ft_atoi(argv[1]);
	env->time_to_die = ft_atoi(argv[2]);
	env->time_to_eat = ft_atoi(argv[3]);
	env->time_to_sleep = ft_atoi(argv[4]);
	if (argv[5])
		env->philo_must_eat = ft_atoi(argv[5]);
	return (env);
}

int	valid_env(t_env *env)
{
	if (env->nb_philo < 2 || env->nb_philo > 200)
		return (0);
	if (env->time_to_die < 0)
		return (0);
	if (env->time_to_eat < 0)
		return (0);
	if (env->time_to_sleep < 0)
		return (0);
	if (env->philo_must_eat < 0)
		return (0);
	return (1);
}