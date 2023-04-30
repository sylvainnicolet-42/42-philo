/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: synicole <synicole@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/30 11:34:52 by synicole          #+#    #+#             */
/*   Updated: 2023/04/30 11:34:53 by synicole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	ft_start_simulation(t_env *env)
{
//	unsigned int	i;
//
//	env->start_time = ft_get_time_in_ms() + (env->nb_philos * 2 * 10);
//	i = 0;
//	while (i < env->nb_philos)
//	{
//		if (pthread_create(&env->philos[i]->thread, NULL,
//						   &philosopher, table->philos[i]) != 0)
//			return (error_failure(STR_ERR_THREAD, NULL, env));
//		i++;
//	}
//	if (env->nb_philos > 1)
//	{
//		if (pthread_create(&env->grim_reaper, NULL,
//						   &grim_reaper, table) != 0)
//			return (error_failure(STR_ERR_THREAD, NULL, table));
//	}
	(void)env;
	return (E_TRUE);
}

void	ft_stop_simulation(t_env *env)
{
	(void)env;
//	unsigned int	i;
//
//	i = 0;
//	while (i < env->nb_philos)
//	{
//		pthread_join(env->philos[i]->thread, NULL);
//		i++;
//	}
//	if (env->nb_philos > 1)
//		pthread_join(env->grim_reaper, NULL);
//	if (DEBUG == E_TRUE && env->must_eat_count != -1)
//		write_outcome(table);
//	destroy_mutexes(table);
//	free_table(table);
}
