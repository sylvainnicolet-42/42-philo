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

typedef struct s_env
{
	int	nb_philo;
	int	time_to_die;
	int	time_to_eat;
	int	time_to_sleep;
	int	philo_must_eat;
}	t_env;

// ----- ENV ----- //
t_env	*init_env(char **argv);
int		valid_env(t_env *env);

// ----- UTILS ----- //
int		ft_atoi(const char *str);

// ----- DEBUG ----- //
void	display_env(t_env *env);

#endif