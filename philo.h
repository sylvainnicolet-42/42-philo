/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: synicole <synicole@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 19:43:07 by synicole          #+#    #+#             */
/*   Updated: 2023/04/14 19:43:09 by synicole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>

typedef struct s_env
{
	int		nb_philo;
	int		time_to_die;
	int		time_to_eat;
	int		time_to_sleep;
	int		philo_must_eat;
}	t_env;

typedef struct s_philo
{
	int				id;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
	t_env			*env;
}	t_philo;

// ----- ENV ----- //
int		init_env(char **argv, t_env *env);

// ----- PHILOSOPHERS ----- //
int		init_philo(t_philo *philo, t_env *env);

// ----- UTILS ----- //
int		ft_atoi(const char *str);

// ----- DEBUG ----- //
void	display_env(t_env *env);
void	display_philo(t_philo *philo, t_env *env);

#endif