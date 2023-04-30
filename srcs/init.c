/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: synicole <synicole@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/30 15:13:22 by synicole          #+#    #+#             */
/*   Updated: 2023/04/30 15:13:23 by synicole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

static void	assign_forks(t_philo *philo)
{
	philo->fork[0] = philo->id;
	philo->fork[1] = (philo->id + 1) % philo->env->nb_philos;
	if (philo->id % 2)
	{
		philo->fork[0] = (philo->id + 1) % philo->env->nb_philos;
		philo->fork[1] = philo->id;
	}
}

static t_philo	**ft_init_philosophers(t_env *env)
{
	t_philo			**philos;
	unsigned int	i;

	philos = malloc(sizeof(t_philo) * env->nb_philos);
	if (!philos)
		return (ft_error(MSG_ERR_MALLOC));
	i = 0;
	while (i < env->nb_philos)
	{
		philos[i] = malloc(sizeof(t_philo) * 1);
		if (!philos[i])
			return (ft_error(MSG_ERR_MALLOC));
		if (pthread_mutex_init(&philos[i]->meal_time_lock, 0) != 0)
			return (ft_error(MSG_ERR_MUTEX));
		philos[i]->env = env;
		philos[i]->id = i;
		philos[i]->nb_meal_eaten = 0;
		assign_forks(philos[i]);
		i++;
	}
	return (philos);
}

t_env	*ft_init_env(int argc, char **argv)
{
	t_env	*env;
	int		i;

	env = malloc(sizeof(t_env));
	if (!env)
		return (ft_error(MSG_ERR_MALLOC));
	i = 1;
	env->nb_philos = ft_integer_atoi(argv[i++]);
	env->time_to_die = ft_integer_atoi(argv[i++]);
	env->time_to_eat = ft_integer_atoi(argv[i++]);
	env->time_to_sleep = ft_integer_atoi(argv[i++]);
	env->must_eat_count = -1;
	if (!env->philosophers)
		return (NULL);
	if (argc == 6)
		env->must_eat_count = ft_integer_atoi(argv[i]);
	env->philosophers = ft_init_philosophers(env);
	env->is_over = E_FALSE;
	return (env);
}
