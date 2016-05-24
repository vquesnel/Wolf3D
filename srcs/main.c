/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vquesnel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/20 12:15:32 by vquesnel          #+#    #+#             */
/*   Updated: 2016/05/24 21:27:43 by vquesnel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

int		main(int ac, char **av)
{
	int		fd;
	t_env	*env;
	int		x;
	int		y;

	if (ac != 2)
		ft_error("\033[31;1mUsage: ./wolf3d <map>\033[0m");
	if ((fd = open(av[1], O_RDONLY)) < 0)
		ft_error("\033[31;1mError when openning file.\033[0m");
	env = init_env(fd);
	expose(env);
	return (0);
}
