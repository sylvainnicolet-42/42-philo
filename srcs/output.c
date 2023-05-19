/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: synicole <synicole@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 12:42:56 by synicole          #+#    #+#             */
/*   Updated: 2023/05/19 12:42:57 by synicole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

static void	ft_print_status_debug(t_philo *philo, char *str, t_status status)
{
	if (status == E_GOT_FORK_1)
		printf("[%10ld]\t%03d\t%s: fork [%d]\n",
			ft_get_time_in_ms() - philo->env->start_time,
			philo->id + 1, str, philo->fork[0]);
	else if (status == E_GOT_FORK_2)
		printf("[%10ld]\t%03d\t%s: fork [%d]\n",
			ft_get_time_in_ms() - philo->env->start_time,
			philo->id + 1, str, philo->fork[1]);
	else
		printf("[%10ld]\t%03d\t%s\n",
			ft_get_time_in_ms() - philo->env->start_time, philo->id + 1, str);
}

static void	ft_write_status_debug(t_philo *philo, t_status status)
{
	if (status == E_DIED)
		ft_print_status_debug(philo, "died", status);
	else if (status == E_EATING)
		ft_print_status_debug(philo, "is eating", status);
	else if (status == E_SLEEPING)
		ft_print_status_debug(philo, "is sleeping", status);
	else if (status == E_THINKING)
		ft_print_status_debug(philo, "is thinking", status);
	else if (status == E_GOT_FORK_1 || status == E_GOT_FORK_2)
		ft_print_status_debug(philo, "has taken a fork", status);
}

static void	ft_print_status(t_philo *philo, char *str)
{
	printf("%ld %d %s\n", ft_get_time_in_ms() - philo->env->start_time,
		philo->id + 1, str);
}

void	ft_write_outcome(t_env *env)
{
	unsigned int	i;
	unsigned int	full_count;

	full_count = 0;
	i = 0;
	while (i < env->nb_philos)
	{
		if (env->philosophers[i]->nb_meal_eaten
			>= (unsigned int)env->must_eat_count)
			full_count++;
		i++;
	}
	pthread_mutex_lock(&env->write_lock);
	printf("%d/%d philosophers had at least %d meals.\n",
		full_count, env->nb_philos, env->must_eat_count);
	pthread_mutex_unlock(&env->write_lock);
}

void	ft_write_status(t_philo *philo, int monitoring_report, t_status status)
{
	pthread_mutex_lock(&philo->env->write_lock);
	if (ft_is_simulation_over(philo->env) == 1 && monitoring_report == 0)
	{
		pthread_mutex_unlock(&philo->env->write_lock);
		return ;
	}
	if (DEBUG == 1)
	{
		ft_write_status_debug(philo, status);
		pthread_mutex_unlock(&philo->env->write_lock);
		return ;
	}
	if (status == E_DIED)
		ft_print_status(philo, "died");
	else if (status == E_EATING)
		ft_print_status(philo, "is eating");
	else if (status == E_SLEEPING)
		ft_print_status(philo, "is sleeping");
	else if (status == E_THINKING)
		ft_print_status(philo, "is thinking");
	else if (status == E_GOT_FORK_1 || status == E_GOT_FORK_2)
		ft_print_status(philo, "has taken a fork");
	pthread_mutex_unlock(&philo->env->write_lock);
}
