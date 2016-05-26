/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vquesnel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/20 12:15:32 by vquesnel          #+#    #+#             */
/*   Updated: 2016/05/26 11:03:27 by vquesnel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

int		main(int ac, char **av)
{
	int		fd;
	t_env	*env;

	if (ac != 2)
		ft_error("\033[31;1mUsage: ./wolf3d <map>\033[0m");
	if ((fd = open(av[1], O_RDONLY)) < 0)
		ft_error("\033[31;1mError when openning file.\033[0m");
	if (!(env = init_env(fd)))
		ft_error("\033[31;1mMalloc Error.\033[0m");
	close(fd);
	expose(env);
	return (0);
}
