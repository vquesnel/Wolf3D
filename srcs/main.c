/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vquesnel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/20 12:15:32 by vquesnel          #+#    #+#             */
/*   Updated: 2016/05/23 15:35:27 by vquesnel         ###   ########.fr       */
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
		ft_error("Usage: ./wolf3d <map>");
	if ((fd = open(av[1], O_RDONLY)) < 0)
		ft_error("\033[31;1mError when openning file.\033[0m");
	env = init_env(fd);
	ray_cast(env);
	mlx_put_image_to_window(env->mlx,env->win, env->img->img, 0, 0);
	mlx_loop(env->mlx);
	return (0);
}
