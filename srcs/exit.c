/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: synicole <synicole@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/30 11:26:45 by synicole          #+#    #+#             */
/*   Updated: 2023/04/30 11:26:47 by synicole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	ft_free_env(t_env *env)
{
	unsigned int	i;

	if (!env)
		return ;
	if (env->philosophers != NULL)
	{
		i = 0;
		while (i < env->nb_philos)
		{
			if (env->philosophers[i] != NULL)
				free(env->philosophers[i]);
			i++;
		}
		free(env->philosophers);
	}
	free(env);
}

/**
 * Print a message with or without a detail, and return an exit code.
 * @param str The string to print.
 * @param detail An optional detail to print after the string.
 * @param exit_n The integer value to return from the function.
 *
 * @return The integer exit code provided by the exit_n parameter.
*/
int	ft_msg(char *str, char *detail, int exit_n)
{
	if (!detail)
		printf("%s", str);
	else
		printf(str, detail);
	return (exit_n);
}

void	*ft_error(char *str)
{
	printf("%s", str);
	return (NULL);
}
