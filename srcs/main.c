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

int	main(int argc, char **argv)
{
	t_env	*env;

	env = NULL;
	if (argc < 5 || argc > 6)
		return (ft_msg(MSG_USAGE, NULL, EXIT_FAILURE));
	if (!ft_is_valid_input(argc, argv))
		return (EXIT_FAILURE);
	env = ft_init_env(argc, argv);
	if (!env)
		return (EXIT_FAILURE);
	printf("Simulation initialized.\n");
	if (!ft_start_simulation(env))
		return (EXIT_FAILURE);
	ft_stop_simulation(env);
	return (EXIT_SUCCESS);
}
